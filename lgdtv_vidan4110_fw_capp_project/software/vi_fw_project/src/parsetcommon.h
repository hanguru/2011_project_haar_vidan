
/*!
 **************************************************************************************
 * \file
 *    parsetcommon.h
 * \brief
 *    Picture and Sequence Parameter Sets, structures common to encoder and decoder
 *    This code reflects JVT version xxx
 *  \date 25 November 2002
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details) 
 *      - Stephan Wenger        <stewe@cs.tu-berlin.de>
 ***************************************************************************************
 */

// In the JVT syntax, frequently flags are used that indicate the presence of
// certain pieces of information in the NALU.  Here, these flags are also
// present.  In the encoder, those bits indicate that the values signalled to
// be present are meaningful and that this part of the syntax should be
// written to the NALU.  In the decoder, the flag indicates that information
// was received from the decoded NALU and should be used henceforth.
// The structure names were chosen as indicated in the JVT syntax

#ifndef _PARSETCOMMON_H_
#define _PARSETCOMMON_H_

#define SIZEslice_group_id      (sizeof (int) * 60000)    // should be sufficient for HUGE pictures, need one int per MB in a picture

//! Boolean Type
typedef enum {
  FALSE,
  TRUE
} Boolean;

#define MAXnum_slice_groups_minus1  8

typedef struct
{
  unsigned  num_ref_idx_l0_active_minus1;                     // ue(v)
} pic_parameter_set_rbsp_t;


#define MAXnum_ref_frames_in_pic_order_cnt_cycle  256
typedef struct
{
  unsigned  pic_width_in_mbs_minus1;                          // ue(v)
  unsigned  pic_height_in_map_units_minus1;                   // ue(v)
} seq_parameter_set_rbsp_t;

pic_parameter_set_rbsp_t *AllocPPS (void);
seq_parameter_set_rbsp_t *AllocSPS (void);
void FreePPS (pic_parameter_set_rbsp_t *pps);
void FreeSPS (seq_parameter_set_rbsp_t *sps);

#endif
