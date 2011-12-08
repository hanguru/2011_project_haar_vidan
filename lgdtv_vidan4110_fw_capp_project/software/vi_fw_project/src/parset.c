
/*!
 **************************************************************************************
 * \file
 *    parset.c
 * \brief
 *    Picture and Sequence Parameter set generation and handling
 *  \date 25 November 2002
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details) 
 *      - Stephan Wenger        <stewe@cs.tu-berlin.de>
 *
 **************************************************************************************
 */

//#include <assert.h>
#include <stdio.h>

#include "global.h"
#include "parsetcommon.h"
#include "parset.h"
#include "vlc.h"

/*! 
 *************************************************************************************
 * \brief
 *    generates a sequence and picture parameter set and stores these in global
 *    active_sps and active_pps
 *
 * \param 
 *    None.
 *
 * \return
 *    A NALU containing the Sequence ParameterSet
 *
 *************************************************************************************
*/
void GenerateParameterSets ()
{
  active_sps = AllocSPS();
  active_pps = AllocPPS();

  FillParameterSetStructures (active_sps, active_pps);

  //MSG(GENERATE_PARAMETER_SETS);
}

/*! 
*************************************************************************************
* \brief
*    frees global parameter sets active_sps and active_pps
*
* \param 
*    None.
*
* \return
*    A NALU containing the Sequence ParameterSet
*
*************************************************************************************
*/
void FreeParameterSets ()
{
  FreeSPS (active_sps);
  FreePPS (active_pps);

  //MSG(FREE_PARAMETER_SETS);
}


/*!
 ************************************************************************
 * \brief
 *    FillParameterSetStructures: extracts info from global variables and
 *    generates a picture and sequence parameter set structure
 *
 * \par Input:
 *    seq_parameter_set_rbsp_t *sps,  Sequence parameter set to be filled
 *    pic_parameter_set_rbsp_t *pps   Picture parameter set to be filled
 * \par
 *    Function reads all kinds of values from several global variables,
 *    including input. and image-> and fills in the sps and pps.  Many
 *    values are current hard-coded to defaults, especially most of the
 *    VUI stuff.  Currently, the sps and pps structures are fixed length
 *    with the exception of the fully flexible FMO map (mode 6).  This
 *    mode is not supported.  Hence, the function does not need to
 *    allocate memory for the FMOmap, the pointer slice_group_id is
 *    always NULL.  If one wants to implement FMO mode 6, one would need
 *    to malloc the memory for the map here, and the caller would need
 *    to free it after use.
 *
 * \par 
 *    Limitations
 *    Currently, the encoder does not support multiple parameter sets,
 *    primarily because the config file does not support it.  Hence the
 *    pic_parameter_set_id and the seq_parameter_set_id are always zero.
 *    If one day multiple parameter sets are implemented, it would
 *    make sense to break this function into two, one for the picture and
 *    one for the sequence.
 *    Currently, FMO is not supported
 *    The following pps and sps elements seem not to be used in the encoder 
 *    or decoder and, hence, a guessed default value is conveyed:
 *
 *    pps->num_ref_idx_l0_active_minus1 = img.num_ref_pic_active_fwd_minus1;
 *    pps->num_ref_idx_l1_active_minus1 = img.num_ref_pic_active_bwd_minus1;
 *    pps->chroma_qp_index_offset = 0;
 *    sps->required_frame_num_update_behaviour_flag = FALSE;
 *    sps->direct_temporal_constrained_flag = FALSE;
 *
 * \par
 *    Regarding the QP
 *    The previous software versions coded the absolute QP only in the 
 *    slice header.  This is kept, and the offset in the PPS is coded 
 *    even if we could save bits by intelligently using this field.
 *
 ************************************************************************
 */

void FillParameterSetStructures (seq_parameter_set_rbsp_t *sps, 
                                 pic_parameter_set_rbsp_t *pps)
{
  // *************************************************************************
  // Sequence Parameter Set
  // *************************************************************************
  //assert (sps != NULL);
  //assert (pps != NULL);
  
  // Picture size, finally a simple one :-)
  sps->pic_width_in_mbs_minus1 = (input.img_width/16) -1;
  sps->pic_height_in_map_units_minus1 = (input.img_height/16) - 1;

  // *************************************************************************
  // Picture Parameter Set 
  // *************************************************************************

  pps->num_ref_idx_l0_active_minus1 = img.num_ref_idx_l0_active-1;   // check this
}



/*! 
 *************************************************************************************
 * \brief
 *    int GenerateSeq_parameter_set_rbsp (seq_parameter_set_rbsp_t *sps, char *rbsp);
 *
 * \param 
 *    sps:  sequence parameter structure
 *    rbsp:  buffer to be filled with the rbsp, size should be at least MAXIMUMPARSETRBSPSIZE
 *
 * \return
 *    size of the RBSP in bytes
 *
 * \note
 *    Sequence Parameter VUI function is called, but the function implements
 *    an exit (-1)
 *************************************************************************************
 */
 
void GenerateSeq_parameter_set_rbsp (seq_parameter_set_rbsp_t *sps)
{
  u_v  (8,PROFILE_IDC);							// PROFILE_IDC 88
//  u_1  (0);
//  u_1  (0);
//  u_1  (0);
//  u_v  (5,0);
  u_v  (8,0xe0);			
  u_v  (8,LEVEL_IDC);							// LEVEL_IDC 21
  ue_v (0);
  ue_v (LOG2_MAX_FRAME_NUM_MINUS4);				// LOG2_MAX_FRAME_NUM_MINUS4 4
  ue_v (0);
  ue_v (LOG2_MAX_PIC_ORDER_CNT_LSB_MINUS4);		// LOG2_MAX_PIC_ORDER_CNT_LSB_MINUS4 4
  ue_v (1);
  u_1  (0);
  ue_v (sps->pic_width_in_mbs_minus1);			// 10 @QCIF
  ue_v (sps->pic_height_in_map_units_minus1);	// 8 @QCIF
//  u_1  (1);
//  u_1  (0);
//  u_1  (0);
//  u_1  (0);
  u_v  (4,12);

  SODBtoRBSP ();     // copies the last couple of bits into the byte buffer
}


/*! 
 *************************************************************************************
 * \brief
 *    int GeneratePic_parameter_set_rbsp (pic_parameter_set_rbsp_t *sps, char *rbsp);
 *
 * \param 
 *    pps: sequence parameter structure
 *    rbsp:  buffer to be filled with the rbsp, size should be at least MAXIMUMPARSETRBSPSIZE
 *
 * \return
 *    size of the RBSP in bytes, negative in case of an error
 *
 * \note
 *    Picture Parameter VUI function is called, but the function implements
 *    an exit (-1)
 *************************************************************************************
 */
 
void GeneratePic_parameter_set_rbsp (pic_parameter_set_rbsp_t *pps)
{
  ue_v (0);
  ue_v (0);
//  u_1  (0);
//  u_1  (0);
  u_v  (2,0);
  ue_v (0);
  ue_v (0);//  ue_v (pps->num_ref_idx_l0_active_minus1);
  ue_v (-1);
  u_1  (0);
  u_v  (2,0);
  se_v (0);
  se_v (0);
  se_v (0);
  u_1  (input.LFSendParameters);
  u_1  (0);
  u_1  (0);

  SODBtoRBSP ();     // copies the last couple of bits into the byte buffer
}
