/*
 * jcparam.c
 *
 * Copyright (C) 1991-1998, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains optional default-setting code for the JPEG compressor.
 * Applications do not have to use this file, but those that don't use it
 * must know a lot more about the innards of the JPEG code.
 */

#define JPEG_INTERNALS
#include <string.h>
#include "jinclude.h"
#include "jpeglib.h"
#include "./jpeg_global.h" //JSY+
#include "map.h"    //JSY+

extern GLOBAL(void*)alloc_small(unsigned int sizeofobject);

/*
 * Quantization table setup routines
 */

GLOBAL(void)jpeg_add_quant_table(j_compress_ptr cinfo, int which_tbl, const
  unsigned int *basic_table, int scale_factor, boolean force_baseline)
/* Define a quantization table equal to the basic_table times
 * a scale factor (given as a percentage).
 * If force_baseline is TRUE, the computed quantization table entries
 * are limited to 1..255 for JPEG baseline compatibility.
 */
{
  JQUANT_TBL **qtblptr;
  int i;
  long temp;

  /* Safety check to ensure start_compress not called yet. */
  if (cinfo->global_state != CSTATE_START)
    ERREXIT1(cinfo, JERR_BAD_STATE, cinfo->global_state);

  if (which_tbl < 0 || which_tbl >= NUM_QUANT_TBLS)
    ERREXIT1(cinfo, JERR_DQT_INDEX, which_tbl);

  qtblptr = &cinfo->quant_tbl_ptrs[which_tbl];

  if (*qtblptr == NULL)
    *qtblptr = jpeg_alloc_quant_table((j_common_ptr)cinfo);

  *DQ_RST = 0x1; //kik+ counter reset for Qtable
  *DQ_RST = 0x0; //kik+ counter reset for Qtable

  for (i = 0; i < DCTSIZE2; i++)
  {
    temp = (long)((basic_table[i] *scale_factor + 50) / 100); //kik 
    // temp = ((long) basic_table[i] * scale_factor + 50L) / 100L;
    // temp = (long) basic_table[i]  + 0.5;  //JSY-
    // temp = (long) basic_table[i];           //JSY+

    /* limit the values to the valid range */
    if (temp <= 0L)
      temp = 1L;
    if (temp > 32767L)
      temp = 32767L;
     /* max quantizer needed for 12 bits */
    if (force_baseline && temp > 255L)
      temp = 255L;
     /* limit to baseline range if requested */
    //////////////////////////
    (*qtblptr)->quantval[i] = (UINT16)temp;

    //kik+ 041214////////////////////////////////////////
    if (which_tbl == 0)
    {
      //kik
      if (temp == 1L)
        *DQ_LU = (UINT16)32767;
      //kik
      else
        *DQ_LU = (UINT16)((UINT16)32768 / (UINT16)temp);
      //kik
    } //kik
    else
    {
      //kik
      if (temp == 1L)
        *DQ_CH = (UINT16)32767;
      else
        *DQ_CH = (UINT16)((UINT16)32768 / (UINT16)temp);
      //kik
    }
    //kik+ 041214/////////////////////////////////////////kik
  }

  /* Initialize sent_table FALSE so table will be written to JPEG file. */
  (*qtblptr)->sent_table = FALSE;
}


GLOBAL(void)jpeg_set_linear_quality(j_compress_ptr cinfo, int scale_factor,
  boolean force_baseline)
/* Set or change the 'quality' (quantization) setting, using default tables
 * and a straight percentage-scaling quality scale.  In most cases it's better
 * to use jpeg_set_quality (below); this entry point is provided for
 * applications that insist on a linear percentage scaling.
 */
{
  /* These are the sample quantization tables given in JPEG spec section K.1.
   * The spec says that the values given produce "good" quality, and
   * when divided by 2, "very good" quality.
   */
  static const unsigned int std_luminance_quant_tbl[DCTSIZE2] = 
  {
    16, 11, 10, 16, 24, 40, 51, 61, 12, 12, 14, 19, 26, 58, 60, 55, 14, 13, 16,
      24, 40, 57, 69, 56, 14, 17, 22, 29, 51, 87, 80, 62, 18, 22, 37, 56, 68,
      109, 103, 77, 24, 35, 55, 64, 81, 104, 113, 92, 49, 64, 78, 87, 103, 121,
      120, 101, 72, 92, 95, 98, 112, 100, 103, 99
  };
  static const unsigned int std_chrominance_quant_tbl[DCTSIZE2] = 
  {
    17, 18, 24, 47, 99, 99, 99, 99, 18, 21, 26, 66, 99, 99, 99, 99, 24, 26, 56,
      99, 99, 99, 99, 99, 47, 66, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
      99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
      99, 99, 99, 99, 99, 99, 99, 99, 99
  };

  /* Set up two quantization tables using the specified scaling */
  jpeg_add_quant_table(cinfo, 0, std_luminance_quant_tbl, scale_factor,
    force_baseline);
  jpeg_add_quant_table(cinfo, 1, std_chrominance_quant_tbl, scale_factor,
    force_baseline);
}


GLOBAL(int)jpeg_quality_scaling(int quality)
/* Convert a user-specified quality rating to a percentage scaling factor
 * for an underlying quantization table, using our recommended scaling curve.
 * The input 'quality' factor should be 0 (terrible) to 100 (very good).
 */
{
  /* Safety limit on quality factor.  Convert 0 to 1 to avoid zero divide. */
  if (quality <= 0)
    quality = 1;
  if (quality > 100)
    quality = 100;
  //kik+
  //kik-  if (quality > 100 ) quality = 100;

  /* The basic table is used as-is (scaling 100) for a quality of 50.
   * Qualities 50..100 are converted to scaling percentage 200 - 2*Q;
   * note that at Q=100 the scaling is 0, which will cause jpeg_add_quant_table
   * to make all the table entries 1 (hence, minimum quantization loss).
   * Qualities 1..50 are converted to scaling percentage 5000/Q.
   */
  if (quality < 50)
    quality = 5000 / quality;
  else
    quality = 200-quality * 2;

  return quality;
}


GLOBAL(void)jpeg_set_quality(j_compress_ptr cinfo, int quality)
/* Set or change the 'quality' (quantization) setting, using default tables.
 * This is the standard quality-adjusting entry point for typical user
 * interfaces; only those who want detailed control over quantization tables
 * would use the preceding three routines directly.
 */
{
  /* Convert user 0-100 rating to percentage scaling */
  quality = jpeg_quality_scaling(quality);

  /* Set up standard quality tables */
  jpeg_set_linear_quality(cinfo, quality, 1);
}


/*
 * Huffman table setup routines
 */

LOCAL(void)add_huff_table(j_compress_ptr cinfo, JHUFF_TBL **htblptr, const
  UINT8 *bits, const UINT8 *val)
/* Define a Huffman table */
{
  int nsymbols, len;

  if (*htblptr == NULL)
    *htblptr = jpeg_alloc_huff_table((j_common_ptr)cinfo);

  /* Copy the number-of-symbols-of-each-code-length counts */
  MEMCOPY((*htblptr)->bits, bits, SIZEOF((*htblptr)->bits));

  /* Validate the counts.  We do this here mainly so we can copy the right
   * number of symbols from the val[] array, without risking marching off
   * the end of memory.  jchuff.c will do a more thorough test later.
   */
  nsymbols = 0;
  for (len = 1; len <= 16; len++)
    nsymbols += bits[len];
  if (nsymbols < 1 || nsymbols > 256)
    ERREXIT(cinfo, JERR_BAD_HUFF_TABLE);

  MEMCOPY((*htblptr)->huffval, val, nsymbols *SIZEOF(UINT8));

  /* Initialize sent_table FALSE so table will be written to JPEG file. */
  (*htblptr)->sent_table = FALSE;
}


LOCAL(void)std_huff_tables(j_compress_ptr cinfo)
/* Set up the standard Huffman tables (cf. JPEG standard section K.3) */
/* IMPORTANT: these are only valid for 8-bit data precision! */
{
  static const UINT8 bits_dc_luminance[17] = 
  {
     /* 0-base */0, 0, 1, 5, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0
  };
  static const UINT8 val_dc_luminance[] = 
  {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
  };

  static const UINT8 bits_dc_chrominance[17] = 
  {
     /* 0-base */0, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0
  };
  static const UINT8 val_dc_chrominance[] = 
  {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
  };

  static const UINT8 bits_ac_luminance[17] = 
  {
     /* 0-base */0, 0, 2, 1, 3, 3, 2, 4, 3, 5, 5, 4, 4, 0, 0, 1, 0x7d
  };
  static const UINT8 val_ac_luminance[] = 
  {
    0x01, 0x02, 0x03, 0x00, 0x04, 0x11, 0x05, 0x12, 0x21, 0x31, 0x41, 0x06,
      0x13, 0x51, 0x61, 0x07, 0x22, 0x71, 0x14, 0x32, 0x81, 0x91, 0xa1, 0x08,
      0x23, 0x42, 0xb1, 0xc1, 0x15, 0x52, 0xd1, 0xf0, 0x24, 0x33, 0x62, 0x72,
      0x82, 0x09, 0x0a, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x25, 0x26, 0x27, 0x28,
      0x29, 0x2a, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x43, 0x44, 0x45,
      0x46, 0x47, 0x48, 0x49, 0x4a, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
      0x5a, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x73, 0x74, 0x75,
      0x76, 0x77, 0x78, 0x79, 0x7a, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
      0x8a, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0xa2, 0xa3,
      0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6,
      0xb7, 0xb8, 0xb9, 0xba, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9,
      0xca, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xe1, 0xe2,
      0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xf1, 0xf2, 0xf3, 0xf4,
      0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa
  };

  static const UINT8 bits_ac_chrominance[17] = 
  {
     /* 0-base */0, 0, 2, 1, 2, 4, 4, 3, 4, 7, 5, 4, 4, 0, 1, 2, 0x77
  };
  static const UINT8 val_ac_chrominance[] = 
  {
    0x00, 0x01, 0x02, 0x03, 0x11, 0x04, 0x05, 0x21, 0x31, 0x06, 0x12, 0x41,
      0x51, 0x07, 0x61, 0x71, 0x13, 0x22, 0x32, 0x81, 0x08, 0x14, 0x42, 0x91,
      0xa1, 0xb1, 0xc1, 0x09, 0x23, 0x33, 0x52, 0xf0, 0x15, 0x62, 0x72, 0xd1,
      0x0a, 0x16, 0x24, 0x34, 0xe1, 0x25, 0xf1, 0x17, 0x18, 0x19, 0x1a, 0x26,
      0x27, 0x28, 0x29, 0x2a, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x43, 0x44,
      0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
      0x59, 0x5a, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x73, 0x74,
      0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
      0x88, 0x89, 0x8a, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a,
      0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xb2, 0xb3, 0xb4,
      0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
      0xc8, 0xc9, 0xca, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda,
      0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xf2, 0xf3, 0xf4,
      0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa
  };

  add_huff_table(cinfo, &cinfo->dc_huff_tbl_ptrs[0], bits_dc_luminance,
    val_dc_luminance);
  add_huff_table(cinfo, &cinfo->ac_huff_tbl_ptrs[0], bits_ac_luminance,
    val_ac_luminance);
  add_huff_table(cinfo, &cinfo->dc_huff_tbl_ptrs[1], bits_dc_chrominance,
    val_dc_chrominance);
  add_huff_table(cinfo, &cinfo->ac_huff_tbl_ptrs[1], bits_ac_chrominance,
    val_ac_chrominance);
}


/*
 * Default parameter setup for compression.
 *
 * Applications that don't choose to use this routine must do their
 * own setup of all these parameters.  Alternately, you can call this
 * to establish defaults and then alter parameters selectively.  This
 * is the recommended approach since, if we add any new parameters,
 * your code will still work (they'll be set to reasonable defaults).
 */

GLOBAL(void)jpeg_set_defaults(j_compress_ptr cinfo, int qfactor, int jpeg_sel)
  //kik+
{


  /* Safety check to ensure start_compress not called yet. */
  if (cinfo->global_state != CSTATE_START)
    ERREXIT1(cinfo, JERR_BAD_STATE, cinfo->global_state);

  /* Allocate comp_info array large enough for maximum component count.
   * Array is made permanent in case application wants to compress
   * multiple images at same param settings.
   */

  if (cinfo->comp_info == NULL)
    cinfo->comp_info = (jpeg_component_info*)alloc_small(MAX_COMPONENTS *SIZEOF
      (jpeg_component_info));

  /* Initialize everything not dependent on the color space */
  cinfo->in_color_space = JCS_YCbCr;
  cinfo->input_components = 3;
  cinfo->num_components = 3;
  cinfo->data_precision = 8;

  /* Set up two quantization tables using default quality of 75 */
  //  jpeg_set_quality(cinfo, 75); //kik-
  jpeg_set_quality(cinfo, qfactor); //kik+
  /* Set up two Huffman tables */
  std_huff_tables(cinfo);

  /* Initialize default arithmetic coding conditioning */


  /* Default is no multiple-scan output */
  //  cinfo->num_scans = 0;

  /* Expect normal source image, not raw downsampled data */
  //  cinfo->raw_data_in = FALSE;

  /* Use Huffman coding, not arithmetic coding, by default */


  /* By default, don't do extra passes to optimize entropy coding */

  /* The standard Huffman tables are only valid for 8-bit data precision.
   * If the precision is higher, force optimization on so that usable
   * tables will be computed.  This test can be removed if default tables
   * are supplied that are valid for the desired precision.
   */

  /* By default, use the simpler non-cosited sampling alignment */
  //  cinfo->CCIR601_sampling = FALSE;

  /* No input smoothing */
  // cinfo->smoothing_factor = 0;

  /* DCT algorithm preference */
  //  cinfo->dct_method = JDCT_DEFAULT;

  /* No restart markers */
  //  cinfo->restart_interval = 0;
  //  cinfo->restart_in_rows = 0;

  /* Fill in default JFIF marker parameters.  Note that whether the marker
   * will actually be written is determined by jpeg_set_colorspace.
   *
   * By default, the library emits JFIF version code 1.01.
   * An application that wants to emit JFIF 1.02 extension markers should set
   * JFIF_minor_version to 2.  We could probably get away with just defaulting
   * to 1.02, but there may still be some decoders in use that will complain
   * about that; saying 1.01 should minimize compatibility problems.
   */
  cinfo->JFIF_major_version = 1; /* Default JFIF version = 1.01 */
  cinfo->JFIF_minor_version = 1;
  cinfo->density_unit = 0; /* Pixel size is unknown by default */
  cinfo->X_density = 1; /* Pixel aspect ratio is square by default */
  cinfo->Y_density = 1;

  /* Choose JPEG colorspace based on input space, set defaults accordingly */

  jpeg_default_colorspace(cinfo, jpeg_sel); //kik+
}


/*
 * Select an appropriate JPEG colorspace for in_color_space.
 */

GLOBAL(void)jpeg_default_colorspace(j_compress_ptr cinfo, int jpeg_sel) //kik+
{

  // DHKIM
  jpeg_set_colorspace(cinfo, JCS_YCbCr, jpeg_sel); //kik+
  /* switch (cinfo->in_color_space) {
  case JCS_GRAYSCALE:
  jpeg_set_colorspace(cinfo, JCS_GRAYSCALE);
  break;
  case JCS_RGB:
  jpeg_set_colorspace(cinfo, JCS_YCbCr);
  break;
  case JCS_YCbCr:
  jpeg_set_colorspace(cinfo, JCS_YCbCr);
  break;
  case JCS_CMYK:
  jpeg_set_colorspace(cinfo, JCS_CMYK); 
  break;
  case JCS_YCCK:
  jpeg_set_colorspace(cinfo, JCS_YCCK);
  break;
  case JCS_UNKNOWN:
  jpeg_set_colorspace(cinfo, JCS_UNKNOWN);
  break;
  default:
  ERREXIT(cinfo, JERR_BAD_IN_COLORSPACE);
  }
   */
}


/*
 * Set the JPEG colorspace, and choose colorspace-dependent default values.
 */

GLOBAL(void)jpeg_set_colorspace(j_compress_ptr cinfo, J_COLOR_SPACE colorspace,
  int jpeg_sel) //kik+
{
  jpeg_component_info *compptr;
  //kik-  int ci;

  #define SET_COMP(index,id,hsamp,vsamp,quant,dctbl,actbl)  \
  (compptr = &cinfo->comp_info[index], \
  compptr->component_id = (id), \
  compptr->h_samp_factor = (hsamp), \
  compptr->v_samp_factor = (vsamp), \
  compptr->quant_tbl_no = (quant), \
  compptr->dc_tbl_no = (dctbl), \
  compptr->ac_tbl_no = (actbl) )

  /* Safety check to ensure start_compress not called yet. */
  if (cinfo->global_state != CSTATE_START)
    ERREXIT1(cinfo, JERR_BAD_STATE, cinfo->global_state);

  /* For all colorspaces, we use Q and Huff tables 0 for luminance components,
   * tables 1 for chrominance components.
   */

  cinfo->jpeg_color_space = colorspace;

  cinfo->write_JFIF_header = TRUE; /* Write a JFIF marker */
  cinfo->num_components = 3;
  /* JFIF specifies component IDs 1,2,3 */
  /* We default to 2x2 subsamples of chrominance */

  //kik+
  //if(jpeg_sel == mjpeg||jpeg_sel == pjpeg) // voli PK_SW025 -
  //  if (jpeg_sel == mjpeg || jpeg_sel == pjpeg || jpeg_sel == pipjpeg)
  //  //voli PK_SW025 +
  //    SET_COMP(0, 1, 2, 2, 0, 0, 0);
  //  //mjpeg
  //  else
#ifdef JPEG_MB_VER
    SET_COMP(0, 1, 2, 2, 0, 0, 0);
#else
    SET_COMP(0, 1, 2, 1, 0, 0, 0);
#endif
  //kik041209+ //jpeg
  //kik+   
  SET_COMP(1, 2, 1, 1, 1, 1, 1);
  SET_COMP(2, 3, 1, 1, 1, 1, 1);


}
