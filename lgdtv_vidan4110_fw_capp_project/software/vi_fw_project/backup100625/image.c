
/*!
 *************************************************************************************
 * \file image.c
 *
 * \brief
 *    Code one image/slice
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Inge Lille-Lang�y               <inge.lille-langoy@telenor.com>
 *     - Rickard Sjoberg                 <rickard.sjoberg@era.ericsson.se>
 *     - Jani Lainema                    <jani.lainema@nokia.com>
 *     - Sebastian Purreiter             <sebastian.purreiter@mch.siemens.de>
 *     - Byeong-Moon Jeon                <jeonbm@lge.com>
 *     - Yoon-Seong Soh                  <yunsung@lge.com>
 *     - Thomas Stockhammer              <stockhammer@ei.tum.de>
 *     - Detlev Marpe                    <marpe@hhi.de>
 *     - Guido Heising                   <heising@hhi.de>
 *     - Thomas Wedi                     <wedi@tnt.uni-hannover.de>
 *     - Ragip Kurceren                  <ragip.kurceren@nokia.com>
 *     - Antti Hallapuro                 <antti.hallapuro@nokia.com>
 *************************************************************************************
 */

#include <assert.h>

#include "global.h"
#include "image.h"
#include "mbuffer.h"
#include "header.h"
#include "memalloc.h"
#include "ratectl.h"
#include "map_hif.h"

//void code_a_picture(Picture *pic);
//void frame_picture (Picture *frame);
void frame_picture (void);

//static int  writeout_picture(Picture *pic);
static void init_frame(void);

//static int CalculateFrameNumber(void);  // Calculates the next frame number
//static int FrameNumberInFile;       // The current frame number in the input file

//StorablePicture *enc_picture;
//StorablePicture *enc_frame_picture;

extern int bits_per_frame;
//extern float CurrentFrameMAD;

/*!
 ************************************************************************
 * \brief
 *    Encodes a picture
 *
 *    This is the main picture coding loop.. It is called by all this
 *    frame and field coding stuff after the img. elements have been
 *    set up.  Not sure whether it is useful for MB-adaptive frame/field
 *    coding
 ************************************************************************
 */
//void init_offset()
//{
//	input_offset  = 0x0;
//	output_offset = 0x0;
//	
//	//MSG(INIT_OFFSET);
//}
//
/*!
 ************************************************************************
 * \brief
 *    Encodes a picture
 *
 *    This is the main picture coding loop.. It is called by all this
 *    frame and field coding stuff after the img. elements have been
 *    set up.  Not sure whether it is useful for MB-adaptive frame/field
 *    coding
 ************************************************************************
 */
 /*
void code_a_picture(Picture *pic)
{
  img.currentPicture = pic;

  // generate reference picture lists
  init_lists(img.type);

  img.num_ref_idx_l0_active = listXsize;

  // Encode the current slice
  encode_one_slice ();

  //MSG(CODE_A_PICTURE);
}
*/


/*!
 ************************************************************************
 * \brief
 *    Encodes one frame
 ************************************************************************
 */
void encode_one_frame ()
//int encode_one_frame ()
{
//MSG(Start_encode_one_frame);
//printf("Start_encode_one_frame\n");
  init_frame ();
  //FrameNumberInFile = CalculateFrameNumber();
//  FrameNumberInFile = IMG_NUMBER;
  
  /*printf("\n\n\n*********************************\n");
  printf("*         Frame #%02d             *\n", FrameNumberInFile);
  printf("*********************************\n");*/
  
  // Rate Control
  // initialize variables and get a new quantization parameter
  //if(input.RCEnable)
  //{
  //  rc_init_pict();
  //  if (img.number % 2  == 0 ) //jykim
  //  {
  //  	img.qp = updateQuantizationParameter();
  //  }
  //}
  //enable_slice_mode
  //writeout_picture (frame_pic);		// write IDR-TYPE NALU header
  frame_picture();
  //printf(">>>>> frame encoded <<<<<\n");

//  if (frame_pic)
//#ifdef OR1200
//    free_slice_list(frame_pic);
//#endif

  // Rate control
  // update quadratic model parameter.
    //if (input.RCEnable) {
    //        img.NumberofHeaderBits = FR_HEADER_BITS;
    //        img.NumberofTextureBits = FR_TEXTURE_BITS;

    //        rc_update_pict_frame(bits_per_frame);
    //        rc_update_pict(bits_per_frame);

    //        // update the parameters of quadratic R-D model
    //        if (img.type == P_SLICE)
    //                updateRCModel();

    //        //printf("img.qp = %d, %d bits/frame, MAD[%f]\n", img.qp, bits_per_frame, CurrentFrameMAD);
    //}


//  if (IMG_NUMBER == 0)
//    return 0;
//  else
//    return 1;
}


/*!
 ************************************************************************
 * \brief
 *    This function write out a picture
 * \return
 *    0 if OK,                                                         \n
 *    1 in case of error
 *
 ************************************************************************
 */
//static int writeout_picture(Picture *pic)
//{
//  GenerateHeader(NALU_TYPE_IDR); 
//
//  //MSG(WRITEOUT_PICTURE);
//
//  return 0;   
//}
//

/*!
 ************************************************************************
 * \brief
 *    Encodes a frame picture
 ************************************************************************
 */
//void frame_picture (Picture *frame)
void frame_picture (void)
{
  //MSG(FRAME_PICTURE_START);
  //to lencod.c  by chae
  //enc_frame_picture  = alloc_storable_picture (img.width, img.height, img.width_cr, img.height_cr);
  

//  enc_frame_picture->pic_num = img.frame_num;
  img.PicSizeInMbs = img.FrameSizeInMbs;

//  enc_picture=enc_frame_picture;

  //code_a_picture(frame); // to reduce function call 0709
  //img.currentPicture = frame;
  // to lencod.c by chae
  //free_storable_picture(enc_frame_picture);		// Jerry 20051013

   if (img.type == I_SLICE) img.num_ref_idx_l0_active = 0;
   else                     img.num_ref_idx_l0_active = 1;
   
  // Encode the current slice
   encode_one_slice ();
  //code_a_picture end
  
  //MSG(FRAME_PICTURE_END);
}



/*!
 ************************************************************************
 * \brief
 *    Initializes the parameters for a new frame
 ************************************************************************
 */
static void init_frame ()
{
  img.current_mb_nr = 0;
  //img.current_slice_nr = 0;

  img.mb_y = img.mb_x = 0;
  img.block_y = img.pix_y = 0; 
  img.block_x = img.pix_x = 0;

  //img.tr = IMG_NUMBER * (input.jumpd + 1);
  //img.mb_y_intra = img.mb_y_upd;  //  img.mb_y_intra indicates which GOB to intra code for this frame
  
  // Rate Control
  // in the case of rate control disabled, qp is constant depending on the image type.

  if(!input.RCEnable)
  {
    if (img.type == I_SLICE)
      img.qp = input.qp0;   // set quant. parameter for I-frame
    else
      img.qp = input.qpN;
  }

  img.total_number_mb = (img.width * img.height) / (MB_BLOCK_SIZE * MB_BLOCK_SIZE);
//  added by chae : setting before VIM to ME 2006.11.14

      // hjlee 10.06.12 (begin)
      if(img.type==P_SLICE && img.number%fake_intra_period==(fake_intra_period-1)) {
            input.slice_mode = 1;
    //kik_fw++
          if(H264_RESOLUTION == H264_VGA){ 
            input.slice_argument = 40;
          }
          else if(H264_RESOLUTION == H264_QVGA){
            input.slice_argument = 20;
          }
      }
      else if(img.type==P_SLICE && img.number%fake_intra_period==0) {
            input.slice_mode = 1;
    //kik_fw++
          if(H264_RESOLUTION == H264_VGA){ 
            input.slice_argument = 40;
          }
          else if(H264_RESOLUTION == H264_QVGA){
            input.slice_argument = 20;
          }
      }
      else if(img.type==P_SLICE && img.number%fake_intra_period==1) {
            input.slice_mode = 1;
    //kik_fw++
          if(H264_RESOLUTION == H264_VGA){ 
            input.slice_argument = 40;
          }
          else if(H264_RESOLUTION == H264_QVGA){
            input.slice_argument = 20;
          }
   } else {
         input.slice_mode = 0;
 //kik_fw++
       if(H264_RESOLUTION == H264_VGA){ 
         input.slice_argument = 1200;
       }
       else if(H264_RESOLUTION == H264_QVGA){
         input.slice_argument = 300;
       }
   }
  // hjlee 10.06.12 (end)

  ME_CR0 = (img.height << 16) | img.width;
  ME_CR1 = (img.type==P_SLICE) ? 0x0 : 0x1;
  ME_CR2 = img.qp;
  if( input.slice_mode == 1 ) VLC_SLICE_ARGUMENT = input.slice_argument;
  else                        VLC_SLICE_ARGUMENT = img.total_number_mb + 1; 

  //MSG(INIT_FRAME);
}


/*!
 ************************************************************************
 * \brief
 *    Calculates the absolute frame number in the source file out
 *    of various variables in img. and input.
 * \return
 *    frame number in the file to be read
 * \side effects
 *    global variable frame_no updated -- dunno, for what this one is necessary
 ************************************************************************
 */
 /*
static int CalculateFrameNumber()
{
  frame_no = IMG_NUMBER * (input.jumpd + 1);

  MSG(CALCULATE_FRAME_NR);
  return frame_no;
}
*/
