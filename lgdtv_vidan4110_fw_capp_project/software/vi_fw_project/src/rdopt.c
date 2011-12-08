
/*!
 ***************************************************************************
 * \file rdopt.c
 *
 * \brief
 *    Rate-Distortion optimized mode decision
 *
 * \author
 *    Heiko Schwarz <hschwarz@hhi.de>
 *
 * \date
 *    12. April 2001
 **************************************************************************
 */

#include <assert.h>

#include "vlc.h"
#include "image.h"
#include "mbuffer.h"
#include "mb_access.h"
//#include "dma.h"

int sbxindex[16] = {0,1,0,1,2,3,2,3,0,1,0,1,2,3,2,3};
int sbyindex[16] = {0,0,1,1,0,0,1,1,2,2,3,3,2,2,3,3};

////////////////////////////////////////////////////////////////////////////
// Global Register Set
//unsigned int GlobalReg[15];
// Intra prediction Register Set
unsigned char neighbourlumaPixel[40];
unsigned char neighbourcbPixel[16];
unsigned char neighbourcrPixel[16];
// Output Register Set
unsigned int OutputReg[49];
////////////////////////////////////////////////////////////////////////////

extern void write_one_macroblock_p_wrapup(void);

/*! 
 *************************************************************************************
 * \brief
 *    Mode Decision for a macroblock
 *************************************************************************************
 */

void encode_one_macroblock_i (int mb)
{
  Macroblock *currMB = &img.mb_data_q;
  //static unsigned int Line_SB_inform[180] = {0, }; //  up to SDTV 

  int mbx, mby;
  

//=============================  Data to ME module (AHB1)  ==========================

  if(img.type==I_SLICE && img.mb_x!=0)  write_one_macroblock(); //vlc
  mbx = img.mb_x;  //  d17: signals according to stage 2???
  mby = img.mb_y;
  //sbx = mbx << 2;
  //sby = mby << 2;

  start_macroblock();
  //currMB->c_ipred_mode = DC_PRED_8; //GB 0

  while (!(VIM_DONE&0x1));
  while (!(VLC_SR0&0x1)); //after VLC DONE, new DCTQ start

  DCTQ_CR2 = (img.mb_x << 16) | img.mb_y; // macroblock x,y position in image
  DCTQ_CR1 = 0x1; // IPDCTQ start
  //currMB->cbp_blk = (unsigned int)((DCTQ_SR5 >> 8)&0xffffff);
  //write_one_macroblock_setting1();
  VLC_CR1    = 0x1; //left & upper
  set_nextMB_parameters (mb+1);

  while(!(DCTQ_SR5&0x1)); //end?

   OutputReg[ 9] = DCTQ_SR4;
   currMB->c_ipred_mode = (OutputReg[9]&0x30000)>>16; //[17:16]: c_ipred_mode
   currMB->mb_type = (unsigned char)((OutputReg[9]>>18)&0xf);
   img.i16offset   = (unsigned int)((DCTQ_SR7     )&0x3f);

   write_one_macroblock_setting2(); 


   while (!(VIM_DONE&0x1));
while(!ME_DMA_DONE);
while(!ADF_DONE);
   if(img.mb_x ==img.PicWidthInMbs-1 ) write_one_macroblock();
    img.prev_mb_x           = img.mb_x;
    img.prev_mb_y           = img.mb_y;
}



void encode_one_macroblock (int mb)
{
  int mbx, mby, sbx, sby;
  int vim_start_flag = 0;
  int current_mb_nr;
  int tot_mb_nr;
  int mb_avail_up;
  int mb_avail_left;
  int cod_counter_in;
  int img_type;
  

  mbx = img.mb_x; mby = img.mb_y;
  sbx = mbx << 2; sby = mby << 2;

  ME_CR3  = ((sby & 0x0000FFFF) << 18) | ((sbx & 0x0000FFFF)<<2);
  // janghack+ (2008.02.27)
  // [31 ~ 5]: unused bits, skip_mode_en [4], FastQME [3], FastHME [2], skip_qme_en [1], skip_hme [0]
/*    0308 debug
  while(!ME_DMA_DONE);
  //while(!ADF_DONE);


  if(mb==-1){
	  //while(!ME_DMA_DONE);
	  //while(!ADF_DONE);
	  ME_DMA_START = 1;
  }
*/
  //== start IME/INTRA
  if (mbx != -1) {
  	DCTQ_CR2 = (img.mb_x << 16) | img.mb_y; // macroblock x,y position in image
  	DCTQ_CR1 = 0x1; // IPDCTQ start
  }
  ME_CR10 = 0x1;	// ME_START
//  if(mb==-1){
//#ifndef ME_DMA
//          dma_wait;
//          DMA_SADDY = (img.mb_y << 16) |img.mb_x+2 ;
//          DMA_CTRL  = DMA_START_WITH_PADDING;
//#else
////	while(!ME_DMA_DONE);
//	ME_DMA_START = 1;
//#endif
//  }

  //==  dctq --> frame mem 
 if(mb!=-1 && mb!=0) {
       //dctq_to_frame_mem(img.prev_mb_x,img.prev_mb_y);
          //DMA_PREFETCH = 0;
//          DMA_SADDY    = (img.prev_mb_y << 16) | img.prev_mb_x;
//          DMA_CTRL     = DMA_START;
  }
  //==  vlc setting 
  if(mb==-1){
      set_nextMB_parameters (img.mb_y*img.PicWidthInMbs);
  }else{
      //write_one_macroblock_setting1();
      VLC_CR1    = 0x1; //left & upper
      img.next_mb_x = mbx+1;
      img.next_mb_y = mby;
      img.prev_mb_x           = img.mb_x;
      img.prev_mb_y           = img.mb_y;
  }
  if(mb!=-1 && mb!=0) write_one_macroblock_p_wrapup();
  //if(mb!=-1) write_one_macroblock_setting2();
  // test
  current_mb_nr     = img.current_mb_nr;
  tot_mb_nr         = img.total_number_mb;
  mb_avail_up       =  (img.mb_y==0)?0:1;
  mb_avail_left     =  (img.mb_x==0)?0:1;
  cod_counter_in    = img.cod_counter;
  img_type          = img.type;

  vim_start_flag = ((((img.mb_x+1) !=  img.PicWidthInMbs-1) &&(img.mb_x+1) != img.PicWidthInMbs ));
// test vim pipeline begin
  if(mb==-1){
//	IMAGE_ENCODING_MB_Y = img.mb_y;
//	if (FRAME_SRC_SEL == 0x1) while(((((img.mb_y << 4) + 17) > IMAGE_TRANS_Y_CNT - img.height_offset) && (IMAGE_FRAME_CNT == 0)) || (IMAGE_FRAME_CNT == 7)); //CAM
//	else if (FRAME_SRC_SEL == 0x2) while(((((img.mb_y << 4) + 17) > ISP_OUT_TRANS_Y_CNT - img.height_offset) && (ISP_VALID_FRAME_CNT == 0)) || (ISP_VALID_FRAME_CNT == 7)); //ISP
        VIM_START = 0x1;
        VIM_START = 0x0;
  }
// test vim pipeline end 

  while (!(ME_SR48&0x1)); //prediction_hw_top ();

  if(mb!=-1) {//write_one_macroblock_setting2();
     VLC_HVCR0 = ((current_mb_nr&0xfff)|((tot_mb_nr&0xfff)<<12));
     VLC_HVCR1 = (((cod_counter_in)&0xfff)<<16|((img_type&0x1)<<28));
     VLC_DVCR0  = (((0&0xff)<<6)|((mb_avail_left&0x1)<<14) |((mb_avail_up&0x1)<<15)|((mb_avail_left&0x1)<<16)|((mb_avail_up&0x1)<<17));

  }
  else      return;

/* when mb!=-1
  //==  vlc start 
  VLC_CR0    = (0x1|((img.number&0x7f)<<1)); //VLC START //

  //== load cur/ref for next MB
  if (vim_start_flag){
        VIM_START = 0x1;
        VIM_START = 0x0;
        //frame_mem_to_me(img.next_mb_x +1,img.next_mb_y); 
        
        //DMA_SADDY = (img.next_mb_y << 16) |img.next_mb_x+1 ;
        //while (!(VIM_DONE&0x1));
        //DMA_CTRL  = DMA_START_WITH_PADDING;
   }
*/
}

