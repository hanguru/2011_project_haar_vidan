/*
 * jcmarker.c
 *
 * Copyright (C) 1991-1998, Thomas G. Lane.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file contains routines to write JPEG datastream markers.
 */

#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "map.h"  //JSY+
#include "./jpeg_global.h" //bmy 04.12.21 jpeg_enc_opt +

#define NULL 0

typedef enum
{
   /* JPEG marker codes */
  M_SOF0 = 0xc0, M_SOF1 = 0xc1, M_SOF2 = 0xc2, M_SOF3 = 0xc3, 

  M_SOF5 = 0xc5, M_SOF6 = 0xc6, M_SOF7 = 0xc7, 

  M_JPG = 0xc8, M_SOF9 = 0xc9, M_SOF10 = 0xca, M_SOF11 = 0xcb, 

  M_SOF13 = 0xcd, M_SOF14 = 0xce, M_SOF15 = 0xcf, 

  M_DHT = 0xc4, 

  M_DAC = 0xcc, 

  M_RST0 = 0xd0, M_RST1 = 0xd1, M_RST2 = 0xd2, M_RST3 = 0xd3, M_RST4 = 0xd4,
    M_RST5 = 0xd5, M_RST6 = 0xd6, M_RST7 = 0xd7, 

  M_SOI = 0xd8, M_EOI = 0xd9, M_SOS = 0xda, M_DQT = 0xdb, M_DNL = 0xdc, M_DRI =
    0xdd, M_DHP = 0xde, M_EXP = 0xdf, 

  M_APP0 = 0xe0, M_APP1 = 0xe1, M_APP2 = 0xe2, M_APP3 = 0xe3, M_APP4 = 0xe4,
    M_APP5 = 0xe5, M_APP6 = 0xe6, M_APP7 = 0xe7, M_APP8 = 0xe8, M_APP9 = 0xe9,
    M_APP10 = 0xea, M_APP11 = 0xeb, M_APP12 = 0xec, M_APP13 = 0xed, M_APP14 =
    0xee, M_APP15 = 0xef, 

  M_JPG0 = 0xf0, M_JPG13 = 0xfd, M_COM = 0xfe, 

  M_TEM = 0x01, 

  M_ERROR = 0x100
} JPEG_MARKER;


/* Private state */

//typedef struct {
// struct jpeg_marker_writer pub; /* public fields */

//  unsigned int last_restart_interval; /* last DRI value emitted; 0 after SOI */
//} my_marker_writer;

//typedef my_marker_writer * my_marker_ptr;


/*
 * Basic output routines.
 *
 * Note that we do not support suspension while writing a marker.
 * Therefore, an application using suspension must ensure that there is
 * enough buffer space for the initial markers (typ. 600-700 bytes) before
 * calling jpeg_start_compress, and enough space to write the trailing EOI
 * (a few bytes) before calling jpeg_finish_compress.  Multipass compression
 * modes are not supported at all with suspension, so those two are the only
 * points where markers will be written.
 */

LOCAL(void)emit_byte(j_compress_ptr cinfo, int val)
/* Emit a byte */
{
  //JSY-+
  //struct jpeg_destination_mgr * dest = cinfo->dest;

  //*(dest->next_output_byte)++ = (JOCTET) val;
  //if (--dest->free_in_buffer == 0) {
  //  if (! empty_output_buffer (cinfo))
  //    ERREXIT(cinfo, JERR_CANT_SUSPEND);
  //}
  //*JPEG_OUT = val;
  *OS_BUF = val;
}


LOCAL(void)emit_marker(j_compress_ptr cinfo, JPEG_MARKER mark)
/* Emit a marker code */
{
  emit_byte(cinfo, 0xFF);
  emit_byte(cinfo, (int)mark);
}


LOCAL(void)emit_2bytes(j_compress_ptr cinfo, int value)
/* Emit a 2-byte integer; these are always MSB first in JPEG files */
{
  emit_byte(cinfo, (value >> 8) &0xFF);
  emit_byte(cinfo, value &0xFF);
}


/*
 * Routines to write specific marker types.
 */

LOCAL(int)emit_dqt(j_compress_ptr cinfo, int index)
/* Emit a DQT marker */
/* Returns the precision used (0 = 8bits, 1 = 16bits) for baseline checking */
{
  JQUANT_TBL *qtbl = cinfo->quant_tbl_ptrs[index];
  int prec;
  int i;

  //if (qtbl == NULL)
  //  ERREXIT1(cinfo, JERR_NO_QUANT_TABLE, index);

  prec = 0;
  for (i = 0; i < DCTSIZE2; i++)
  {
    if (qtbl->quantval[i] > 255)
      prec = 1;
  }

  if (!qtbl->sent_table)
  {
    emit_marker(cinfo, M_DQT);

    emit_2bytes(cinfo, prec ? DCTSIZE2 *2+1+2: DCTSIZE2 + 1+2);

    emit_byte(cinfo, index + (prec << 4));

    for (i = 0; i < DCTSIZE2; i++)
    {
      /* The table entries must be emitted in zigzag order. */
      unsigned int qval = qtbl->quantval[(int)jpeg_natural_order[i]];
      if (prec)
        emit_byte(cinfo, (int)(qval >> 8));
      emit_byte(cinfo, (int)(qval &0xFF));
    }

    qtbl->sent_table = TRUE;
  }

  return prec;
}


LOCAL(void)emit_dht(j_compress_ptr cinfo, int index, boolean is_ac)
/* Emit a DHT marker */
{
  JHUFF_TBL *htbl;
  int length, i;

  if (is_ac)
  {
    htbl = cinfo->ac_huff_tbl_ptrs[index];
    index += 0x10; /* output index has AC bit set */
  }
  else
  {
    htbl = cinfo->dc_huff_tbl_ptrs[index];
  }

  if (htbl == NULL)
    ERREXIT1(cinfo, JERR_NO_HUFF_TABLE, index);

  if (!htbl->sent_table)
  {
    emit_marker(cinfo, M_DHT);

    length = 0;
    for (i = 1; i <= 16; i++)
      length += htbl->bits[i];

    emit_2bytes(cinfo, length + 2+1+16);
    emit_byte(cinfo, index);

    for (i = 1; i <= 16; i++)
      emit_byte(cinfo, htbl->bits[i]);

    for (i = 0; i < length; i++)
      emit_byte(cinfo, htbl->huffval[i]);

    htbl->sent_table = TRUE;
  }
}




LOCAL(void)emit_sof(j_compress_ptr cinfo, JPEG_MARKER code)
/* Emit a SOF marker */
{
  int ci;
  jpeg_component_info *compptr;

  emit_marker(cinfo, code);

  emit_2bytes(cinfo, 3 *cinfo->num_components + 2+5+1); /* length */

  /* Make sure image isn't bigger than SOF field can handle */
  //if ((long) cinfo->image_height > 65535L ||
  //    (long) cinfo->image_width > 65535L)
  //  ERREXIT1(cinfo, JERR_IMAGE_TOO_BIG, (unsigned int) 65535);

  emit_byte(cinfo, 8);

  //kik -- MJPEG and jpeg have same height.
  emit_2bytes(cinfo, (int)cinfo->image_height);

  emit_2bytes(cinfo, (int)cinfo->image_width);

  emit_byte(cinfo, cinfo->num_components);

  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++,
    compptr++)
  {
    emit_byte(cinfo, compptr->component_id);
    emit_byte(cinfo, (compptr->h_samp_factor << 4) + compptr->v_samp_factor);
    emit_byte(cinfo, compptr->quant_tbl_no);
  }
}


LOCAL(void)emit_sos(j_compress_ptr cinfo)
/* Emit a SOS marker */
{
  int i, td, ta;
  jpeg_component_info *compptr;

  emit_marker(cinfo, M_SOS);

  emit_2bytes(cinfo, 2 *cinfo->comps_in_scan + 2+1+3); /* length */

  emit_byte(cinfo, cinfo->comps_in_scan);

  for (i = 0; i < cinfo->comps_in_scan; i++)
  {
    compptr = cinfo->cur_comp_info[i];
    emit_byte(cinfo, compptr->component_id);
    td = compptr->dc_tbl_no;
    ta = compptr->ac_tbl_no;

    emit_byte(cinfo, (td << 4) + ta);
  }

  emit_byte(cinfo, 0);
  emit_byte(cinfo, (DCTSIZE2 - 1));
  emit_byte(cinfo, 0);
}


LOCAL(void)emit_jfif_app0(j_compress_ptr cinfo)
/* Emit a JFIF-compliant APP0 marker */
{
  /*
   * Length of APP0 block	(2 bytes)
   * Block ID			(4 bytes - ASCII "JFIF")
   * Zero byte			(1 byte to terminate the ID string)
   * Version Major, Minor	(2 bytes - major first)
   * Units			(1 byte - 0x00 = none, 0x01 = inch, 0x02 = cm)
   * Xdpu			(2 bytes - dots per unit horizontal)
   * Ydpu			(2 bytes - dots per unit vertical)
   * Thumbnail X size		(1 byte)
   * Thumbnail Y size		(1 byte)
   */

  emit_marker(cinfo, M_APP0);

  emit_2bytes(cinfo, 2+4+1+2+1+2+2+1+1); /* length */

  emit_byte(cinfo, 0x4A); /* Identifier: ASCII "JFIF" */
  emit_byte(cinfo, 0x46);
  emit_byte(cinfo, 0x49);
  emit_byte(cinfo, 0x46);
  emit_byte(cinfo, 0);
  emit_byte(cinfo, cinfo->JFIF_major_version); /* Version fields */
  emit_byte(cinfo, cinfo->JFIF_minor_version);
  emit_byte(cinfo, cinfo->density_unit); /* Pixel size information */
  emit_2bytes(cinfo, (int)cinfo->X_density);
  emit_2bytes(cinfo, (int)cinfo->Y_density);
  emit_byte(cinfo, 0); /* No thumbnail image */
  emit_byte(cinfo, 0);
}


#ifndef JPEG_ENC_OPT  //bmy 04.12.21 jpeg_enc_opt + : below
  /*
   * These routines allow writing an arbitrary marker with parameters.
   * The only intended use is to emit COM or APPn markers after calling
   * write_file_header and before calling write_frame_header.
   * Other uses are not guaranteed to produce desirable results.
   * Counting the parameter bytes properly is the caller's responsibility.
   */

  GLOBAL(void)write_marker_header(j_compress_ptr cinfo, int marker, unsigned
    int datalen)
  /* Emit an arbitrary marker header */
  {
    if (datalen > (unsigned int)65533)
     /* safety check */
      ERREXIT(cinfo, JERR_BAD_LENGTH);

    emit_marker(cinfo, (JPEG_MARKER)marker);

    emit_2bytes(cinfo, (int)(datalen + 2)); /* total length */
  }

  GLOBAL(void)write_marker_byte(j_compress_ptr cinfo, int val)
  /* Emit one byte of marker parameters following write_marker_header */
  {
    emit_byte(cinfo, val);
  }
#endif //bmy 04.12.21 jpeg_enc_opt + : up


/*
 * Write datastream header.
 * This consists of an SOI and optional APPn markers.
 * We recommend use of the JFIF marker, but not the Adobe marker,
 * when using YCbCr or grayscale data.  The JFIF marker should NOT
 * be used for any other JPEG colorspace.  The Adobe marker is helpful
 * to distinguish RGB, CMYK, and YCCK colorspaces.
 * Note that an application can write additional header markers after
 * jpeg_start_compress returns.
 */

GLOBAL(void)write_file_header(j_compress_ptr cinfo)
{
  //  my_marker_ptr marker = (my_marker_ptr) cinfo->marker;

  emit_marker(cinfo, M_SOI); /* first the SOI */

  /* SOI is defined to reset restart interval to 0 */
  //  marker->last_restart_interval = 0;

  if (cinfo->write_JFIF_header)
   /* next an optional JFIF APP0 */
    emit_jfif_app0(cinfo);


}


/*
 * Write frame header.
 * This consists of DQT and SOFn markers.
 * Note that we do not emit the SOF until we have emitted the DQT(s).
 * This avoids compatibility problems with incorrect implementations that
 * try to error-check the quant table numbers as soon as they see the SOF.
 */

GLOBAL(void)write_frame_header(j_compress_ptr cinfo)
{
  int ci, prec;
  //boolean is_baseline; //JSY-
  jpeg_component_info *compptr;

  /* Emit DQT for each quantization table.
   * Note that emit_dqt() suppresses any duplicate tables.
   */
  prec = 0;
  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++,
    compptr++)
  {
    prec += emit_dqt(cinfo, compptr->quant_tbl_no);
  }
  /* now prec is nonzero iff there are any 16-bit quant tables. */

  /* Check for a non-baseline specification.
   * Note we assume that Huffman table numbers won't be changed later.
   */

  /* Emit the proper SOF marker */
  {

    //if (is_baseline)  //JSY-
    emit_sof(cinfo, M_SOF0); /* SOF code for baseline implementation */

  }
}


/*
 * Write scan header.
 * This consists of DHT or DAC markers, optional DRI, and SOS.
 * Compressed data will be written following the SOS.
 */

GLOBAL(void)write_scan_header(j_compress_ptr cinfo)
{

  int i;
  jpeg_component_info *compptr;
  {
    /* Emit Huffman tables.
     * Note that emit_dht() suppresses any duplicate tables.
     */
    for (i = 0; i < cinfo->comps_in_scan; i++)
    {
      compptr = cinfo->cur_comp_info[i];
      {
        /* Sequential mode: need both DC and AC tables */
        emit_dht(cinfo, compptr->dc_tbl_no, FALSE);
        emit_dht(cinfo, compptr->ac_tbl_no, TRUE);
      }
    }
  }

  /* Emit DRI if required --- note that DRI value could change for each scan.
   * We avoid wasting space with unnecessary DRIs, however.
   */


  emit_sos(cinfo);
}


#ifndef JPEG_ENC_OPT  //bmy 04.12.21 jpeg_enc_opt + : below
  /*
   * Write datastream trailer.
   */

  GLOBAL(void)write_file_trailer(j_compress_ptr cinfo)
  {
    emit_marker(cinfo, M_EOI);
  }
#endif //bmy 04.12.21 jpeg_enc_opt + : up
