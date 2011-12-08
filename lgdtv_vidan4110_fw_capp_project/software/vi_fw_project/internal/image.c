
/*!
 *************************************************************************************
 * \file image.c
 *
 * \brief
 *    Code one image/slice
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Inge Lille-Langøy               <inge.lille-langoy@telenor.com>
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
#include "time.h"
#include "haar_define.h"

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

int my_frame_num = 0;;

extern int matched_flag_debug;

extern void my_draw_rect(int x, int y, int width, int height, int color, int fill);
/*
{
    int frame_width = (ORC_CAM_SIZE & 0xffff);
    int frame_y_base = VIM_Y_BASE;

    int x_start = (x>>2)<<2;
    int x_end   = ((x+width-1)>>2)<<2;
    int y_start = y;
    int y_end   = y+height-1;

    int i,j;

    // top & bottom line
    for (j=x_start; j<= x_end ; j=j+4)
    {
        // top
        i = y_start;
        *( (int*)(frame_y_base + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;

        // bottom
        i = y_end;
        *( (int*)(frame_y_base + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;
    }

    // left & right line
    for (i=y_start; i<= y_end; i= i+1)
    {
        // left
        // the reason why adding 3 is the endian of ViDan is big.
        // (3, 2, 1, 0), (3, 2, 1, 0) ...
        j= x_start+3;
        *( (char*)(frame_y_base + i*frame_width + j ) ) = color;

        // right
        j= x_end;
        *( (char*)(frame_y_base + i*frame_width + j) ) = color;
    }
}
*/
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
   

    /////////////////////////////////////////
    //                                     //
    //         SDRAMC2 Write TEST          //
    //                                     //
    /////////////////////////////////////////
   
/*
    int i, j;
    for (i=0; i<9800; i++)
   	for (j=0; j<640; j++)
		*((volatile char*)(0xF0600000 + j)) = j;
*/
    //while(IMAGE_FRAME_CNT == 0);

//    if ( ( my_frame_num  %3 == 0 ) & ( VIM_Y_BASE == 0xf0000000) )
//        my_draw_rect( 0, (0+my_frame_num), 20, 20, 255, 0);
//    else if ( ( my_frame_num  %3 == 1 ) & ( VIM_Y_BASE == 0xf0200000) )
//        my_draw_rect( 0, (0+my_frame_num), 20, 20, 128, 0);
//    else if ( ( my_frame_num  %3 == 2 ) & ( VIM_Y_BASE == 0xf0400000) )
//        my_draw_rect( 0, (0+my_frame_num), 20, 20, 0, 0);

    // draw test code 
    //my_draw_rect( 0, (0+my_frame_num), 20, 20, 0, 0);
    //if ( my_frame_num > 640 ) my_frame_num = 0;
    //else my_frame_num ++;

    //if ( my_frame_num == 0 ) my_frame_num = 300;
    //if ( my_frame_num < 303 ) {
    //    my_draw_rect( 0, (0+my_frame_num), 20, 20, 0, 0);
    //    my_frame_num ++;
   // }


    /////////////////////////////////////////
    //                                     //
    //       Viola Jones Algorithm         //
    //                                     //
    /////////////////////////////////////////

		// for debugging test 
/*
		int src_frame_width = (ORC_CAM_SIZE & 0xffff);
		if ( my_frame_num%3 == 0 ) 
		{
			//if ( src_data == 0xF0000000 )
			if ( matched_flag_debug )
				haar_draw_rect (0xF0000000, src_frame_width, 50, 50, 50, 50, 255, 0);
			else 
				haar_draw_rect (0XF0000000, src_frame_width, 50, 50, 50, 50, 255, 1);
		}
		else if ( my_frame_num%3 == 1 ) 
		{
			matched_flag_debug = 1;
			if ( src_data == 0xF0200000 )
				haar_draw_rect (0xF0200000, src_frame_width, 100, 50, 50, 50, 255, 0);
			else {
				//haar_draw_rect (0xF0200000, src_frame_width, 100, 50, 50, 50, 255, 1);
			    if ( src_data == 0xF0000000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 100, 50, 50, 50, 255, 1);
			    else if ( src_data == 0xF0100000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 150, 100, 50, 50, 255, 1);
			    else if ( src_data == 0xF0300000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 200, 150, 50, 50, 255, 1);
			    else if ( src_data == 0xF0400000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 250, 200, 50, 50, 255, 1);
			    else if ( src_data == 0xF0500000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 300, 250, 50, 50, 255, 1);
			    else if ( src_data == 0xF0600000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 350, 300, 50, 50, 255, 1);
			    else if ( src_data == 0xF0700000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 400, 350, 50, 50, 255, 1);
			    else if ( src_data == 0xF0800000 )
    				haar_draw_rect ((0xF0200000), (ORC_CAM_SIZE & 0xffff), 450, 400, 50, 50, 255, 1);
			}
		}
		else if ( my_frame_num%3 == 2 ) 
		{
			//if ( src_data == 0xF0400000 )
			if ( matched_flag_debug )
				haar_draw_rect (0XF0400000, src_frame_width, 150, 50, 50, 50, 255, 0);
			else
				haar_draw_rect (0XF0400000, src_frame_width, 150, 50, 50, 50, 255, 1);
		}

*/



    //haar_draw_rect (VIM_Y_BASE, (ORC_CAM_SIZE & 0xffff), 0, 0, 50, 50, 255, 1);

    Haar_ViDan(img.width, img.height, VIM_Y_BASE, (ORC_CAM_SIZE & 0xffff), SRC_BASE + FRAME_OFFSET2);
    //Haar_ViDan(640, 110, VIM_Y_BASE, (ORC_CAM_SIZE & 0xffff), SRC_BASE + FRAME_OFFSET2);

    my_frame_num ++;



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
