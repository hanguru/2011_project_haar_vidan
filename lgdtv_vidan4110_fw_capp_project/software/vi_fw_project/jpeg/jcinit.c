/*
 * jcinit.c
 *
 * Copyright (C) 1991-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains initialization logic for the JPEG compressor.
 * This routine is in charge of selecting the modules to be executed and
 * making an initialization call to each one.
 *
 * Logically, this code belongs in jcmaster.c.  It's split out because
 * linking this routine implies linking the entire compression library.
 * For a transcoding-only application, we want to be able to use jcmaster.c
 * without linking in the whole library.
 */

#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "./jpeg_global.h" //bmy 04.12.29 jpeg_enc_opt +
extern GLOBAL(void)write_file_header(j_compress_ptr cinfo);
/*
 * Master selection of compression modules.
 * This is done once at the start of processing an image.  We determine
 * which modules will be used and give them appropriate initialization calls.
 */

GLOBAL(void)jinit_compress_master(j_compress_ptr cinfo)
{
  /* Initialize master control (includes parameter checking/processing) */
  jinit_c_master_control(cinfo);

  /* Preprocessing */

  #ifndef JPEG_ENC_OPT
    /* Forward DCT */
    #ifndef DBUG_pk0157s
      jinit_forward_dct(cinfo);
    #endif 
  #endif 
  /* Entropy encoding: either Huffman or arithmetic coding. */

  #ifndef JPEG_ENC_OPT  //bmy 04.12.29 jpeg_enc_opt +    
    jinit_huff_encoder(cinfo);
  #endif //bmy 04.12.29 jpeg_enc_opt +  

  /* Need a full-image coefficient buffer in any multi-pass mode. */
  jinit_c_coef_controller(cinfo);



  /* We can now tell the memory manager to allocate virtual arrays. */
  // realize_virt_arrays ((j_common_ptr) cinfo);

  /* Write the datastream header (SOI) immediately.
   * Frame and scan headers are postponed till later.
   * This lets application insert special markers after the SOI.
   */
  write_file_header(cinfo);
}
