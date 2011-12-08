/*
 * jutils.c
 *
 * Copyright (C) 1991-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains tables and miscellaneous utility routines needed
 * for both compression and decompression.
 * Note we prefix all global names with "j" to minimize conflicts with
 * a surrounding application.
 */

#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "./jpeg_global.h" //bmy 04.12.21 jpeg_enc_opt +

/*
 * jpeg_zigzag_order[i] is the zigzag-order position of the i'th element
 * of a DCT block read in natural order (left to right, top to bottom).
 */



/*
 * jpeg_natural_order[i] is the natural-order position of the i'th element
 * of zigzag order.
 *
 * When reading corrupted data, the Huffman decoders could attempt
 * to reference an entry beyond the end of this array (if the decoded
 * zero run length reaches past the end of the block).  To prevent
 * wild stores without adding an inner-loop test, we put some extra
 * "63"s after the real entries.  This will cause the extra coefficient
 * to be stored in location 63 of the block, not somewhere random.
 * The worst case would be a run-length of 15, which means we need 16
 * fake entries.
 */
// DHKIM
// From int
// To char
const char jpeg_natural_order[DCTSIZE2 + 16] = 
{
  0, 1, 8, 16, 9, 2, 3, 10, 17, 24, 32, 25, 18, 11, 4, 5, 12, 19, 26, 33, 40,
    48, 41, 34, 27, 20, 13, 6, 7, 14, 21, 28, 35, 42, 49, 56, 57, 50, 43, 36,
    29, 22, 15, 23, 30, 37, 44, 51, 58, 59, 52, 45, 38, 31, 39, 46, 53, 60, 61,
    54, 47, 55, 62, 63, 63, 63, 63, 63, 63, 63, 63, 63,  /* extra entries for
    safety in decoder */
  63, 63, 63, 63, 63, 63, 63, 63
};


#ifndef JPEG_ENC_OPT  //bmy 04.12.21 jpeg_enc_opt + : below
  /*
   * Arithmetic utilities
   */

  GLOBAL(long)jdiv_round_up(long a, long b)
  /* Compute a/b rounded up to next integer, ie, ceil(a/b) */
  /* Assumes a >= 0, b > 0 */
  {
    return (a + b - 1L) / b;
  }


  GLOBAL(long)jround_up(long a, long b)
  /* Compute a rounded up to next multiple of b, ie, ceil(a/b)*b */
  /* Assumes a >= 0, b > 0 */
  {
    a += b - 1L;
    return a - (a % b);
  }


  /* On normal machines we can apply MEMCOPY() and MEMZERO() to sample arrays
   * and coefficient-block arrays.  This won't work on 80x86 because the arrays
   * are FAR and we're assuming a small-pointer memory model.  However, some
   * DOS compilers provide far-pointer versions of memcpy() and memset() even
   * in the small-model libraries.  These will be used if USE_FMEM is defined.
   * Otherwise, the routines below do it the hard way.  (The performance cost
   * is not all that great, because these routines aren't very heavily used.)
   */

  // DHKIM
  // For test
  //#ifndef NEED_FAR_POINTERS	/* normal case, same as regular macros */
  //#define FMEMCOPY(dest,src,size)	MEMCOPY(dest,src,size)
  //#define FMEMZERO(target,size)	MEMZERO(target,size)
  //#else				/* 80x86 case, define if we can */
  //#ifdef USE_FMEM
  //#define FMEMCOPY(dest,src,size)	_fmemcpy((void FAR *)(dest), (const void FAR *)(src), (unsigned int)(size))
  //#define FMEMZERO(target,size)	_fmemset((void FAR *)(target), 0, (unsigned int)(size))
  //#endif
  //#endif


  GLOBAL(void)jcopy_sample_rows(JSAMPARRAY input_array, int source_row,
    JSAMPARRAY output_array, int dest_row, int num_rows, JDIMENSION num_cols)
  /* Copy some rows of samples from one place to another.
   * num_rows rows are copied from input_array[source_row++]
   * to output_array[dest_row++]; these areas may overlap for duplication.
   * The source and destination arrays must be at least as wide as num_cols.
   */
  {
    register JSAMPROW inptr, outptr;
    #ifdef FMEMCOPY
      register unsigned int count = (unsigned int)(num_cols *SIZEOF(JSAMPLE));
    #else 
      register JDIMENSION count;
    #endif 
    register int row;

    input_array += source_row;
    output_array += dest_row;

    for (row = num_rows; row > 0; row--)
    {
      inptr =  *input_array++;
      outptr =  *output_array++;
      #ifdef FMEMCOPY
        FMEMCOPY(outptr, inptr, count);
      #else 
        for (count = num_cols; count > 0; count--)
          *outptr++ =  *inptr++;
         /* needn't bother with GETJSAMPLE() here */
      #endif 
    }
  }



GLOBAL(void)jzero_far(void FAR *target, unsigned int bytestozero)
/* Zero out a chunk of FAR memory. */
/* This might be sample-array data, block-array data, or alloc_large data. */
{
  #ifdef FMEMZERO
    FMEMZERO(target, bytestozero);
  #else 
    register char FAR *ptr = (char FAR*)target;
    register unsigned int count;

    for (count = bytestozero; count > 0; count--)
    {
      *ptr++ = 0;
    }
  #endif 
}
#endif //bmy 04.12.21 jpeg_enc_opt + : up