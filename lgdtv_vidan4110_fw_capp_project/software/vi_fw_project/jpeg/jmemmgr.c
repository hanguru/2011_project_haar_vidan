/*
 * jmemmgr.c
 *
 * Copyright (C) 1991-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains the JPEG system-independent memory management
 * routines.  This code is usable across a wide variety of machines; most
 * of the system dependencies have been isolated in a separate file.
 * The major functions provided here are:
 *   * pool-based allocation and freeing of memory;
 *   * policy decisions about how to divide available memory among the
 *     virtual arrays;
 *   * control logic for swapping virtual arrays between main memory and
 *     backing storage.
 * The separate system-dependent file provides the actual backing-storage
 * access code, and it contains the policy decision about how much total
 * main memory to use.
 * This file is system-dependent in the sense that some of its functions
 * are unnecessary in some systems.  For example, if there is enough virtual
 * memory so that backing storage will never be used, much of the virtual
 * array control logic could be removed.  (Of course, if you have that much
 * memory then you shouldn't care about a little bit of unused code...)
 */

#define JPEG_INTERNALS
#define AM_MEMORY_MANAGER	/* we define jvirt_Xarray_control structs */
#include "jinclude.h"
#include "jpeglib.h"
#include "jmemsys.h"		/* import the system-dependent declarations */

#ifndef NO_GETENV
  #ifndef HAVE_STDLIB_H		/* <stdlib.h> should declare getenv() */
    extern char *getenv JPP((const char *name));
  #endif 
#endif 

#include "./jpeg_global.h" //bmy 04.12.21 jpeg_enc_opt +
/*
 * Some important notes:
 *   The allocation routines provided here must never return NULL.
 *   They should exit to error_exit if unsuccessful.
 *
 *   It's not a good idea to try to merge the sarray and barray routines,
 *   even though they are textually almost the same, because samples are
 *   usually stored as bytes while coefficients are shorts or ints.  Thus,
 *   in machines where byte pointers have a different representation from
 *   word pointers, the resulting machine code could not be the same.
 */


/*
 * Many machines require storage alignment: longs must start on 4-byte
 * boundaries, doubles on 8-byte boundaries, etc.  On such machines, malloc()
 * always returns pointers that are multiples of the worst-case alignment
 * requirement, and we had better do so too.
 * There isn't any really portable way to determine the worst-case alignment
 * requirement.  This module assumes that the alignment requirement is
 * multiples of sizeof(ALIGN_TYPE).
 * By default, we define ALIGN_TYPE as double.  This is necessary on some
 * workstations (where doubles really do need 8-byte alignment) and will work
 * fine on nearly everything.  If your machine has lesser alignment needs,
 * you can save a few bytes by making ALIGN_TYPE smaller.
 * The only place I know of where this will NOT work is certain Macintosh
 * 680x0 compilers that define double as a 10-byte IEEE extended float.
 * Doing 10-byte alignment is counterproductive because longwords won't be
 * aligned well.  Put "#define ALIGN_TYPE long" in jconfig.h if you have
 * such a compiler.
 */




/*
 * We allocate objects from "pools", where each pool is gotten with a single
 * request to jpeg_get_small() or jpeg_get_large().  There is no per-object
 * overhead within a pool, except for alignment padding.  Each pool has a
 * header with a link to the next pool of the same class.
 * Small and large pool headers are identical except that the latter's
 * link pointer must be FAR on 80x86 machines.
 * Notice that the "real" header fields are union'ed with a dummy ALIGN_TYPE
 * field.  This forces the compiler to make SIZEOF(small_pool_hdr) a multiple
 * of the alignment requirement of ALIGN_TYPE.
 */




struct jvirt_sarray_control
{
  JSAMPARRAY mem_buffer; /* => the in-memory buffer */
  JDIMENSION rows_in_array; /* total virtual array height */
  JDIMENSION samplesperrow; /* width of array (and of memory buffer) */
  JDIMENSION maxaccess; /* max rows accessed by access_virt_sarray */
  JDIMENSION rows_in_mem; /* height of memory buffer */
  JDIMENSION rowsperchunk; /* allocation chunk size in mem_buffer */
  JDIMENSION cur_start_row; /* first logical row # in the buffer */
  JDIMENSION first_undef_row; /* row # of first uninitialized row */
  boolean pre_zero; /* pre-zero mode requested? */
  boolean dirty; /* do current buffer contents need written? */
  boolean b_s_open; /* is backing-store data valid? */
  jvirt_sarray_ptr next; /* link to next virtual sarray control block */
  backing_store_info b_s_info; /* System-dependent control info */
};

struct jvirt_barray_control
{
  JBLOCKARRAY mem_buffer; /* => the in-memory buffer */
  JDIMENSION rows_in_array; /* total virtual array height */
  JDIMENSION blocksperrow; /* width of array (and of memory buffer) */
  JDIMENSION maxaccess; /* max rows accessed by access_virt_barray */
  JDIMENSION rows_in_mem; /* height of memory buffer */
  JDIMENSION rowsperchunk; /* allocation chunk size in mem_buffer */
  JDIMENSION cur_start_row; /* first logical row # in the buffer */
  JDIMENSION first_undef_row; /* row # of first uninitialized row */
  boolean pre_zero; /* pre-zero mode requested? */
  boolean dirty; /* do current buffer contents need written? */
  boolean b_s_open; /* is backing-store data valid? */
  jvirt_barray_ptr next; /* link to next virtual barray control block */
  backing_store_info b_s_info; /* System-dependent control info */
};




GLOBAL(void*)alloc_small(unsigned int sizeofobject)
/* Allocate a "small" object */
{

  return jpeg_get_small(sizeofobject);


}


/*
 * Allocation of "large" objects.
 *
 * The external semantics of these are the same as "small" objects,
 * except that FAR pointers are used on 80x86.  However the pool
 * management heuristics are quite different.  We assume that each
 * request is large enough that it may as well be passed directly to
 * jpeg_get_large; the pool management just links everything together
 * so that we can free it all on demand.
 * Note: the major use of "large" objects is in JSAMPARRAY and JBLOCKARRAY
 * structures.  The routines that create these structures (see below)
 * deliberately bunch rows together to ensure a large request size.
 */

GLOBAL(void FAR*)alloc_large(unsigned int sizeofobject)
/* Allocate a "large" object */
{
  return jpeg_get_small(sizeofobject);

}

#ifndef JPEG_ENC_OPT  //bmy 04.12.21 jpeg_enc_opt + : below
  /*
   * Creation of 2-D sample arrays.
   * The pointers are in near heap, the samples themselves in FAR heap.
   *
   * To minimize allocation overhead and to allow I/O of large contiguous
   * blocks, we allocate the sample rows in groups of as many rows as possible
   * without exceeding MAX_ALLOC_CHUNK total bytes per allocation request.
   * NB: the virtual array control routines, later in this file, know about
   * this chunking of rows.  The rowsperchunk value is left in the mem manager
   * object so that it can be saved away if this sarray is the workspace for
   * a virtual array.
   */

  GLOBAL(JSAMPARRAY)alloc_sarray(JDIMENSION samplesperrow, JDIMENSION numrows)
  /* Allocate a 2-D sample array */
  {
    //  my_mem_ptr mem = (my_mem_ptr) cinfo->mem;
    JSAMPARRAY result;
    JSAMPROW workspace;
    JDIMENSION rowsperchunk, currow, i;
    long ltemp;

    /* Calculate max # of rows allowed in one allocation chunk */
    // ltemp = (MAX_ALLOC_CHUNK-SIZEOF(large_pool_hdr)) /
    //	  ((long) samplesperrow * SIZEOF(JSAMPLE));
    //  if (ltemp <= 0)
    //    ERREXIT(cinfo, JERR_WIDTH_OVERFLOW);
    if (ltemp < (long)numrows)
      rowsperchunk = (JDIMENSION)ltemp;
    else
      rowsperchunk = numrows;
    //  mem->last_rowsperchunk = rowsperchunk;

    /* Get space for row pointers (small object) */
    result = (JSAMPARRAY)alloc_small((unsigned int)(numrows *SIZEOF(JSAMPROW)));

    /* Get the rows themselves (large objects) */
    currow = 0;
    while (currow < numrows)
    {
      rowsperchunk = MIN(rowsperchunk, numrows - currow);
      workspace = (JSAMPROW)alloc_large((unsigned int)((unsigned int)
        rowsperchunk *(unsigned int)samplesperrow*SIZEOF(JSAMPLE)));
      for (i = rowsperchunk; i > 0; i--)
      {
        result[currow++] = workspace;
        workspace += samplesperrow;
      }
    }

    return result;
  }
#endif //bmy 04.12.21 jpeg_enc_opt + : up
