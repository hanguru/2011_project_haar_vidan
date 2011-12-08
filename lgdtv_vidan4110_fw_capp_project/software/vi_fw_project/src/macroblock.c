
/*!
 *************************************************************************************
 * \file macroblock.c
 *
 * \brief
 *    Process one macroblock
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *    - Inge Lille-Lang?               <inge.lille-langoy@telenor.com>
 *    - Rickard Sjoberg                 <rickard.sjoberg@era.ericsson.se>
 *    - Jani Lainema                    <jani.lainema@nokia.com>
 *    - Sebastian Purreiter             <sebastian.purreiter@mch.siemens.de>
 *    - Detlev Marpe                    <marpe@hhi.de>
 *    - Thomas Wedi                     <wedi@tnt.uni-hannover.de>
 *    - Ragip Kurceren                  <ragip.kurceren@nokia.com>
 *************************************************************************************
 */

#include <assert.h>

#include "vlc.h"
#include "image.h"
#include "mb_access.h"

 /*!
 ************************************************************************
 * \brief
 *    updates the coordinates for the next macroblock to be processed
 *
 * \input
 *    mb: MB address in scan order
 ************************************************************************
 */

void set_MB_parameters (int mb)
{
  int cnt = 0;

  const int number_mb_per_row          = img.width >> 4 ;
  img.current_mb_nr = mb;

  while(1){
    if(mb-number_mb_per_row<0) break; 
    else {
        mb = mb-number_mb_per_row;
        cnt++;
    }
  }
  img.mb_x = mb;
  img.mb_y = cnt;


  // Define vertical positions
  //img.block_y       = img.mb_y << 2;                // vertical luma 4x4block position
  //img.pix_y         = img.mb_y << 4;                // vertical luma macroblock position

  // Define horizontal positions
  //img.block_x       = img.mb_x << 2;                  // luma block
  //img.pix_x         = img.mb_x << 4;                  // luma pixel

  //MSG(SET_MB_PARAMETERS);
}

void set_nextMB_parameters (int mb)
{
  int cnt = 0;

  const int number_mb_per_row          = img.width >> 4 ;

  while(1){
    if(mb-number_mb_per_row<0) break;
    else {
        mb = mb-number_mb_per_row;
        cnt++;
    }
  }
  img.next_mb_x = mb;
  img.next_mb_y = cnt;
}

/*!
 ************************************************************************
 * \brief
 *    initializes the current macroblock
 ************************************************************************
 */
void start_macroblock()
{
  Macroblock *currMB = &img.mb_data_q;
  currMB->mbAvailA = (img.mb_x==0)?0:1;
  currMB->mbAvailB = (img.mb_y==0)?0:1;

  currMB->c_ipred_mode = DC_PRED_8; //GB 0

  //MSG(START_MACROBLOCK);
}

void terminate_frame(){
//  Macroblock    *currMB    = &img.mb_data_q; 
  SyntaxElement *currSE    = &img.MB_SyntaxElements[0];
  if(img.cod_counter)
  {
    currSE->value1  = img.cod_counter;
    currSE->mapping = ue_linfo;

    writeSyntaxElement_UVLC(currSE);
    img.cod_counter = 0;
  }
}

/*!
 ************************************************************************
 * \brief
 *    Passes the chosen syntax elements to the NAL
 ************************************************************************
 */
//void write_one_macroblock ()
void write_one_macroblock_setting1 ()
{
  //MB_BLOCK_SIZE  = 16;
  //BLOCK_SIZE = 4
  //Macroblock* currMB   = &img.mb_data_q;
  ////added by chae for multi-size
  //const int number_mb_per_row = img.width >>4 ;
  //const int number_mb_per_row_mul_four = number_mb_per_row*4 ;
  //const int number_mb_per_row_mul_six  = number_mb_per_row*6;

  //int y_nnz_border0, y_nnz_border1, y_nnz_border2, y_nnz_border3;
  //int y_nnz_border4, y_nnz_border5, y_nnz_border6, y_nnz_border7;
  //int u_nnz_border0, u_nnz_border1, u_nnz_border2, u_nnz_border3;
  //int v_nnz_border0, v_nnz_border1, v_nnz_border2, v_nnz_border3;
  //
  //int mb_x = img.mb_x;
  //int prev_mb_x = img.prev_mb_x;
  //int mb_avail_up   = currMB->mbAvailB;
  //int *nz_coeff_u   = img.nz_coeff_u;
  //int i;
  //int nz_coeff_reg[6];
  //nz_coeff_reg[3] = VLC_DVSR3;//Y
  //nz_coeff_reg[4] = VLC_DVSR4;//U
  //nz_coeff_reg[5] = VLC_DVSR5;//V
 
 //// previous vlc wrapup
  //// LUMA Non-Zero Coefficients
  //nz_coeff_u[(prev_mb_x<<2) + 0] 			      = (signed int)((nz_coeff_reg[3]    )&0x3f);	// Y_NNZ12 - up
  //nz_coeff_u[(prev_mb_x<<2) + 1] 			      = (signed int)((nz_coeff_reg[3]>>6 )&0x3f);	// Y_NNZ13 - up
  //nz_coeff_u[(prev_mb_x<<2) + 2] 			      = (signed int)((nz_coeff_reg[3]>>12)&0x3f);	// Y_NNZ14 - up
  //nz_coeff_u[(prev_mb_x<<2) + 3] 			      = (signed int)((nz_coeff_reg[3]>>18)&0x3f);	// Y_NNZ15 - up
 
  //// Cb   Non-Zero Coefficients  - modified by chae for multi-size
  //nz_coeff_u[(prev_mb_x<<1) + number_mb_per_row_mul_four]     = (signed int)((nz_coeff_reg[4]>>12)&0x3f);  // U_NNZ2 - up
  //nz_coeff_u[(prev_mb_x<<1) + number_mb_per_row_mul_four +1]  = (signed int)((nz_coeff_reg[4]>>18)&0x3f);  // U_NNZ3 - up
  //
  //// Cb   Non-Zero Coefficients  - modified by chae for multi-size
  //nz_coeff_u[(prev_mb_x<<1) + number_mb_per_row_mul_six]     = (signed int)((nz_coeff_reg[5]>>12)&0x3f);  // V_NNZ2 - up
  //nz_coeff_u[(prev_mb_x<<1) + number_mb_per_row_mul_six+1]   = (signed int)((nz_coeff_reg[5]>>18)&0x3f);  // V_NNZ3 - up
  //
  //// VLC_HARDWARE
  //if(mb_avail_up){
  //        y_nnz_border0 = nz_coeff_u[(mb_x<<2) + 0];
  //        y_nnz_border1 = nz_coeff_u[(mb_x<<2) + 1];
  //        y_nnz_border2 = nz_coeff_u[(mb_x<<2) + 2];
  //        y_nnz_border3 = nz_coeff_u[(mb_x<<2) + 3];
  //        u_nnz_border0 = nz_coeff_u[(mb_x<<1) + (number_mb_per_row_mul_four)];
  //        u_nnz_border1 = nz_coeff_u[(mb_x<<1) + (number_mb_per_row_mul_four)+1];
  //        v_nnz_border0 = nz_coeff_u[(mb_x<<1) + (number_mb_per_row_mul_six)];
  //        v_nnz_border1 = nz_coeff_u[(mb_x<<1) + (number_mb_per_row_mul_six)+1];
  //}
 
  ////0710 : left info in hartware begin
  //VLC_DVCR1  = ((y_nnz_border0&0x3f)|((y_nnz_border1&0x3f)<<6)|((y_nnz_border2&0x3f)<<12)|((y_nnz_border3&0x3f)<<18)); //upper
  //VLC_DVCR3  = ((u_nnz_border0&0x3f)|((u_nnz_border1&0x3f)<<6)); //upper
  //VLC_DVCR4  = ((v_nnz_border0&0x3f)|((v_nnz_border1&0x3f)<<6)); //upper
  VLC_CR1    = 0x1; //left & upper
  //left info in hartware end

  //MSG(VLC_SETTING_DONE);
}

void write_one_macroblock_setting2 ()
{
  //MB_BLOCK_SIZE  = 16;
  //BLOCK_SIZE = 4
  //Macroblock* currMB   = &img.mb_data_q;
  
  //int cbp           	= currMB->cbp;
  //int delta_qp      	= currMB->delta_qp;
  //int mb_type       	= currMB->mb_type;
  int current_mb_nr 	= img.current_mb_nr;
  int tot_mb_nr     	= img.total_number_mb;
  //int i16offset     	= img.i16offset;
  //int mb_avail_up   	= currMB->mbAvailB;
  //int mb_avail_left 	= currMB->mbAvailA;
  int mb_avail_up   	=  (img.mb_y==0)?0:1; 
  int mb_avail_left 	=  (img.mb_x==0)?0:1; 
  int cod_counter_in 	= img.cod_counter;
  int img_type      	= img.type; 
  //int c_ipredmode    	= currMB->c_ipred_mode;

  //VLC_HVCR0 = ((current_mb_nr&0xfff)|((tot_mb_nr&0xfff)<<12)|((mb_type&0xf)<<24)); 
  //VLC_HVCR1 = ((c_ipredmode&0xf)|((i16offset&0x3f)<<4)|((cod_counter_in)&0xfff)<<16|((img_type&0x1)<<28));
  //VLC_DVCR0  = (((0&0xff)<<6)|((mb_avail_left&0x1)<<14) |((mb_avail_up&0x1)<<15)|((mb_avail_left&0x1)<<16)|((mb_avail_up&0x1)<<17));
  VLC_HVCR0 = ((current_mb_nr&0xfff)|((tot_mb_nr&0xfff)<<12)); 
  VLC_HVCR1 = (((cod_counter_in)&0xfff)<<16|((img_type&0x1)<<28));
  VLC_DVCR0  = (((0&0xff)<<6)|((mb_avail_left&0x1)<<14) |((mb_avail_up&0x1)<<15)|((mb_avail_left&0x1)<<16)|((mb_avail_up&0x1)<<17));
}


void write_one_macroblock_setting3 (){

  //Macroblock* currMB   = &img.mb_data_q;
  //int cbp           	= currMB->cbp;
  ////int delta_qp      	= currMB->delta_qp;
  //int mb_avail_up   	= currMB->mbAvailB;
  //int mb_avail_left 	= currMB->mbAvailA;

  //VLC_DVCR0  = ((cbp&0x3f)|((0&0xff)<<6)|((mb_avail_left&0x1)<<14) |((mb_avail_up&0x1)<<15)|((mb_avail_left&0x1)<<16)|((mb_avail_up&0x1)<<17));
}

void write_one_macroblock_i (){
//  int i;
  int acc_length;
  int frame_nr      = img.number;

  VLC_CR0    = (0x1|((frame_nr&0x7f)<<1)); //VLC START

  while (!(VLC_SR0&0x1)); //VLC DONE
  acc_length                      = (unsigned int)((VLC_SR0 >> 1)&0x7);
  img.cod_counter                 = (unsigned int)((VLC_HVSR0>>4)&0xfff);//this value is used in OSC

  bits_to_go -= acc_length;
  if(bits_to_go <= 0)
	  bits_to_go += 8;
//  for(i=0;i<acc_length;i++)
//  {
//          bits_to_go--;
//          if(bits_to_go==0)
//        	  bits_to_go = 8;
//  }

  //MSG(VLC_DONE);
}

void write_one_macroblock (){
//  int i;
  int acc_length;
  int frame_nr      = img.number;

  VLC_CR0    = (0x1|((frame_nr&0x7f)<<1)); //VLC START

  //terminate_macroblock(); // in advance

  while (!(VLC_SR0&0x1)); //VLC DONE

  acc_length           		  = (unsigned int)((VLC_SR0 >> 1)&0x7); 
  img.cod_counter  	          = (unsigned int)((VLC_HVSR0>>4)&0xfff);//this value is used in OSC
  //currMB->c_ipred_mode 								= (unsigned int)((VLC_HVSR0   )&0xf);

  bits_to_go -= acc_length;
  if(bits_to_go <= 0)
	  bits_to_go += 8;
//  for(i=0;i<acc_length;i++)
//  {
//          bits_to_go--;
//          if(bits_to_go==0)
//        	  bits_to_go = 8;
//  }

  //MSG(VLC_DONE);
}

void write_one_macroblock_p (){
  //int i;
  //int acc_length;
  int frame_nr      = img.number;
  VLC_CR0    = (0x1|((frame_nr&0x7f)<<1)); //VLC START

}

void write_one_macroblock_p_wrapup (){
//  int i;
  int acc_length;

  while (!(VLC_SR0&0x1)); //VLC DONE
  acc_length                      = (unsigned int)((VLC_SR0 >> 1)&0x7);
  img.cod_counter                 = (unsigned int)((VLC_HVSR0>>4)&0xfff);//this value is used in OSC

  bits_to_go -= acc_length;
  if(bits_to_go <= 0)
	  bits_to_go += 8;
//  for(i=0;i<acc_length;i++)
//  {
//          bits_to_go--;
//          if(bits_to_go==0)
//        	  bits_to_go = 8;
//  }

  //MSG(VLC_DONE);
}

