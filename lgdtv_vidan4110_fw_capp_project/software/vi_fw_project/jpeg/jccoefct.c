
/*
 * jccoefct.c
 *
 * Copyright (C) 1994-1997, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains the coefficient buffer controller for compression.
 * This controller is the top level of the JPEG compressor proper.
 * The coefficient buffer lies between forward-DCT and entropy encoding steps.
 */

#define JPEG_INTERNALS
//#include "V1_define.h" //JSY+ 06.07.04
#include "jinclude.h"
#include "jpeglib.h"

//JSY+
#include "./jpeg_global.h"
//#include "../header/map.h"
//#include "../header/top_test.h"
#include "map.h"

/* We use a full-image coefficient buffer when doing Huffman optimization,
 * and also for writing multiple-scan JPEG files.  In all cases, the DCT
 * step is run during the first pass, and subsequent passes need only read
 * the buffered coefficients.
 */

#ifdef ENTROPY_OPT_SUPPORTED
  #define FULL_COEF_BUFFER_SUPPORTED
#else 
#endif 

#define NULL 0
extern GLOBAL(void*)alloc_small(unsigned int sizeofobject);
extern GLOBAL(void FAR*)alloc_large(unsigned int sizeofobject);

/* Private buffer controller object */
char tick = 0;
typedef struct
{
  //  struct jpeg_c_coef_controller pub; /* public fields */

  JDIMENSION iMCU_row_num; /* iMCU row # within image */
  JDIMENSION mcu_ctr; /* counts MCUs processed in current row */
  int MCU_vert_offset; /* counts MCU rows within iMCU row */
  int MCU_rows_per_iMCU_row; /* number of such rows needed */

  /* For single-pass compression, it's sufficient to buffer just one MCU
   * (although this may prove a bit slow in practice).  We allocate a
   * workspace of C_MAX_BLOCKS_IN_MCU coefficient blocks, and reuse it for each
   * MCU constructed and sent.  (On 80x86, the workspace is FAR even though
   * it's not really very big; this is to keep the module interfaces unchanged
   * when a large coefficient buffer is necessary.)
   * In multi-pass modes, this array points to the current MCU's blocks
   * within the virtual arrays.
   */
  JBLOCKROW MCU_buffer[C_MAX_BLOCKS_IN_MCU];

  /* In multi-pass modes, we need a virtual block array for each component. */
  // jvirt_barray_ptr whole_image[MAX_COMPONENTS];
} my_coef_controller;

typedef my_coef_controller *my_coef_ptr;


/* Forward declarations */
GLOBAL(boolean)compress_data 
//JPP((j_compress_ptr cinfo, JSAMPIMAGE input_buf));  //JSY-
JPP((j_compress_ptr cinfo, int iMBY, int jpeg_sel)); //JSY+ //kik+
#ifdef FULL_COEF_BUFFER_SUPPORTED
  METHODDEF(boolean)compress_first_pass JPP((j_compress_ptr cinfo, JSAMPIMAGE
    input_buf));
  METHODDEF(boolean)compress_output JPP((j_compress_ptr cinfo, JSAMPIMAGE
    input_buf));
#endif 


LOCAL(void)start_iMCU_row(j_compress_ptr cinfo)
/* Reset within-iMCU-row counters for a new row */
{
  my_coef_ptr coef = (my_coef_ptr)cinfo->coef;

  /* In an interleaved scan, an MCU row is the same as an iMCU row.
   * In a noninterleaved scan, an iMCU row has v_samp_factor MCU rows.
   * But at the bottom of the image, process only what's left.
   */
  if (cinfo->comps_in_scan > 1)
  {
    coef->MCU_rows_per_iMCU_row = 1;
  }
  else
  {
    if (coef->iMCU_row_num < (cinfo->total_iMCU_rows - 1))
      coef->MCU_rows_per_iMCU_row = cinfo->cur_comp_info[0]->v_samp_factor;
    else
      coef->MCU_rows_per_iMCU_row = cinfo->cur_comp_info[0]->last_row_height;
  }

  coef->mcu_ctr = 0;
  coef->MCU_vert_offset = 0;
}


/*
 * Initialize for a processing pass.
 */

GLOBAL(void)start_pass_coef(j_compress_ptr cinfo) // , J_BUF_MODE pass_mode)
{
  my_coef_ptr coef = (my_coef_ptr)cinfo->coef;

  coef->iMCU_row_num = 0;
  start_iMCU_row(cinfo);

  //  switch (pass_mode) {
  //  case JBUF_PASS_THRU:
  //    coef->pub.compress_data = compress_data;
  //    break;

  //  default:
  //    ERREXIT(cinfo, JERR_BAD_BUFFER_MODE);
  //    break;
  //  }
}


/*
 * Process some data in the single-pass case.
 * We process the equivalent of one fully interleaved MCU row ("iMCU" row)
 * per call, ie, v_samp_factor block rows for each component in the image.
 * Returns TRUE if the iMCU row is completed, FALSE if suspended.
 *
 * NB: input_buf contains a plane for each component in image,
 * which we index according to the component's SOF position.
 */
//#define RUN_SW
GLOBAL(boolean)
//compress_data (j_compress_ptr cinfo, JSAMPIMAGE input_buf)  //JSY-
compress_data(j_compress_ptr cinfo, int number, int jpeg_sel) //JSY+ //kik+
{
  my_coef_ptr coef = (my_coef_ptr)cinfo->coef;
  JDIMENSION MCU_col_num; /* index of current MCU within row */
  JDIMENSION last_MCU_col = cinfo->MCUs_per_row - 1;
  //kik-  JDIMENSION last_iMCU_row = cinfo->total_iMCU_rows - 1;
  //kik-  int blkn, bi, ci, yindex, yoffset, blockcnt, TEMP;
  //kik-  JDIMENSION ypos, xpos;
  //kik-  jpeg_component_info *compptr;

  /*_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
  H/W
  _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/*/

  int iMBX, iMBY;

  //	unsigned int *DCT_DATA_IN = (0x00800000);    //JSY-
  //	unsigned int *DCT_DATA_OUT = (0x00840000);   //JSY-
  //	unsigned int *out_ready_flag = (0x00804000); //JSY-


  //	*out_ready_flag = 0;  //JSY-

  /*_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
  S/W
  _/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/*/

  /* Loop to write as much as one whole iMCU row */
  //kik for (yoffset = coef->MCU_vert_offset; yoffset < coef->MCU_rows_per_iMCU_row;
  //kik      yoffset++) {
  for (MCU_col_num = coef->mcu_ctr; MCU_col_num <= last_MCU_col; MCU_col_num++)
  {
    /* Determine where data comes from in input_buf and do the DCT thing.
     * Each call on forward_DCT processes a horizontal row of DCT blocks
     * as wide as an MCU; we rely on having allocated the MCU_buffer[] blocks
     * sequentially.  Dummy blocks at the right or bottom edge are filled in
     * specially.  The data in them does not matter for image reconstruction,
     * so we fill them with values that will encode to the smallest amount of
     * data, viz: all zeroes in the AC entries, DC entries equal to previous
     * block's DC value.  (Thanks to Thomas Kinsman for this idea.)
     */

    //////////////////////////////////////////////////////////////////////////////////////////
    /* JSY+ : Start DCTQ module and store the result in SDRAM.
     * DCTQ operation is macroblock based and must be started before block operation. Sequence is as follows.
     * 1. Dump Macroblock data from SDRAM to SWF0 for passing through MECMC
     * 2. Wait until Macroblock data pass through MEFMC and is stored in DCTQ Residual Buffer
     * 3. Set DCTQ registers and start DCTQ. Wait some time for DCTQ to be completed
     * 4. Read the result from QCO buffer and store it in SDRAM
     * The remaining process is block based and processes later.
     */

    iMBX = MCU_col_num;
    iMBY = number * 16;
    iMBX = iMBX * 8;

    if (tick == 0)
    {
      while(!(*MI_STATUS)) 
	;
      *DQ_CTRL = 0x0; //RES1Buffer write
      *MI_REG1 = 0x1; // half macroblock st
      *MI_REG1 = 0x0;
      *DQ_OPMODE = 0x2014; //OP_MODE:Encoder,  Intra, mjpeg
        tick = 1;

      while(!(*MI_STATUS))
	;
      while(!((*DQ_CBP_DONE)&0x1))
	;
      *DQ_CTRL = 0x400; //dctq_st(10)
      *DQ_CTRL = 0x0; //DCTQ_ST low.
    }
    else
    {
      //tick=1
      while(!(*MI_STATUS))
	;
      *DQ_CTRL = 0x4000; //RES2Buffer write
      *MI_REG1 = 0x1; // half macroblock st
      *MI_REG1 = 0x0;
      *DQ_OPMODE = 0x2014; //OP_MODE:Encoder,  Intra, mjpeg
        tick = 0;

      while(!((*DQ_CBP_DONE)&0x1))
	;
      *DQ_CTRL = 0xC000; //dctq_st(15)
      *DQ_CTRL = 0x4000;
    }
  }
  /* Completed an MCU row, but perhaps not an iMCU row */
  coef->mcu_ctr = 0;
  return TRUE;
}





/*
 * Initialize coefficient buffer controller.
 */

GLOBAL(void)jinit_c_coef_controller(j_compress_ptr cinfo)
{
  my_coef_ptr coef;

  if (cinfo->coef == NULL)
  {
    coef = (my_coef_ptr)alloc_small(SIZEOF(my_coef_controller));
    cinfo->coef = (struct jpeg_c_coef_controller*)coef;
  }
  else
  {
    coef = (my_coef_ptr)cinfo->coef;
  } 

  if (coef->MCU_buffer[0] == NULL)
  //  coef->pub.start_pass = start_pass_coef;

  /* Create the coefficient buffer. */
  {
    /* We only need a single-MCU buffer. */
    JBLOCKROW buffer;
    int i;

    buffer = (JBLOCKROW)alloc_large(C_MAX_BLOCKS_IN_MCU *SIZEOF(JBLOCK));
    for (i = 0; i < C_MAX_BLOCKS_IN_MCU; i++)
    {
      coef->MCU_buffer[i] = buffer + i;
    }

  }
}
