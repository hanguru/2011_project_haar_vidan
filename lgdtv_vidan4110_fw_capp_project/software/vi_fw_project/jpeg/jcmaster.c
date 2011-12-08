/*
 * jcmaster.c
 *
 * Copyright (C) 1991-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains master control logic for the JPEG compressor.
 * These routines are concerned with parameter validation, initial setup,
 * and inter-pass control (determining the number of passes and the work 
 * to be done in each pass).
 */

#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#define REMOVE_DIV_OPT   //JSY+
#include "./jpeg_global.h" //bmy 04.12.29 jpeg_enc_opt +

#define NULL 0

/* Private state */

typedef enum
{
  main_pass,  /* input data, also do first output step */
  huff_opt_pass,  /* Huffman code optimization pass */
  output_pass /* data output pass */
} c_pass_type;

typedef struct
{
  // struct jpeg_comp_master pub;	/* public fields */

  c_pass_type pass_type; /* the type of the current pass */

  // int pass_number;		/* # of passes completed */
  // int total_passes;		/* total # of passes needed */

  int scan_number; /* current index in scan_info[] */
} my_comp_master;

typedef my_comp_master *my_master_ptr;

extern GLOBAL(void*)alloc_small(unsigned int sizeofobject);
extern GLOBAL(void)start_pass_coef(j_compress_ptr cinfo);
extern GLOBAL(void)write_frame_header(j_compress_ptr cinfo);
extern GLOBAL(void)write_scan_header(j_compress_ptr cinfo);

/*
 * Support routines that do various essential calculations.
 */

LOCAL(void)initial_setup(j_compress_ptr cinfo)
/* Do computations that are needed before master selection phase */
{
  int ci;
  jpeg_component_info *compptr;
  long samplesperrow;
  JDIMENSION jd_samplesperrow;

  /* Sanity check on image dimensions */
  //if (cinfo->image_height <= 0 || cinfo->image_width <= 0
  //    || cinfo->num_components <= 0 || cinfo->input_components <= 0)
  //  ERREXIT(cinfo, JERR_EMPTY_IMAGE);

  /* Make sure image isn't bigger than I can handle */
  //if ((long) cinfo->image_height > (long) JPEG_MAX_DIMENSION ||
  //    (long) cinfo->image_width > (long) JPEG_MAX_DIMENSION)
  //  ERREXIT1(cinfo, JERR_IMAGE_TOO_BIG, (unsigned int) JPEG_MAX_DIMENSION);

  /* Width of an input scanline must be representable as JDIMENSION. */
  samplesperrow = (long)cinfo->image_width *(long)cinfo->input_components;
  jd_samplesperrow = (JDIMENSION)samplesperrow;
  // if ((long) jd_samplesperrow != samplesperrow)
  //  ERREXIT(cinfo, JERR_WIDTH_OVERFLOW);

  /* For now, precision must match compiled-in value... */

  /* Check that number of components won't exceed internal array sizes */
  if (cinfo->num_components > MAX_COMPONENTS)
    ERREXIT2(cinfo, JERR_COMPONENT_COUNT, cinfo->num_components, MAX_COMPONENTS)
      ;

  /* Compute maximum sampling factors; check factor validity */
  cinfo->max_h_samp_factor = 1;
  cinfo->max_v_samp_factor = 1;
  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++,
    compptr++)
  {
    if (compptr->h_samp_factor <= 0 || compptr->h_samp_factor > MAX_SAMP_FACTOR
      || compptr->v_samp_factor <= 0 || compptr->v_samp_factor >
      MAX_SAMP_FACTOR)
      ERREXIT(cinfo, JERR_BAD_SAMPLING);
    cinfo->max_h_samp_factor = MAX(cinfo->max_h_samp_factor, compptr
      ->h_samp_factor);
    cinfo->max_v_samp_factor = MAX(cinfo->max_v_samp_factor, compptr
      ->v_samp_factor);
  }

  /* Compute dimensions of components */
  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++,
    compptr++)
  {
    /* Fill in the correct component_index value; don't rely on application */
    compptr->component_index = ci;
    /* For compression, we never do DCT scaling. */
    compptr->DCT_scaled_size = DCTSIZE;
    //JSY+
    #ifdef REMOVE_DIV_OPT
      compptr->width_in_blocks = (JDIMENSION)((!ci) ? (cinfo->image_width >> 3)
        : (cinfo->image_width >> 4));
      compptr->height_in_blocks = (JDIMENSION)(!ci) ? (cinfo->image_height >> 3)
        : (cinfo->image_height >> 4);
      compptr->downsampled_width = (JDIMENSION)(!ci) ? (cinfo->image_width): 
        (cinfo->image_width >> 1);
      compptr->downsampled_height = (JDIMENSION)(!ci) ? (cinfo->image_height): 
        (cinfo->image_height >> 1);
    #else 
      /* Size in DCT blocks */
      compptr->width_in_blocks = (JDIMENSION)jdiv_round_up((long)cinfo
        ->image_width *(long)compptr->h_samp_factor, (long)(cinfo
        ->max_h_samp_factor *DCTSIZE));
      compptr->height_in_blocks = (JDIMENSION)jdiv_round_up((long)cinfo
        ->image_height *(long)compptr->v_samp_factor, (long)(cinfo
        ->max_v_samp_factor *DCTSIZE));
      /* Size in samples */
      compptr->downsampled_width = (JDIMENSION)jdiv_round_up((long)cinfo
        ->image_width *(long)compptr->h_samp_factor, (long)cinfo
        ->max_h_samp_factor);
      compptr->downsampled_height = (JDIMENSION)jdiv_round_up((long)cinfo
        ->image_height *(long)compptr->v_samp_factor, (long)cinfo
        ->max_v_samp_factor);
    #endif 
    /* Mark component needed (this flag isn't actually used for compression) */
    compptr->component_needed = TRUE;
  }

  /* Compute number of fully interleaved MCU rows (number of times that
   * main controller will call coefficient controller).
   */
  //JSY+
  #ifdef REMOVE_DIV_OPT
    cinfo->total_iMCU_rows = (JDIMENSION)(cinfo->image_height >> 4);
  #else 
    cinfo->total_iMCU_rows = (JDIMENSION)jdiv_round_up((long)cinfo
      ->image_height, (long)(cinfo->max_v_samp_factor *DCTSIZE));
  #endif 
}



LOCAL(void)select_scan_parameters(j_compress_ptr cinfo)
/* Set up the scan parameters for the current scan */
{
  int ci;

  {
    /* Prepare for single sequential-JPEG scan containing all components */
    // if (cinfo->num_components > MAX_COMPS_IN_SCAN)
    //  ERREXIT2(cinfo, JERR_COMPONENT_COUNT, cinfo->num_components,
    //      MAX_COMPS_IN_SCAN);
    cinfo->comps_in_scan = cinfo->num_components;
    for (ci = 0; ci < cinfo->num_components; ci++)
    {
      cinfo->cur_comp_info[ci] = &cinfo->comp_info[ci];
    }

  }
}


LOCAL(void)per_scan_setup(j_compress_ptr cinfo)
/* Do computations that are needed before processing a JPEG scan */
/* cinfo->comps_in_scan and cinfo->cur_comp_info[] are already set */
{
  int ci, mcublks;
  jpeg_component_info *compptr;

  {

    /* Interleaved (multi-component) scan */
    //if (cinfo->comps_in_scan <= 0 || cinfo->comps_in_scan > MAX_COMPS_IN_SCAN)
    //  ERREXIT2(cinfo, JERR_COMPONENT_COUNT, cinfo->comps_in_scan,
    //       MAX_COMPS_IN_SCAN);

    /* Overall image size in MCUs */
    //JSY+
    #ifdef REMOVE_DIV_OPT
      cinfo->MCUs_per_row = (JDIMENSION)(cinfo->image_width >> 4);
      cinfo->MCU_rows_in_scan = (JDIMENSION)(cinfo->image_height >> 4);
    #else 
      cinfo->MCUs_per_row = (JDIMENSION)jdiv_round_up((long)cinfo->image_width,
        (long)(cinfo->max_h_samp_factor *DCTSIZE));
      cinfo->MCU_rows_in_scan = (JDIMENSION)jdiv_round_up((long)cinfo
        ->image_height, (long)(cinfo->max_v_samp_factor *DCTSIZE));
    #endif 

    cinfo->blocks_in_MCU = 0;

    for (ci = 0; ci < cinfo->comps_in_scan; ci++)
    {
      compptr = cinfo->cur_comp_info[ci];
      /* Sampling factors give # of blocks of component in each MCU */
      compptr->MCU_width = compptr->h_samp_factor;
      compptr->MCU_height = compptr->v_samp_factor;
      compptr->MCU_blocks = compptr->MCU_width *compptr->MCU_height;
      compptr->MCU_sample_width = compptr->MCU_width *DCTSIZE;
      /* Figure number of non-dummy blocks in last MCU column & row */
      //JSY+
      #ifdef REMOVE_DIV_OPT
        compptr->last_col_width = compptr->MCU_width;
        compptr->last_row_height = compptr->MCU_height;
      #else 
        tmp = (int)(compptr->width_in_blocks % compptr->MCU_width);
        if (tmp == 0)
          tmp = compptr->MCU_width;
        compptr->last_col_width = tmp;
        tmp = (int)(compptr->height_in_blocks % compptr->MCU_height);
        if (tmp == 0)
          tmp = compptr->MCU_height;
        compptr->last_row_height = tmp;
      #endif 
      /* Prepare array describing MCU composition */
      mcublks = compptr->MCU_blocks;
      //   if (cinfo->blocks_in_MCU + mcublks > C_MAX_BLOCKS_IN_MCU)
      //	ERREXIT(cinfo, JERR_BAD_MCU_SIZE);
      while (mcublks-- > 0)
      {
        cinfo->MCU_membership[cinfo->blocks_in_MCU++] = ci;
      }
    }

  }

  /* Convert restart specified in rows to actual MCU count. */
  /* Note that count must fit in 16 bits, so we provide limiting. */
  //  if (cinfo->restart_in_rows > 0) {
  //    long nominal = (long) cinfo->restart_in_rows * (long) cinfo->MCUs_per_row;
  //    cinfo->restart_interval = (unsigned int) MIN(nominal, 65535L);
  // }
}


/*
 * Per-pass setup.
 * This is called at the beginning of each pass.  We determine which modules
 * will be active during this pass and give them appropriate start_pass calls.
 * We also set is_last_pass to indicate whether any more passes will be
 * required.
 */

GLOBAL(void)prepare_for_pass(j_compress_ptr cinfo)
{
  my_master_ptr master = (my_master_ptr)cinfo->master;

  switch (master->pass_type)
  {
    case main_pass:
      /* Initial pass: will collect input data, and do either Huffman
       * optimization or data output for the first scan.
       */
      select_scan_parameters(cinfo);
      per_scan_setup(cinfo);

      //#ifndef DBUG_pk0157s 
      //  start_pass_fdctmgr(cinfo);
      //#endif 
      #ifndef JPEG_ENC_OPT  //bmy 04.12.29 jpeg_enc_opt +
        start_pass_huff(cinfo, 0);
      #endif //bmy 04.12.29 jpeg_enc_opt +
      start_pass_coef(cinfo);
      //			(master->total_passes > 1 ?
      //			 JBUF_SAVE_AND_PASS : JBUF_PASS_THRU));

      break;

    case output_pass:
      /* Do a data-output pass. */
      /* We need not repeat per-scan setup if prior optimization pass did it. */
      {
        select_scan_parameters(cinfo);
        per_scan_setup(cinfo);
      }
      //pjh-start_pass_huff_decoder (cinfo, FALSE);
      //start_pass_coef(cinfo, JBUF_CRANK_DEST);
      start_pass_coef(cinfo);
      /* We emit frame/scan headers now */
      if (master->scan_number == 0)
        write_frame_header(cinfo);
      write_scan_header(cinfo);

      break;
    default:
	  return;
  }

}


/*
 * Special start-of-pass hook.
 * This is called by jpeg_write_scanlines if call_pass_startup is TRUE.
 * In single-pass processing, we need this hook because we don't want to
 * write frame/scan headers during jpeg_start_compress; we want to let the
 * application write COM markers etc. between jpeg_start_compress and the
 * jpeg_write_scanlines loop.
 * In multi-pass processing, this routine is not used.
 */

GLOBAL(void)pass_startup(j_compress_ptr cinfo)
{
  cinfo->master->call_pass_startup = FALSE; /* reset flag so call only once */

  write_frame_header(cinfo);
  write_scan_header(cinfo);
}


/*
 * Finish up at end of pass.
 */

GLOBAL(void)finish_pass_master(j_compress_ptr cinfo)
{
  my_master_ptr master = (my_master_ptr)cinfo->master;

  /* The entropy coder always needs an end-of-pass call,
   * either to analyze statistics or to flush its output buffer.
   */
  #ifndef JPEG_ENC_OPT  //bmy 04.12.29 jpeg_enc_opt +
    finish_pass_huff(cinfo);
  #endif //bmy 04.12.29 jpeg_enc_opt +

  /* Update state for next pass */
  switch (master->pass_type)
  {
    case main_pass:
      /* next pass is either output of scan 0 (after optimization)
       * or output of scan 1 (if no optimization).
       */
      master->pass_type = output_pass;

      master->scan_number++;
      break;
    case huff_opt_pass:
      /* next pass is always output of current scan */
      master->pass_type = output_pass;
      break;
    case output_pass:
      /* next pass is either optimization or output of next scan */

      master->pass_type = huff_opt_pass;
      master->scan_number++;
      break;
  }

  //  master->pass_number++;
}


/*
 * Initialize master compression control.
 */

GLOBAL(void)jinit_c_master_control(j_compress_ptr cinfo)
{
  my_master_ptr master;

  if (cinfo->master == NULL)
  {
    master = (my_master_ptr)alloc_small(SIZEOF(my_comp_master));
    cinfo->master = (struct jpeg_comp_master*)master;
  }
  else
  {
    master = (my_master_ptr)cinfo->master;
  } 
  ///////////////////////////////
  //  master->pub.prepare_for_pass = prepare_for_pass;
  //  master->pub.pass_startup = pass_startup;
  //  master->pub.finish_pass = finish_pass_master;
  //  master->pub.is_last_pass = FALSE;

  /* Validate parameters, determine derived values */
  initial_setup(cinfo);


  //    cinfo->num_scans = 1;



  /* for normal compression, first pass is always this type: */
  master->pass_type = main_pass;
  master->scan_number = 0;
  //  master->pass_number = 0;

  //    master->total_passes = cinfo->num_scans;
}
