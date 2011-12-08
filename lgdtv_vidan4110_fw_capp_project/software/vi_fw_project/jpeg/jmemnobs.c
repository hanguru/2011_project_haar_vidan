/*
 * jmemnobs.c
 *
 * Copyright (C) 1992-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file provides a really simple implementation of the system-
 * dependent portion of the JPEG memory manager.  This implementation
 * assumes that no backing-store files are needed: all required space
 * can be obtained from malloc().
 * This is very portable in the sense that it'll compile on almost anything,
 * but you'd better have lots of main memory (or virtual memory) if you want
 * to process big images.
 * Note that the max_memory_to_use option is ignored by this implementation.
 */

#define JPEG_INTERNALS
#include <string.h>
#include "jinclude.h"
#include "jpeglib.h"
#include "jmemsys.h"		/* import the system-dependent declarations */

#ifndef HAVE_STDLIB_H		/* <stdlib.h> should declare malloc(),free() */
  extern void *malloc JPP((unsigned int size));
  extern void free JPP((void *ptr));
#endif 

#include "./jpeg_global.h" //bmy 04.12.21 jpeg_enc_opt +
/*
 * Memory allocation and freeing are controlled by the regular library
 * routines malloc() and free().
 */
int total_alloc_mem = 0;
// for decoder -4813
// for encoder 
GLOBAL(void*)jpeg_get_small(unsigned int sizeofobject)
{
  //if (sizeofobject < 4000)
  //	total_alloc_mem += sizeofobject;
  char *ptr;

  total_alloc_mem += sizeofobject;
  #ifdef SIMULATION_DHKIM	 
    *((volatile int*)(TUBE_FILE_3 + 0x04)) = 0xA1C8C8C9;
    *((volatile int*)(TUBE_FILE_3 + 0x04)) = total_alloc_mem;
  #endif 

  //  return (void *) malloc(sizeofobject);
  ptr = (void*)malloc(sizeofobject);
  memset(ptr, 0, sizeofobject);
  return (void*)ptr;
}

/* JSY-
GLOBAL(void)
jpeg_free_small (unsigned int sizeofobject)
{
free(sizeofobject);
}
 */



#ifndef JPEG_ENC_OPT  //bmy 04.12.21 jpeg_enc_opt + : below
  /*
   * "Large" objects are treated the same as "small" ones.
   * NB: although we include FAR keywords in the routine declarations,
   * this file won't actually work in 80x86 small/medium model; at least,
   * you probably won't be able to process useful-size images in only 64KB.
   */


  GLOBAL(void FAR*)jpeg_get_large(j_common_ptr cinfo, unsigned int sizeofobject)
  {
    char *ptr;

    total_alloc_mem += sizeofobject;
    #ifdef SIMULATION_DHKIM	 
      *((volatile int*)(TUBE_FILE_3 + 0x04)) = 0xA1C8C8C9;
      *((volatile int*)(TUBE_FILE_3 + 0x04)) = total_alloc_mem;
    #endif 

    if (sizeofobject < 4000)
      total_alloc_mem += sizeofobject;
    //    return (void FAR *) malloc(sizeofobject);

    ptr = (char*)malloc(sizeofobject);
    memset(ptr, 0, sizeofobject);
    return (void*)ptr;
  }

  GLOBAL(void)jpeg_free_large(j_common_ptr cinfo, void FAR *object, unsigned
    int sizeofobject)
  {
    free(object);
  }

#endif //bmy 04.12.21 jpeg_enc_opt + : up






/*
 * These routines take care of any system-dependent initialization and
 * cleanup required.  Here, there isn't any.
 */
