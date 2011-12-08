/*
 * jcapistd.c
 *
 * Copyright (C) 1994-1996, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains application interface code for the compression half
 * of the JPEG library.  These are the "standard" API routines that are
 * used in the normal full-compression case.  They are not used by a
 * transcoding-only application.  Note that if an application links in
 * jpeg_start_compress, it will end up linking in the entire compressor.
 * We thus must separate this file from jcapimin.c to avoid linking the
 * whole compression library into a transcoder.
 */

#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "./jpeg_global.h" //bmy 04.12.29 jpeg_enc_opt +

extern GLOBAL(void)prepare_for_pass(j_compress_ptr cinfo);
/*
 * Compression initialization.
 * Before calling this, all parameters and a data destination must be set up.
 *
 * We require a write_all_tables parameter as a failsafe check when writing
 * multiple datastreams from the same compression object.  Since prior runs
 * will have left all the tables marked sent_table=TRUE, a subsequent run
 * would emit an abbreviated stream (no tables) by default.  This may be what
 * is wanted, but for safety's sake it should not be the default behavior:
 * programmers should have to make a deliberate choice to emit abbreviated
 * images.  Therefore the documentation and examples should encourage people
 * to pass write_all_tables=TRUE; then it will take active thought to do the
 * wrong thing.
 */

GLOBAL(void)jpeg_start_compress(j_compress_ptr cinfo, boolean write_all_tables)
{
  // DHKIM
  //  cinfo->raw_data_in = 1;

  if (cinfo->global_state != CSTATE_START)
    ERREXIT1(cinfo, JERR_BAD_STATE, cinfo->global_state);

  if (write_all_tables)
    jpeg_suppress_tables(cinfo, FALSE);
   /* mark all tables to be written */

  /* (Re)initialize error mgr and destination modules */
  //  (*cinfo->err->reset_error_mgr) ((j_common_ptr) cinfo);
  #ifndef JPEG_ENC_OPT  //bmy 04.12.29 jpeg_enc_opt +
    init_destination(cinfo);
  #endif //bmy 04.12.29 jpeg_enc_opt +
  /* Perform master selection of active modules */
  jinit_compress_master(cinfo);
  /* Set up for the first pass */
  prepare_for_pass(cinfo);
  /* Ready for application to drive first pass through jpeg_write_scanlines
   * or jpeg_write_raw_data.
   */
  //  cinfo->next_scanline = 0;


  cinfo->global_state = CSTATE_SCANNING;
}
