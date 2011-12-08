
/*!
 *************************************************************************************
 * \file header.c
 *
 * \brief
 *    H.26L Slice and Sequence headers
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Stephan Wenger                  <stewe@cs.tu-berlin.de>
 *************************************************************************************
 */

//#include <assert.h>

#include "header.h"
#include "mbuffer.h"
#include "defines.h"
#include "vlc.h"
#include "parset.h"

static void ref_pic_list_reordering(void);
static void dec_ref_pic_marking(void);

/*!
 ********************************************************************************************
 * \brief 
 *    Write a slice header
 ********************************************************************************************
*/
int  SliceHeader(int first_mb_in_slice)
{

  //ue_v(img.current_mb_nr);
  ue_v(first_mb_in_slice);
  ue_v(get_picture_type ());
  ue_v(0);

  //assert (img.frame_num < 1<<(LOG2_MAX_FRAME_NUM_MINUS4+4));  // check that it fits
  u_v (LOG2_MAX_FRAME_NUM_MINUS4 + 4, img.frame_num);

//added by eskim as what jjs said for another decoder to decode result stream, such as JM11 and GOM player 
if(img.number == 0)
  ue_v (0);

  img.pic_order_cnt_lsb = (img.framepoc & 0xff);
  u_v (LOG2_MAX_PIC_ORDER_CNT_LSB_MINUS4+4, img.pic_order_cnt_lsb);

  // ist there any sense in the following assignments ???

  if (img.type == P_SLICE)
  {
    // num_ref_idx_active_override_flag here always 1
    u_1 (1);
    ue_v (img.num_ref_idx_l0_active-1);
  }

  ref_pic_list_reordering();
  
  if (img.nal_reference_idc) 
    dec_ref_pic_marking();
  

  // we transmit zero in the pps, so here the real QP
  se_v((img.qp - 26));

  if (input.LFSendParameters)
  {
    ue_v(input.LFDisableIdc);  // Turn loop filter on/off on slice basis 

    if (input.LFDisableIdc!=1)
    {
      se_v (input.LFAlphaC0Offset / 2);
      se_v (input.LFBetaOffset / 2);
    }
  }

  //MSG(SLICE_HEADER);
  return 0;
}

/*!
 ********************************************************************************************
 * \brief 
 *    writes the ref_pic_list_reordering syntax
 *    based on content of according fields in img structure
 *
 * \return
 *    number of bits used 
 ********************************************************************************************
*/
static void ref_pic_list_reordering()
{
  if ((img.type!=I_SLICE))
  {
    u_1 (0);
  }
}


/*!
 ************************************************************************
 * \brief
 *    write the memory menagement control operations
 ************************************************************************
 */
static void dec_ref_pic_marking()
{
//added by eskim as what jjs said for another decoder to decode result stream, such as JM11 and GOM player 
 if(img.number == 0)
  u_1(0);
  u_1(0);
}

  
/********************************************************************************************
 ********************************************************************************************
 *
 * Local Support Functions
 *
 ********************************************************************************************
 ********************************************************************************************/



// StW Note: This function is a hack.  It would be cleaner if the encoder maintains
// the picture type in the given format.  Note further that I have yet to understand
// why the encoder needs to know whether a picture is predicted from one or more
// reference pictures.

/*!
 ************************************************************************
 * \brief
 *    Selects picture type and codes it to symbol
 ************************************************************************
 */
int get_picture_type()
{
  switch (img.type)
  {
  case I_SLICE:
    return 7;
    break;
  case P_SLICE:
    return 5;
    break;
  default:
    //EXIT(0x1);
	return 0;
    break;
  }
   
  return 0;
}

void GenerateHeader(int nal_unit_type)
{
  //byte header;
  int header;
  int  forbidden_bit = 0;
  int  nal_reference_idc;
  
  //nal_reference_idc = NALU_PRIORITY_HIGHEST;

//added by eskim as what jjs said for another decoder to decode result stream, such as JM11 and GOM player 
//:begin
  nal_reference_idc = NALU_PRIORITY_HIGHEST;
/*  header = 
	  forbidden_bit << 7      |
	  nal_reference_idc << 5  |
	  nal_unit_type;*/
//modified by jjs @ 2007.09.28
 //if (img.number == 0) // idr_flag = 1
if (nal_unit_type == NALU_TYPE_IDR) // idr_flag = 0
{  
  if (img.number == 0)
  {
    header = 
    forbidden_bit << 7      |
    NALU_PRIORITY_HIGHEST << 5  |
    NALU_TYPE_IDR;
 //MSG(MSG_GenerateHeader);
 //MSGX(forbidden_bit);
 //MSGX(NALU_PRIORITY_HIGHEST);
 //MSGX(NALU_TYPE_IDR);
 //MSGX(header);
  }
  /*
  else if ( img.type == I_SLICE )
  {
    header = 
    forbidden_bit << 7      |
    NALU_PRIORITY_HIGHEST << 5  |
    NALU_TYPE_IDR;
  }
  */
  else
  { 
    header = 
    forbidden_bit << 7      |
    NALU_PRIORITY_HIGH << 5  |
    NALU_TYPE_SLICE;
 //MSG(MSG_GenerateHeader);
 //MSGX(forbidden_bit);
 //MSGX(NALU_PRIORITY_HIGH);
 //MSGX(NALU_TYPE_SLICE);
 //MSGX(header);
  }
}
else{// NALU_TYPE_SLICE;
   header =
    forbidden_bit << 7      |
    nal_reference_idc << 5  |
    nal_unit_type;
}
//:end

 //MSG(MSG_GenerateHeader);
 //MSGX(forbidden_bit);
 //MSGX(nal_reference_idc);
 //MSGX(nal_unit_type);
 //MSGX(header);

  OutputStreamController (0,8);
  OutputStreamController (0,8);
  OutputStreamController (0,8);
  OutputStreamController (1,8);
  OutputStreamController ((int)header, 8);
}

void bitstream_init(void)
{
  bits_to_go = 8;
}

void SODBtoRBSP(void)
{
	//MSGX((1<<(bits_to_go-1)));
	//MSGX(bits_to_go);
	//MSG(SODB_TO_RBSP);
	OutputStreamController((0x1<<(bits_to_go-1)),bits_to_go);
}

