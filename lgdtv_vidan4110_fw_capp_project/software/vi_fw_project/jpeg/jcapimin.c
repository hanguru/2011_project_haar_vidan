/*
 * jcapimin.c
 *
 * Copyright (C) 1994-1998, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains application interface code for the compression half
 * of the JPEG library.  These are the "minimum" API routines that may be
 * needed in either the normal full-compression case or the transcoding-only
 * case.
 *
 * Most of the routines intended to be called directly by an application
 * are in this file or in jcapistd.c.  But also see jcparam.c for
 * parameter-setup helper routines, jcomapi.c for routines shared by
 * compression and decompression, and jctrans.c for the transcoding case.
 */

#define JPEG_INTERNALS
#include <string.h>
#include "jinclude.h"
#include "jpeglib.h"
#include "./jpeg_global.h" //bmy 04.12.21 jpeg_enc_opt +

extern GLOBAL(void)finish_pass_master(j_compress_ptr cinfo);
/*
 * Initialization of a JPEG compression object.
 * The error manager must already be set up (in case memory manager fails).
 */

GLOBAL(void)jpeg_CreateCompress(j_compress_ptr cinfo, unsigned int structsize)
{
  int i;

  /* Guard against version mismatches between library and caller. */
  //  cinfo->mem = 0;		/* so jpeg_destroy knows mem mgr not called */
  //if (version != JPEG_LIB_VERSION)
  //  ERREXIT2(cinfo, JERR_BAD_LIB_VERSION, JPEG_LIB_VERSION, version);
  // (structsize != SIZEOF(struct jpeg_compress_struct))
  //ERREXIT2(cinfo, JERR_BAD_STRUCT_SIZE, 
  //  (int) SIZEOF(struct jpeg_compress_struct), (int) structsize);

  /* For debugging purposes, we zero the whole master structure.
   * But the application has already set the err pointer, and may have set
   * client_data, so we have to save and restore those fields.
   * Note: if application hasn't set client_data, tools like Purify may
   * complain here.
   */
  {
    //    struct jpeg_error_mgr * err = NULL; // DHKIM cinfo->err;
    //    void * client_data = cinfo->client_data; /* ignore Purify complaint here */
    MEMZERO(cinfo, SIZEOF(struct jpeg_compress_struct));
    // cinfo->err = err;
    //    cinfo->client_data = client_data;
  }
  cinfo->is_decompressor = FALSE;

  /* Initialize a memory manager instance for this object */

  //  jinit_memory_mgr((j_common_ptr) cinfo);


  /* Zero out pointers to permanent structures. */
  //  cinfo->progress = NULL;
  cinfo->dest = NULL;

  cinfo->comp_info = NULL;

  for (i = 0; i < NUM_QUANT_TBLS; i++)
    cinfo->quant_tbl_ptrs[i] = NULL;

  for (i = 0; i < NUM_HUFF_TBLS; i++)
  {
    cinfo->dc_huff_tbl_ptrs[i] = NULL;
    cinfo->ac_huff_tbl_ptrs[i] = NULL;
  } 

  //  cinfo->script_space = NULL;

  cinfo->input_gamma = 1.0; /* in case application forgets */

  /* OK, I'm ready */
  cinfo->global_state = CSTATE_START;
}




/*
 * Forcibly suppress or un-suppress all quantization and Huffman tables.
 * Marks all currently defined tables as already written (if suppress)
 * or not written (if !suppress).  This will control whether they get emitted
 * by a subsequent jpeg_start_compress call.
 *
 * This routine is exported for use by applications that want to produce
 * abbreviated JPEG datastreams.  It logically belongs in jcparam.c, but
 * since it is called by jpeg_start_compress, we put it here --- otherwise
 * jcparam.o would be linked whether the application used it or not.
 */

GLOBAL(void)jpeg_suppress_tables(j_compress_ptr cinfo, boolean suppress)
{
  int i;
  JQUANT_TBL *qtbl;
  JHUFF_TBL *htbl;

  for (i = 0; i < NUM_QUANT_TBLS; i++)
  {
    if ((qtbl = cinfo->quant_tbl_ptrs[i]) != NULL)
      qtbl->sent_table = suppress;
  }

  for (i = 0; i < NUM_HUFF_TBLS; i++)
  {
    if ((htbl = cinfo->dc_huff_tbl_ptrs[i]) != NULL)
      htbl->sent_table = suppress;
    if ((htbl = cinfo->ac_huff_tbl_ptrs[i]) != NULL)
      htbl->sent_table = suppress;
  }
}


/*
 * Finish JPEG compression.
 *
 * If a multipass operating mode was selected, this may do a great deal of
 * work including most of the actual output.
 */

GLOBAL(void)jpeg_finish_compress(j_compress_ptr cinfo)
{
  if (cinfo->global_state == CSTATE_SCANNING || cinfo->global_state ==
    CSTATE_RAW_OK)
  {
    /* Terminate first pass */
    //if (cinfo->next_scanline < cinfo->image_height)
    //  ERREXIT(cinfo, JERR_TOO_LITTLE_DATA);

    finish_pass_master(cinfo);
  } // else if (cinfo->global_state != CSTATE_WRCOEFS)
  // ERREXIT1(cinfo, JERR_BAD_STATE, cinfo->global_state);
  /* Perform any remaining passes */

  /* Write EOI, do final cleanup */
  /*  write_file_trailer (cinfo);  JJS- vlc hardware  */
  #ifndef JPEG_ENC_OPT  //bmy 04.12.29 jpeg_enc_opt +
    term_destination(cinfo);
  #endif //bmy 04.12.29 jpeg_enc_opt +
  /* We can use jpeg_abort to release memory and reset global_state */
  jpeg_abort((j_common_ptr)cinfo);
}

#ifndef JPEG_ENC_OPT  //bmy 04.12.21 jpeg_enc_opt + : below
  /*
   * Write a special marker.
   * This is only recommended for writing COM or APPn markers.
   * Must be called after jpeg_start_compress() and before
   * first call to jpeg_write_scanlines() or jpeg_write_raw_data().
   */

  GLOBAL(void)jpeg_write_marker(j_compress_ptr cinfo, int marker, const JOCTET
    *dataptr, unsigned int datalen)
  {
    JMETHOD(void, write_marker_byte, (j_compress_ptr info, int val));

    //if (
    //    (cinfo->global_state != CSTATE_SCANNING &&
    //     cinfo->global_state != CSTATE_RAW_OK &&
    //    cinfo->global_state != CSTATE_WRCOEFS))
    //  ERREXIT1(cinfo, JERR_BAD_STATE, cinfo->global_state);

    write_marker_header(cinfo, marker, datalen);

    while (datalen--)
    {
      write_marker_byte(cinfo,  *dataptr);
      dataptr++;
    }
  }
#endif //bmy 04.12.21 jpeg_enc_opt + : up



/*
 * Alternate compression function: just write an abbreviated table file.
 * Before calling this, all parameters and a data destination must be set up.
 *
 * To produce a pair of files containing abbreviated tables and abbreviated
 * image data, one would proceed as follows:
 *
 *		initialize JPEG object
 *		set JPEG parameters
 *		set destination to table file
 *		jpeg_write_tables(cinfo);
 *		set destination to image file
 *		jpeg_start_compress(cinfo, FALSE);
 *		write data...
 *		jpeg_finish_compress(cinfo);
 *
 * jpeg_write_tables has the side effect of marking all tables written
 * (same as jpeg_suppress_tables(..., TRUE)).  Thus a subsequent start_compress
 * will not re-emit the tables unless it is passed write_all_tables=TRUE.
  */
