
/*!
 **************************************************************************************
 * \file
 *    slice.
 * \brief
 *    generate the slice header, setup the bit buffer for slices,
 *    and generates the slice NALU(s)

 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Thomas Stockhammer            <stockhammer@ei.tum.de>
 *      - Detlev Marpe                  <marpe@hhi.de>
 *      - Stephan Wenger                <stewe@cs.tu-berlin.de>
 ***************************************************************************************
 */

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "global.h"
#include "header.h"
#include "parset.h"
#include "vlc.h"
#include "image.h"
#include "mb_access.h"
//#include "dma.h"
#include "map_hif.h"
#include "jpeg.h"

#include "configfile.h" //jykim_20080715_HIF_CONV++

#include "tube.h"
#include "commandProcess.h" //usb.h

//! Local declarations
void simpleLineRateControl(int mby, int img_height_in_mb); //chae 2010.06.17
extern int target_one_frame_size_byte; // chae 2010.06.17

static void  free_slice(Slice *slice);

extern int img_sel;
extern int bits_per_frame;
extern int jpeg_length_array[5]; //090507_jarre_dvp2 + 
//extern int jpeg_length_array[4]; //090408_jykim_mux+

int end_of_slice;
int end_of_last_slice;
int slice_no;
int qp_delta; //chae 2010.06.17

extern int my_frame_num;

//kik_fw+
///////////////////////////////////////////////////////////
int random_temp[5] = {0};
///////////////////////////////////////////////////////////

//kik_fw extern int jpeg_mot_enable;
//kik_fw extern int jpeg_start;
//kik_fw 
//kik_fw extern int ori_me_dma_y_base;
//kik_fw extern int ori_me_dma_u_base;
//kik_fw extern int ori_me_dma_v_base;
/*!
 ************************************************************************
 *  \brief
 *     This function generates the slice (and partition) header(s) 
 ************************************************************************
*/
int NAL_BIT_SIZE = 0;
void  start_slice(int first_mb_in_slice)
{
  GenerateHeader(NALU_TYPE_IDR); 
  SliceHeader (first_mb_in_slice);
     
//  CAVLC_init();
//  added by chae : setting before VIM to ME 2006.11.14
  ME_CR0 = (img.height << 16) | img.width;
  ME_CR1 = (img.type==P_SLICE) ? 0x0 : 0x1;
  ME_CR2 = img.qp;

  end_of_slice = 0;
  end_of_last_slice = 0;


  //MSGX(first_mb_in_slice);
  //MSG(START_SLICE);

}

int compute_slice_argument(int bitrate, int type)
{
  float frame_bit;
  int  i_frame_bit;
  float f_no_intra ;
  float i_no_intra ;
  
    f_no_intra = RATE_CONTROL_FRAME_RATE/INTRA_PERIOD + 1;
    i_no_intra = f_no_intra; 

  // Iframe
  if (type == 0) {

     float total = RATE_CONTROL_FRAME_RATE + 5 * i_no_intra;  
     frame_bit = (float) bitrate * 8.0/total; 
  } 
  else {
  
     float total = RATE_CONTROL_FRAME_RATE + 2 * i_no_intra;  
     frame_bit = (float) bitrate  * 4.0/total; 

  }

  i_frame_bit = frame_bit;

 return  frame_bit/(NAL_BIT_SIZE) +1 ; 
}


/*!
 ************************************************************************
 * \brief
 *    Encodes one slice
 * \para
 *   returns the number of coded MBs in the SLice 
 ************************************************************************
 */
void encode_one_slice (void)
{
  int i,j,j2,k,l;
  int total_mb_nr = img.total_number_mb;
  int img_width_in_mb,img_height_in_mb;
//kik_fw+
/////////////////////////////////////////////////////////
int mb_sub_groups = 0, intra_mb_lines = 0, select_num = 0;
extern int tmp_y, tmp_u, tmp_v;
/////////////////////////////////////////////////////////


  // Rate Control
//  int vlc_sr, vlc_len;  // get encoded size from VLC register
//  int mb_mode;
//  int nTotMB = 0, nIntraMB = 0;
// -- try
  int mbx, mby, sbx, sby;
//  int vim_start_flag = 0;
//  int dma_dctq_flag = 0;
//  int mb_avail;
//  int mb_avail_up;
//  int mb_avail_left;
//  int cod_counter_in;
//--
// int temp_mb_x = 0;
	volatile int temp;
  int intentional_islice=0; //2010.06.04
  int intra_line_prev = 0;  //2010.06.04
  int intra_line_curr = 0;  //2010.06.04
  int ref_frame_base_temp;  //2010.06.04

  int acc_length;
  int img_type = (img.type == P_SLICE) ? 1:0;

	//090408_jykim_mux_head+ 
  int osb_fifo_i = 0;
  int osb_fifo_filled_num = 0;
  OS_CPU_SR cpu_sr = 0;

	//090408_jykim_mux_tail+ 
  img.cod_counter = 0;	//<! Current count of number of skipped macroblocks in a row
  img_width_in_mb = img.width >> 4; // how many MB in a row
  img_height_in_mb = img.height >> 4; // how many MB in a row

  // Rate Control
  bits_per_frame = 0;

  //init_slice();
  slice_no = 0;
  
  start_slice (0);
  //SliceFirstMB  = (0 <<16) | 0;


  ME_CHIPSCOPE = 21; // This line is test to check whether configuration is working or not
  // Set Margin M0 to 16 and 2 for early termination of 16x16 and 4x4 intra prediction, respectively
//  EarlyTerm_Control = 0xC0100002;
    EarlyTerm_Control = 0x00100002;
// skip_mode_en [4], FastQME [3], FastHME [2], skip_qme_en [1], skip_hme [0]
// fast_fme_option[18:16] : 5(32/32),4(24/32),3(16/32),2(12/32),1(8/32)
// fast_fme_mode[21:20]   : 0,1(16x16),2(16x8/8x16),3(16x16/16x8/8x16)
// speed_control_mode[31] : 1 ( speed control algorithm ON) 
//    ME_FAST_FME_CONTROL = 0x00000010; // FastQME and FastHME are disabled, other options are disabled
    ME_FAST_FME_CONTROL = 0x0031001C; //2010.05.28  FastFME

 // janghack modified encoding loop (2008.05.09)
  i=0;
  j=0;
  j2=0;
  k=0;
  l=0;
//  mb_avail_up       =  (img.mb_y==0)?0:1;
//  mb_avail_left     =  (img.mb_x==0)?0:1;

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /* janghack : encoding loop 2008.5.11 (Pipelined firmware structure)
  
  Pipelined firmware scheduling :
  	----------------------------> Time
	 mbx = -1		0				1				2			3				...
    I SLICE PIPELINING ( bits_to_go is software loop )
  	 STAGE I	STAGE II		STAGEIII		STAGE IV		STAGE V			STAGE VI  		STAGE VII
	 -------------------------------------------------------------------------------------------------------
	 VIM0		VIM1			VIM2			VIM3
	 			DCTQ0			DCTQ1			DCTQ2			DCTQ3
	 							ADF0			ADF1			ADF2			ADF3
	 							VLC0			VLC1			VLC2 			VLC3
												bits_to_go0		bits_to_go1		bits_to_go2		bits_to_go3

	 P SLICE PIPELINING ( INT = interpolation, and bits_to_go is software loop )
	 STAGE I	STAGE II		STAGEIII		STAGE IV		STAGE V			STAGE VI 		STAGE VII 		STAGEVIII
	 -----------------------------------------------------------------------------------------------------------------------
	 VIM0		VIM1			VIM2			VIM3
				 REF  IME0		REF  IME1		REF  IME2		REF  IME3
				 INT0			INT1			INT2			INT3							
				 					 FME+MC0		 FME+MC1		 FME+MC2	FME_MC3
				 				DCTQ0			DCTQ1			DCTQ2			DCTQ3
				 								ADF0			ADF1			ADF2			ADF3
				 								VLC0			VLC1			VLC2 			VLC3
																bits_to_go0		bits_to_go1		bits_to_go2		bits_to_go3
  Important Note :
  1. Several instruction should be located between ME_CR3 and ME_CR10.
  	-- After ME_CR3 setting, ME prepares some data for about 9 cycles. 
		hardware stream will be different from reference stream if ME_CR10 is asserted before this preparation

  2. ADF_START must be asserted before DCTQ_CR1(IPDCTQ start)
  	-- Reconstruction buffer switching may not work correctly if this rule is violated
  
  3. VLC_START must be asserted before DCTQ_CR1
  	-- Result of DCTQ in the previous pipeline stage should be latched before current DCTQ

  4. DCTQ_CR1(IPDCTQ start) must be asserted before ME_CR10 (ME start)
    -- If ME_CR10 is asserted before DCTQ_CR1, inter DCTQ may be requested while intra DCTQ time
		DCTQ can not perform both inter and intra DCTQ at the same time
  
  So, keep below starting sequence  
  		ADF or VLC --> DCTQ --> ME 
  */
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 
//kik_fw
//select resolution of image  
         if ( H264_RESOLUTION == H264_VGA)
             {
             mb_sub_groups  = 6;
             intra_mb_lines = 5;
             }
         else if( H264_RESOLUTION == H264_QVGA)
             {
             mb_sub_groups  = 3;
             intra_mb_lines = 5;
             }

 //random number generation for now frame intra mode lines => 1line
      if(img.type==P_SLICE && img.number%fake_intra_period==0 && img.number!=1 )
      {
       if(H264_RESOLUTION == H264_VGA)
       {
          if((img.number/fake_intra_period)%mb_sub_groups == 0){
            random_temp[0] = 0; random_temp[1] = 6; random_temp[2] = 12; random_temp[3] = 18; random_temp[4] = 24;
          }
          else if((img.number/fake_intra_period)%mb_sub_groups == 2){
            random_temp[0] = 1; random_temp[1] = 7; random_temp[2] = 13; random_temp[3] = 19; random_temp[4] = 25;
          }
          else if((img.number/fake_intra_period)%mb_sub_groups == 4){
            random_temp[0] = 2; random_temp[1] = 8; random_temp[2] = 14; random_temp[3] = 20; random_temp[4] = 26;
          }
          else if((img.number/fake_intra_period)%mb_sub_groups == 5){
            random_temp[0] = 3; random_temp[1] = 9; random_temp[2] = 15; random_temp[3] = 21; random_temp[4] = 27;
          }
          else if((img.number/fake_intra_period)%mb_sub_groups == 3){
            random_temp[0] = 4; random_temp[1] = 10; random_temp[2] = 16; random_temp[3] = 22; random_temp[4] = 28;
          }
          else if((img.number/fake_intra_period)%mb_sub_groups == 1){
            random_temp[0] = 5; random_temp[1] = 11; random_temp[2] = 17; random_temp[3] = 23; random_temp[4] = 29;
          }
       }
       else if( H264_RESOLUTION == H264_QVGA)
       {
          if((img.number/fake_intra_period)%mb_sub_groups == 1){
            random_temp[0] = 0; random_temp[1] = 3; random_temp[2] = 6; random_temp[3] = 9; random_temp[4] = 12;
          }
          else if((img.number/fake_intra_period)%mb_sub_groups == 0){
            random_temp[0] = 1; random_temp[1] = 4; random_temp[2] = 7; random_temp[3] = 10; random_temp[4] = 13;
          }
          else if((img.number/fake_intra_period)%mb_sub_groups == 2){
            random_temp[0] = 2; random_temp[1] = 5; random_temp[2] = 8; random_temp[3] = 11; random_temp[4] = 14;
          }

       }
      }

//    if ( ( my_frame_num  %3 == 0 ) & ( VIM_Y_BASE == 0xf0000000) )
//        my_draw_rect( 0, (0+my_frame_num), 20, 20, 255, 0);
//    else if ( ( my_frame_num  %3 == 1 ) & ( VIM_Y_BASE == 0xf0200000) )
//        my_draw_rect( 0, (0+my_frame_num), 20, 20, 128, 0);
//    else if ( ( my_frame_num  %3 == 2 ) & ( VIM_Y_BASE == 0xf0400000) )
//        my_draw_rect( 0, (0+my_frame_num), 20, 20, 0, 0);


//   if ( my_frame_num > 640 ) my_frame_num = 0;
//   else my_frame_num ++;

///////////////////////////////////////////////////////// 

  img.prev_qp=img.qp;	// chae 2010.06.17
  for(mby=0; mby<img_height_in_mb; mby++)
  {

    //2010.06.04 begin
    if(img.type==P_SLICE && img.number%fake_intra_period==0){
          img_type = 0; //2010.06.01
          intentional_islice = 1;
     }
     else
     {
          img_type = (img.type == P_SLICE) ? 1:0;
          intentional_islice = 0;
     }

     if(img.type==P_SLICE &&
        img.number%fake_intra_period==(fake_intra_period-1) &&
        ((mby/intra_mb_lines)==(((img.number/fake_intra_period)-1)%mb_sub_groups)) && img.number!=1)intra_line_prev = 1;//intra
     else                                                                                          intra_line_prev = 0; //skip
//kik_fw-      if(img.type==P_SLICE &&
//kik_fw-         img.number%fake_intra_period==0 &&
//kik_fw-         ((mby/intra_mb_lines)==(((img.number/fake_intra_period)-1)%mb_sub_groups)) && img.number!=1) intra_line_curr = 1; //intra
//kik_fw-      else                                                                                           intra_line_curr = 0; //skip
//kik_fw- 
//kik_fw-      if(img.type==P_SLICE &&
//kik_fw-         img.number%fake_intra_period==1 ){
//kik_fw-        if(((mby/intra_mb_lines)!=((((img.number-1)/fake_intra_period)-1)%mb_sub_groups)) && img.number>1){
//kik_fw-         ref_frame_base_temp  = JPEG_STREAM_BASE2;          //temp
//kik_fw-         ME_DMA_Y_BASE = ref_frame_base_temp;
//kik_fw-         ME_DMA_U_BASE = ref_frame_base_temp + cam_cb_offset_aligned_temp;
//kik_fw-         ME_DMA_V_BASE = ref_frame_base_temp + cam_cr_offset_aligned_temp;
//kik_fw-         }
//kik_fw-        else if(((mby/intra_mb_lines)==((((img.number-1)/fake_intra_period)-1)%mb_sub_groups)) && img.number>1){
//kik_fw-         ME_DMA_Y_BASE = tmp_y; 
//kik_fw-         ME_DMA_U_BASE = tmp_u; 
//kik_fw-         ME_DMA_V_BASE = tmp_v; 
//kik_fw-         }
//kik_fw-      }

////////////////////////////////////////////////////////////////
     //select 5 lines in intra mode
     if(mby == random_temp[0] || mby == random_temp[1] || mby == random_temp[2] || mby == random_temp[3] || mby == random_temp[4])
       select_num = 1;
     else
       select_num = 0;

     //now frame
     if(img.type==P_SLICE && img.number%fake_intra_period==0 && img.number!=1 && select_num == 1) //intra mode
      intra_line_curr = 1;
     else //skip
      intra_line_curr = 0;


     //next frame
     if(img.type==P_SLICE && img.number%fake_intra_period==1 && img.number!=1 ) //skip mode
      {
        if(select_num == 0)
          {
             ref_frame_base_temp  = JPEG_STREAM_BASE2;          //temp
             ME_DMA_Y_BASE = ref_frame_base_temp;
             ME_DMA_U_BASE = ref_frame_base_temp + cam_cb_offset_aligned_temp;
             ME_DMA_V_BASE = ref_frame_base_temp + cam_cr_offset_aligned_temp;
          }
        else
          {
             ME_DMA_Y_BASE = tmp_y;
             ME_DMA_U_BASE = tmp_u;
             ME_DMA_V_BASE = tmp_v;
          }
      }

////////////////////////////////////////////////////////////////


    //2010.06.04 end 

	    IMAGE_ENCODING_MB_Y = mby;

	  sby = mby << 2;
	  
	  //mbx=-1;
	  {
		  //sbx = (mbx-1) << 2; // valid when mbx ranges from 1 to img_width_in_mb
		  while(!OSB_SAFE); // wait until OSB overflow hazard to disappear
		  while(IMAGE_AFIFO_ALMOST_FULL);
		  { 
                         //2010.06.03 begin
                          if(intentional_islice==1){
                          ME_CR1 = 0x0;
                          ME_CR1 = 0x1;
                          }
                          //2010.06.03 end 

			  VIM_START = 0x1;
			  VIM_START = 0x0;
			  while (!(VIM_DONE&0x1));
		  }
	  }
	  //mbx=0;
	  {
		  //sbx = (mbx-1) << 2; // valid when mbx ranges from 1 to img_width_in_mb
		  while(!OSB_SAFE); // wait until OSB overflow hazard to disappear
		  while(IMAGE_AFIFO_ALMOST_FULL);
		  { 
			  if(img_type) // ME_DMA start
			  {
			          OS_ENTER_CRITICAL();         // memaccess_me begin
				  ME_DMA_START = 0x1;
                                      if(mby==0){
                                           SliceFirstMB_P  =  0x0;
                                           SliceLastMB_P   =  0xffffffff;
                                      }else{
                                        if(l==0) SliceFirstMB_P  =  mby;
                                        if(l==input.slice_argument-1) SliceLastMB_P  =  mby;
                                      }
                                  if(l==input.slice_argument-1) l=0;
                                  else                          l++;
                  //while(!ME_DMA_DONE);
				  while(!ME_DMA_DONE);
			          OS_EXIT_CRITICAL();          // memaccess_me end
				  ME_CR3  = ((sby & 0x0000FFFF) << 18) | ((0x0000FFFC)<<2); //0317 by chae
				  //while(!ME_INTERPOLATION_DONE);
				  ME_CR10 = 0x1; // ME_START
			          VIM_START = 0x1;
			          VIM_START = 0x0;
                                  while (!((ME_SR48>>1)&0x1));
			          OS_ENTER_CRITICAL();         // memaccess_me begin
			          ME_DMA_START = 0x1; //1-1)
			          while (!(ME_SR48&0x1)); //prediction_hw_top ();

			          while (!(VIM_DONE&0x1));
			  }
			  else {
				  DCTQ_CR2 = mby;
                                      if(k==0) SliceFirstMB_I  = mby;
                                      if(k==input.slice_argument-1) SliceLastMB_I  = mby;

                                  if(k==input.slice_argument-1) k=0;
                                  else                          k++;
				  DCTQ_CR1 = 0x1; // IPDCTQ_START
                                  if(intentional_islice==1) while(!(DCTQ_SR5&0x1)); // 2010.06.03
                                  if(intentional_islice==1){ //2010.06.03
                                  ME_CR1 = 0x0;
                                  ME_CR1 = 0x1;
                                  }
			          VIM_START = 0x1;
			          VIM_START = 0x0;
                                  if(intentional_islice==1) while (!(VIM_DONE&0x1)); //2010.06.03
			          while(!(DCTQ_SR5&0x1)); // IPDCTQ end
			          while (!(VIM_DONE&0x1));
			  }
			 
		  }
	  }
	  //mbx=1;
	  {
		  //sbx = (mbx-1) << 2; // valid when mbx ranges from 1 to img_width_in_mb
		  while(!OSB_SAFE); // wait until OSB overflow hazard to disappear
		  while(IMAGE_AFIFO_ALMOST_FULL);
		  {
			  if(img_type) {
				   //ME_DMA_START = 0x1; //1-0)
	                                  if(l==0) SliceFirstMB_P  = (1 << 16) | mby;
                                      if(l==input.slice_argument-1) SliceLastMB_P  = (1 <<16) | mby;
			   
                                  if(l==input.slice_argument-1) l=0;
                                  else                          l++;
				   DCTQ_CR2 = mby;
                                       if(k==0) SliceFirstMB_I  = mby;
                                       if(k==input.slice_argument-1) SliceLastMB_I  = mby;
                                  if(k==input.slice_argument-1) k=0;
                                  else                          k++;
			           DCTQ_CR1 = 0x1; // IPDCTQ_START
                                   while(!ME_DMA_DONE);
			           OS_EXIT_CRITICAL();          // memaccess_me end
                                   ME_CR3  = ((sby & 0x0000FFFF) << 18); //0317 by chae
                                   //ME_CR3  = ((sby & 0x0000FFFF) << 18) | ((sbx & 0x0000FFFF)<<2); //0317 by chae
                                   //while(!ME_DMA_DONE);
                                   //while(!ME_INTERPOLATION_DONE);
                                   ME_CR10 = 0x1; // ME_START
                                   VIM_START = 0x1;
                                   VIM_START = 0x0;
                                   while (!(VIM_DONE&0x1));
                                   while (!((ME_SR48>>1)&0x1));
			          			while (!(ME_SR48&0x1)); //prediction_hw_top (); // janghack + : ME done check
			          //OS_ENTER_CRITICAL();         // memaccess_me begin
                                   ME_DMA_START = 0x1; //1-1)

			  } else {
                                  VLC_CR1  = 0x1; //left & upper ?
                                  VLC_HVCR0 = ((i&0xffff)|((total_mb_nr&0xffff)<<16));
                                  if(intentional_islice==1) ME_CR1 = (img.type==P_SLICE) ? 0x0 : 0x1; //2010.06.03
                                  if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0))VLC_CR0 = (0x1|((img.number&0x7f)<<1));//2010.06.04
                                  if(intentional_islice==1) ME_CR1 = 0x1; //2010.06.03
                                  i++; //  i= 1, mbx=0 vlc start
                                  if(intentional_islice==1) while(!(VLC_SR0&0x1)); //2010.06.03 


				  DCTQ_CR2 = (1 << 16) | mby;
                                      if(k==0) SliceFirstMB_I  = (1 << 16) | mby;
                                      if(k==input.slice_argument-1) SliceLastMB_I  = (1 <<16) | mby;
                                  if(k==input.slice_argument-1) k=0;
                                  else                          k++;
			          OS_ENTER_CRITICAL();         // memaccess_me begin
				  ADF_START = 0x1;
			          DCTQ_CR1 = 0x1; // IPDCTQ_START
                                  if(intentional_islice==1)while(!(DCTQ_SR5&0x1)); // 2010.06.03

//#if ADF_BURST_SUPPORT
				  while(!ADF_READ_DONE); // Previous ADF is end ?
//#endif
                                  if(intentional_islice==1){ //2010.06.03
                                  ME_CR1 = 0x0;
                                  ME_CR1 = 0x1;
                                  }

				  VIM_START = 0x1;
				  VIM_START = 0x0;
				  while (!(VIM_DONE&0x1));
				  while(!(DCTQ_SR5&0x1)); // IPDCTQ end
                                 if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0)){ //2010.06.04
				  while(!(VLC_SR0&0x1)); // Previous VLC is end ?
				  acc_length = (unsigned int)((VLC_SR0 >> 1)&0x7);        	
	                          bits_to_go -= acc_length; //11i 11p
	                          if(bits_to_go <= 0) bits_to_go += 8;
                                 }
				  while(!ADF_DONE); // Previous ADF is end ?
			           OS_EXIT_CRITICAL();          // memaccess_me end
			  }
		  }
	  }
	  sbx = 0; // valid when mbx ranges from 1 to img_width_in_mb
	  for(mbx=2; mbx<img_width_in_mb-1; mbx++)
	  {
		  sbx += 4; // valid when mbx ranges from 1 to img_width_in_mb
		  //sbx = (mbx-1) << 2; // valid when mbx ranges from 1 to img_width_in_mb
		  while(!OSB_SAFE); // wait until OSB overflow hazard to disappear
		  while(IMAGE_AFIFO_ALMOST_FULL);
		  { // All Processing Elements are processed in parallel ( mbx = 2 ~ img_width_in_mb-2 )
			  if(img_type) {
			          if(mbx != 2) { 
                                               j++;
                                               if(j2==input.slice_argument-1) j2=0;
                                               else                           j2++;
                                              if(j2==0) {
                                                    SODBtoRBSP(); start_slice(j);slice_no++;
                                              }
			          }

				  // chae 2010.06.17 begin
				  if((ME_SR0&0xf)==0) {
					qp_delta = 0;
					VLC_DVCR0 = ((qp_delta)&0xff)<<6;
				  } else {
					if(img.prev_qp!=img.qp) qp_delta = img.qp-img.prev_qp;
					else qp_delta = 0;
					VLC_DVCR0 = ((qp_delta)&0xff)<<6;
					img.prev_qp = img.qp;
				  }	
				  // 2010.06.17 end

                                    VLC_CR1  = 0x1; //left & upper ?

				 VLC_HVCR0 = ((i&0xffff)|((total_mb_nr&0xffff)<<16));
			         if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0))VLC_CR0  = (0x1|((img.number&0x7f)<<1)); //2010.06.04
			         i++; // increase processed macroblock counter
                                      if(l==0) SliceFirstMB_P  = ((mbx) << 16) | mby;
                                      if(l==input.slice_argument-1) SliceLastMB_P  = ((mbx) <<16) | mby;

                                  if(l==input.slice_argument-1) l=0;
                                  else                          l++;
			          DCTQ_CR2 = ((mbx-1) << 16) | mby;
                                      if(k==0) SliceFirstMB_I  = ((mbx-1) << 16) | mby;
                                      if(k==input.slice_argument-1) SliceLastMB_I  = ((mbx-1) <<16) | mby;
                                  if(k==input.slice_argument-1) k=0;
                                  else                          k++;
			          //while(!ME_DMA_DONE);
			          while(!ME_INTERPOLATION_DONE);
			          OS_ENTER_CRITICAL();         // memaccess_me begin
			          ADF_START = 0x1; // ADF start
			          ME_CR3  = ((sby & 0x0000FFFF) << 18) | ((sbx & 0x0000FFFF)<<2); //0317 by chae
			          DCTQ_CR1 = 0x1; // IPDCTQ_START
			          ME_CR10 = 0x1; // ME_START

//#if ADF_BURST_SUPPORT
			           while(!ADF_READ_DONE); // Previous ADF is end ?
//#endif
			           while(!ME_DMA_DONE);
			          //OS_EXIT_CRITICAL();          // memaccess_me end
			           VIM_START = 0x1;
			           VIM_START = 0x0;
			           while(!ADF_DONE); // Previous ADF is end ?
			           OS_EXIT_CRITICAL();          // memaccess_me end
			           while (!(VIM_DONE&0x1));
                                   if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0)){ //2010.06.04
			           while(!(VLC_SR0&0x1)); // Previous VLC is end ?
			           acc_length = (unsigned int)((VLC_SR0 >> 1)&0x7);
	                          bits_to_go -= acc_length; //11i 11p
	                          if(bits_to_go <= 0) bits_to_go += 8;
                                  }
                                   while (!((ME_SR48>>1)&0x1));
			          //OS_ENTER_CRITICAL();         // memaccess_me begin
			           ME_DMA_START = 0x1; //2-1)
			           while (!(ME_SR48&0x1));

			  } else {
                                   j++;
                                               if(j2==input.slice_argument-1) j2=0;
                                               else                           j2++;
                                     //end_of_slice = ((j) == input.slice_argument*(slice_no+1));
                                     //if(end_of_slice) {
                                              if(j2==0) {
                                           SODBtoRBSP(); start_slice(j);slice_no++;
                                     }
                                  VLC_CR1  = 0x1; //left & upper ?
                                  VLC_HVCR0 = ((i&0xffff)|((total_mb_nr&0xffff)<<16));
                                  if(intentional_islice==1)ME_CR1 = (img.type==P_SLICE) ? 0x0 : 0x1; //2010.06.03
                                  if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0)) VLC_CR0 = (0x1|((img.number&0x7f)<<1)); //2010.06.04
                                  if(intentional_islice==1) ME_CR1 = 0x1; //2010.06.03
                                  i++;
                                  if(intentional_islice==1) while(!(VLC_SR0&0x1)); //2010.06.03 




				  DCTQ_CR2 = (mbx << 16) | mby;
                                      if(k==0) SliceFirstMB_I  = (mbx << 16) | mby;
                                      if(k==input.slice_argument-1) SliceLastMB_I  = (mbx << 16 ) | mby;
                                  if(k==input.slice_argument-1) k=0;
                                  else                          k++;
			          OS_ENTER_CRITICAL();         // memaccess_me begin
				  ADF_START = 0x1; // ADF start
				  DCTQ_CR1 = 0x1; // IPDCTQ_START
                                  if(intentional_islice==1) while(!(DCTQ_SR5&0x1)); // 2010.06.03
//#if ADF_BURST_SUPPORT					  
			          while(!ADF_READ_DONE); // Previous ADF is end ?
//#endif
                                   if(intentional_islice==1){ //2010.06.03
                                    ME_CR1 = 0x0;
                                    ME_CR1 = 0x1;
                                   }

			          VIM_START = 0x1;
			          VIM_START = 0x0;
                                  if(intentional_islice==1) while (!(VIM_DONE&0x1)); //2010.06.03
			          while(!ADF_DONE); // Previous ADF is end ?
			           OS_EXIT_CRITICAL();          // memaccess_me end
			          while (!(VIM_DONE&0x1));
                                  if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0)){ //2010.06.04
			          while(!(VLC_SR0&0x1)); // Previous VLC is end ?
			          acc_length = (unsigned int)((VLC_SR0 >> 1)&0x7);
	                          bits_to_go -= acc_length; //11i 11p
	                          if(bits_to_go <= 0) bits_to_go += 8;
                                  }
			          while(!(DCTQ_SR5&0x1));

			  }
		  }
	  }
	  //mbx=img_width_in_mb-1;
	  {
		  sbx += 4; // valid when mbx ranges from 1 to img_width_in_mb
		  //sbx = (mbx-1) << 2; // valid when mbx ranges from 1 to img_width_in_mb
		  while(!OSB_SAFE); // wait until OSB overflow hazard to disappear
		  while(IMAGE_AFIFO_ALMOST_FULL);
		  { 
			  if(img_type) {
				   //ME_DMA_START = 0x1; //2-0
                                       if(l==0) SliceFirstMB_P  = ((mbx) << 16) | mby;
                                       if(l==input.slice_argument-1) SliceLastMB_P  = ((mbx) <<16) | mby;
                                  if(l==input.slice_argument-1) l=0;
                                  else                          l++;

				   //while(!ME_DMA_DONE);
				   while(!ME_DMA_DONE);
			          //OS_EXIT_CRITICAL();          // memaccess_me end
			          OS_ENTER_CRITICAL();         // memaccess_me begin
			           ADF_START = 0x1; // ADF start
				   ME_CR3  = ((sby & 0x0000FFFF) << 18) | ((sbx & 0x0000FFFF)<<2); //0317 by chae
				   DCTQ_CR2 = ((mbx-1) << 16) | mby;
                                       if(k==0) SliceFirstMB_I  = ((mbx-1) << 16) | mby;
                                       if(k==input.slice_argument-1) SliceLastMB_I  = ((mbx-1) <<16) | mby;
                                  if(k==input.slice_argument-1) k=0;
                                  else                          k++;
                                        j++;
                                               if(j2==input.slice_argument-1) j2=0;
                                               else                           j2++;
                                      // end_of_slice = ((j) == input.slice_argument*(slice_no+1));
                                      // if(end_of_slice) {
                                              if(j2==0) {
                                             SODBtoRBSP(); start_slice(j);slice_no++;
                                       }

				  // chae 2010.06.17 begin
				  if((ME_SR0&0xf)==0) {
					qp_delta = 0;
					VLC_DVCR0 = ((qp_delta)&0xff)<<6;
				  } else {
					if(img.prev_qp!=img.qp) qp_delta = img.qp-img.prev_qp;
					else qp_delta = 0;
					VLC_DVCR0 = ((qp_delta)&0xff)<<6;
					img.prev_qp = img.qp;
				  }	
				  // 2010.06.17 end

                                      VLC_CR1  = 0x1; //left & upper ?
				   VLC_HVCR0 = ((i&0xffff)|((total_mb_nr&0xffff)<<16));
			           if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0))VLC_CR0 = (0x1|((img.number&0x7f)<<1)); //2010.06.04
			           i++; // increase processed macroblock counter
			           DCTQ_CR1 = 0x1; // IPDCTQ_START
                                   ME_CR10 = 0x1; // ME_START

                                 //  bits_to_go -= acc_length;  //9i 8p
                                 //  if(bits_to_go <= 0) bits_to_go += 8;
			         while(!ADF_DONE); // Previous ADF is end ?
			           OS_EXIT_CRITICAL();          // memaccess_me end
                                   if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0)){ //2010.06.04
			         while(!(VLC_SR0&0x1)); // Previous VLC is end ?
			         acc_length = (unsigned int)((VLC_SR0 >> 1)&0x7);        	
	                          bits_to_go -= acc_length; //11i 11p
	                          if(bits_to_go <= 0) bits_to_go += 8;
                                 }

			         while (!(ME_SR48&0x1)); 

			  } else {
                                   DCTQ_CR2 = (mbx << 16) | mby; //mbx=10
                                      if(k==0) SliceFirstMB_I  = (mbx << 16) | mby;
                                      if(k==input.slice_argument-1) SliceLastMB_I  = (mbx << 16 ) | mby;
                                  if(k==input.slice_argument-1) k=0;
                                  else                          k++;
                                       j++;
                                               if(j2==input.slice_argument-1) j2=0;
                                               else                           j2++;
                                     // end_of_slice = ((j) == input.slice_argument*(slice_no+1));
                                     // if(end_of_slice) {
                                              if(j2==0) {
                                            SODBtoRBSP(); start_slice(j);slice_no++;
                                      }

                                   VLC_CR1  = 0x1; //left & upper ?
                                   VLC_HVCR0 = ((i&0xffff)|((total_mb_nr&0xffff)<<16));
                                   if(intentional_islice==1) ME_CR1 = (img.type==P_SLICE) ? 0x0 : 0x1; //2010.06.03
                                   if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0)) VLC_CR0 = (0x1|((img.number&0x7f)<<1)); //2010.06.04
                                   if(intentional_islice==1) ME_CR1 = 0x1; //2010.06.03
                                   i++;
                                   if(intentional_islice==1) while(!(VLC_SR0&0x1)); //2010.06.03 


			           OS_ENTER_CRITICAL();         // memaccess_me begin
			           ADF_START = 0x1; // ADF start
			           DCTQ_CR1 = 0x1; // IPDCTQ_START
                                   if(intentional_islice==1)  while(!(DCTQ_SR5&0x1)); // 2010.06.03


			          while(!ADF_DONE); // Previous ADF is end ?
			           OS_EXIT_CRITICAL();          // memaccess_me end
                                   if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0)){ //2010.06.04
			          while(!(VLC_SR0&0x1)); // Previous VLC is end ?
			          acc_length = (unsigned int)((VLC_SR0 >> 1)&0x7);        	
	                          bits_to_go -= acc_length; //11i 11p
	                          if(bits_to_go <= 0) bits_to_go += 8;
                                   }

			          while(!(DCTQ_SR5&0x1));

                          }
		  }
	  }
	  mbx=img_width_in_mb; 
	  {
		  sbx += 4; // valid when mbx ranges from 1 to img_width_in_mb
		  //sbx = (mbx-1) << 2; // valid when mbx ranges from 1 to img_width_in_mb
		  while(!OSB_SAFE); // wait until OSB overflow hazard to disappear
		  while(IMAGE_AFIFO_ALMOST_FULL);
		  {
			  if(img_type) {
                                       j++;
                                               if(j2==input.slice_argument-1) j2=0;
                                               else                           j2++;
                                      // end_of_slice = ((j) == input.slice_argument*(slice_no+1));
                                      //if(end_of_slice) {
                                              if(j2==0) {
                                            SODBtoRBSP(); start_slice(j);slice_no++;
                                      }

				  // chae 2010.06.17 begin
				  if((ME_SR0&0xf)==0) {
					qp_delta = 0;
					VLC_DVCR0 = ((qp_delta)&0xff)<<6;
				  } else {
					if(img.prev_qp!=img.qp) qp_delta = img.qp-img.prev_qp;
					else qp_delta = 0;
					VLC_DVCR0 = ((qp_delta)&0xff)<<6;
					img.prev_qp = img.qp;
				  }	
				  // 2010.06.17 end
                                     VLC_CR1  = 0x1; //left & upper ?

				  VLC_HVCR0 = ((i&0xffff)|((total_mb_nr&0xffff)<<16));
			          if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0))VLC_CR0  = (0x1|((img.number&0x7f)<<1)); //2010.06.04
			          i++; // increase processed macroblock counter
			          OS_ENTER_CRITICAL();         // memaccess_me begin
			          ADF_START = 0x1; 
			  
				  DCTQ_CR2 = ((mbx-1) << 16) | mby;
                                      if(k==0) SliceFirstMB_I  = ((mbx-1) << 16) | mby;
                                      if(k==input.slice_argument-1) SliceLastMB_I  = ((mbx-1) <<16) | mby;
                                  if(k==input.slice_argument-1) k=0;
                                  else                          k++;
				  ME_CR3  = ((sby & 0x0000FFFF) << 18) | ((sbx & 0x0000FFFF)<<2); //0317 by chae
				  //DCTQ_CR2 = ((mbx-1) << 16) | mby;
				  DCTQ_CR1 = 0x1; // IPDCTQ_START
				  ME_CR10 = 0x1; // ME_START
			          //bits_to_go -= acc_length; //10i 9p
			          //if(bits_to_go <= 0)
				  //bits_to_go += 8;
                                  if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0)){ //2010.06.04
			          while(!(VLC_SR0&0x1)); // Last VLC is end ?
			          acc_length = (unsigned int)((VLC_SR0 >> 1)&0x7);
	                          bits_to_go -= acc_length; //11i 11p
	                          if(bits_to_go <= 0) bits_to_go += 8;
                                  }

			          while(!ADF_DONE);
			           OS_EXIT_CRITICAL();          // memaccess_me end
		
			          while (!(ME_SR48&0x1));

			  }else{
                                       j++;
                                               if(j2==input.slice_argument-1) j2=0;
                                               else                           j2++;
                                   //  end_of_slice = ((j) == input.slice_argument*(slice_no+1));
                                   // if(end_of_slice) {
                                              if(j2==0) {
                                          SODBtoRBSP(); start_slice(j);slice_no++;
                                    }

                                  VLC_CR1  = 0x1; //left & upper ?
                                  VLC_HVCR0 = ((i&0xffff)|((total_mb_nr&0xffff)<<16));
                                  if(intentional_islice==1) ME_CR1 = (img.type==P_SLICE) ? 0x0 : 0x1; //2010.06.03
                                  if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0)) VLC_CR0 = (0x1|((img.number&0x7f)<<1)); //2010.06.04
                                  if(intentional_islice==1) ME_CR1 = 0x1; //2010.06.03
                                  i++;
                                  if(intentional_islice==1) while(!(VLC_SR0&0x1)); //2010.06.03 


			          OS_ENTER_CRITICAL();         // memaccess_me begin
			          ADF_START = 0x1; 
                                  if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0)){ //2010.06.04
			          while(!(VLC_SR0&0x1)); // Last VLC is end ?
			          acc_length = (unsigned int)((VLC_SR0 >> 1)&0x7);
	                          bits_to_go -= acc_length; //11i 11p
	                          if(bits_to_go <= 0) bits_to_go += 8;
                                  }
			          while(!ADF_DONE);
			           OS_EXIT_CRITICAL();          // memaccess_me end
                          }
		
		  }
	  }
	  mbx=img_width_in_mb+1;
	  {
		  //sbx = (mbx-1) << 2; // valid when mbx ranges from 1 to img_width_in_mb
		  while(!OSB_SAFE); // wait until OSB overflow hazard to disappear
		  while(IMAGE_AFIFO_ALMOST_FULL);
		  {
			  if(img_type) {
                                       j++;
                                               if(j2==input.slice_argument-1) j2=0;
                                               else                           j2++;
                                   //  end_of_slice = ((j) == input.slice_argument*(slice_no+1));
                                   //  if(end_of_slice) {
                                              if(j2==0) {
                                           SODBtoRBSP(); start_slice(j);slice_no++;
                                     }

				  // chae 2010.06.17 begin
				  if((ME_SR0&0xf)==0) {
					qp_delta = 0;
					VLC_DVCR0 = ((qp_delta)&0xff)<<6;
				  } else {
					if(img.prev_qp!=img.qp) qp_delta = img.qp-img.prev_qp;
					else qp_delta = 0;
					VLC_DVCR0 = ((qp_delta)&0xff)<<6;
					img.prev_qp = img.qp;
				  }	
				  // 2010.06.17 end
                                   VLC_CR1  = 0x1; //left & upper ?

				  VLC_HVCR0 = ((i&0xffff)|((total_mb_nr&0xffff)<<16));
				  if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0))VLC_CR0  = (0x1|((img.number&0x7f)<<1)); //2010.06.04
				  i++; // increase processed macroblock counter
			          OS_ENTER_CRITICAL();         // memaccess_me begin
				  ADF_START = 0x1;

				  //bits_to_go -= acc_length; //10p
				  //if(bits_to_go <= 0) bits_to_go += 8;

                                  if(!(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0)){ //2010.06.04 
				  while(!(VLC_SR0&0x1)); // Last VLC is end ?
				  acc_length = (unsigned int)((VLC_SR0 >> 1)&0x7);
	                          bits_to_go -= acc_length; //11i 11p
	                          if(bits_to_go <= 0) bits_to_go += 8;
                                  }
				  while(!ADF_DONE);
			           OS_EXIT_CRITICAL();          // memaccess_me end
                                     j++;
                                               if(j2==input.slice_argument-1) j2=0;
                                               else                           j2++;
                                     end_of_slice = ((j) == input.slice_argument*(slice_no+1)); //i=11
                                     end_of_last_slice = ((j) == total_mb_nr); //i=11
                                     if(j==total_mb_nr) {
                                           if(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0){ //2010.06.04
                                             //img.cod_counter = input.slice_argument;
                                          if(H264_RESOLUTION == H264_VGA){//kik_fw++
                                             img.cod_counter = 40;
                                          }
                                          else if(H264_RESOLUTION == H264_QVGA){
                                             img.cod_counter = 20;
                                          }
                                             terminate_frame();
                                           }
                                           SODBtoRBSP(); slice_no++;
                                     }
                                    else if(j2==0) {
                                           if(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0){ //2010.06.04
                                          if(H264_RESOLUTION == H264_VGA){//kik_fw++
                                             img.cod_counter = 40;
                                          }
                                          else if(H264_RESOLUTION == H264_QVGA){
                                             img.cod_counter = 20;
                                          }
                                             terminate_frame();
                                           }
                                           SODBtoRBSP(); start_slice(i);slice_no++;
                                     }


			  } 
			else
			{
                                  j++;
                                               if(j2==input.slice_argument-1) j2=0;
                                               else                           j2++;
                                     //end_of_slice = ((j) == input.slice_argument*(slice_no+1)); //i=11
                                     //end_of_last_slice = ((j) == total_mb_nr); //i=11
                                     //if(end_of_last_slice) {
                                     if(j==total_mb_nr) {
                                           if(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0){ //2010.06.04
                                          if(H264_RESOLUTION == H264_VGA){//kik_fw++
                                             img.cod_counter = 40;
                                          }
                                          else if(H264_RESOLUTION == H264_QVGA){
                                             img.cod_counter = 20;
                                          }
                                             terminate_frame();
                                           }
                                              SODBtoRBSP(); slice_no++;
                                     }
                                    // else if(end_of_slice) {
                                    else if(j2==0) {
                                           if(img.type==P_SLICE && img.number%fake_intra_period==0 && intra_line_curr==0){ //2010.06.04
                                          if(H264_RESOLUTION == H264_VGA){//kik_fw++
                                             img.cod_counter = 40;
                                          }
                                          else if(H264_RESOLUTION == H264_QVGA){
                                             img.cod_counter = 20;
                                          }
                                             terminate_frame();
                                           }
                                              SODBtoRBSP(); start_slice(i);slice_no++;
                                     }


			}
	

		  }
	  }
	  //090408_jykim_mux_head+ 
    //OSB Buffer to Frame Memory
	  //if ( MUX_STREAM_EN )
	  //{
      osb_fifo_filled_num = OSB_FILL_NUM;

			for (osb_fifo_i = 0; osb_fifo_i < osb_fifo_filled_num; osb_fifo_i
					+= 4) {
				//*((volatile int*) (JPEG_STREAM_BASE1 + jpeg_length_array[1]))
				//		= OSB_DATA_FIFO;
				//jpeg_length_array[1] += 4;
				if ( img_type == 1 ) //P_SLICE
				{
					if ( h264DualStreamBuf.len[(int)h264DualStreamBuf.set_idx] > MAX_H264_STREAM_LEN )
					{
						temp = OSB_DATA_FIFO;
					}
					else
					{
						*(volatile int*)(H264_STREAM_ADDR + (h264DualStreamBuf.set_idx * MAX_H264_STREAM_LEN) + h264DualStreamBuf.len[(int)h264DualStreamBuf.set_idx] ) 
							= OSB_DATA_FIFO;
					}
				}
				else //I_SLICE
				{
					if ( h264DualStreamBuf.len[(int)h264DualStreamBuf.set_idx] > MAX_H264_STREAM_LEN * 2)
					{
						temp = OSB_DATA_FIFO;
					}
					else
					{
						*(volatile int*)(H264_STREAM_ADDR + (h264DualStreamBuf.set_idx * MAX_H264_STREAM_LEN) + h264DualStreamBuf.len[(int)h264DualStreamBuf.set_idx] ) 
							= OSB_DATA_FIFO;
					}

				}
				h264DualStreamBuf.len[(int)h264DualStreamBuf.set_idx] += 4; 
			}
	
	  //}
	  ////090408_jykim_mux_tail+ 
	  ////090507_jarre_dvp2_head+ 
	  //else if ( DVP_DATA_SRC )
	  //  {
	  //    osb_fifo_filled_num = OSB_FILL_NUM;
	  //    for ( osb_fifo_i = 0; osb_fifo_i < osb_fifo_filled_num; osb_fifo_i += 4 )
	  //  {
	  //    *((volatile int*)(H264_STREAM_BASE + jpeg_length_array[4])) =  OSB_DATA_FIFO;
	  //    jpeg_length_array[4] += 4;
	  //  }
	  //  }
	  ////090507_jarre_dvp2_tail+ 


	// chae 2010.06.17 begin
/*	simpleLIneRateControl
	if(img.type==P_SLICE &&
	   img.number%fake_intra_period!=0 &&
	   img.number%fake_intra_period!=1 &&
	   img.number%fake_intra_period!=(fake_intra_period-1)) {
	    img.prev_qp=img.qp;
	    simpleLineRateControl (mby, img_height_in_mb);
	    ME_CR2 = img.qp;
	    Deblock_Control1(input.LFDisableIdc, img.qp);
	} else {
	    if (img.type==P_SLICE) img.prev_qp=img.qp=input.qpN;
	    else img.prev_qp=img.qp = input.qp0;
	}
*/
	// chae 2010.06.17 end	


  }
  //bits_per_frame = (OSC_CNT_STREAM)<<5;
  //OSC_CNT_STREAM = 0;
  //img.cod_counter = (unsigned int)((VLC_HVSR0>>4)&0xfff); // skip MB in a row : seems not used now
  //terminate_frame();
  //SODBtoRBSP();
}


/*!
 ************************************************************************
 * \brief
 *    Memory frees of all Slice structures and of its dependent
 *    data structures
 * \par Input:
 *    Image Parameters struct struct img_par *img
 ************************************************************************
 */
void free_slice_list(Picture *currPic)
{
    free_slice (currPic->slices);
    currPic->slices=NULL;

	//MSG(FREE_SLICE_LIST);
}


/*!
 ************************************************************************
 * \brief
 *    Memory frees of the Slice structure and of its dependent
 *    data structures
 * \para slice:
 *    Slice to be freed
 ************************************************************************
 */
static void free_slice(Slice *slice)
{
  if (slice != NULL)
  {
    free(slice);
  }
  //MSG(FREE_SLICE);
}

// chae 2010.06.17 begin
short result_size_byte_until_5;

void simpleLineRateControl(int mby,int img_height_in_mb) //2010.06.17
{
    int result_size_byte_until_now;
    int target_one_frame_size_byte_div_5;
    int target_one_frame_size_byte_div_3_5;
    int size_diff;
    result_size_byte_until_now = h264DualStreamBuf.len[(int)h264DualStreamBuf.set_idx];


    target_one_frame_size_byte_div_5 = target_one_frame_size_byte/5;
    target_one_frame_size_byte_div_3_5 = target_one_frame_size_byte_div_5*3;
    if(mby==5){
        // original by chae if(result_size_byte_until_now > (target_one_frame_size_byte/3)+340) input.qpN += 2;
        // else if(result_size_byte_until_now > (target_one_frame_size_byte/3)+170) input.qpN += 1;
        if(result_size_byte_until_now > (target_one_frame_size_byte_div_5)+150) input.qpN += 3;
        else if(result_size_byte_until_now > (target_one_frame_size_byte_div_5)-250) input.qpN += 2;
        else if(result_size_byte_until_now > (target_one_frame_size_byte_div_5)-300) input.qpN += 1;
        result_size_byte_until_5 = result_size_byte_until_now;
     }
     if(mby==23){
        size_diff = result_size_byte_until_now-result_size_byte_until_5;
    if(result_size_byte_until_5 <= ((target_one_frame_size_byte_div_5)-300)) {
             if(size_diff > ((target_one_frame_size_byte_div_3_5)))
        input.qpN += 4;
             else if(size_diff > ((target_one_frame_size_byte_div_3_5)-600))
        input.qpN += 3;
             else if(size_diff > ((target_one_frame_size_byte_div_3_5)-2000))
        input.qpN += 2;
    } else // between -100 and 0
    if(result_size_byte_until_5 <= ((target_one_frame_size_byte_div_5)-250)) {
             if(size_diff > ((target_one_frame_size_byte_div_3_5)-500))
        input.qpN += 3;
             else if(size_diff > ((target_one_frame_size_byte_div_3_5)-1000))
        input.qpN += 2;
    } else if(result_size_byte_until_5 <= ((target_one_frame_size_byte_div_5)+150)) {
         if(size_diff > ((target_one_frame_size_byte_div_3_5)-1000))
        input.qpN += 2;
        }
     }

    img.qp = input.qpN;

}

// chae 2010.06.17 end 
