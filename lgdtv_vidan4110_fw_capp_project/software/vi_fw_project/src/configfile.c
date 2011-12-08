
/*!
 ***********************************************************************
 * \file
 *    configfile.c
 * \brief
 *    Configuration handling.
 * \author
 *  Main contributors (see contributors.h for copyright, address and affiliation details)
 *    - Stephan Wenger           <stewe@cs.tu-berlin.de>
 * \note
 *    In the future this module should hide the Parameters and offer only
 *    Functions for their access.  Modules which make frequent use of some parameters
 *    (e.g. picture size in macroblocks) are free to buffer them on local variables.
 *    This will not only avoid global variable and make the code more readable, but also
 *    speed it up.  It will also greatly facilitate future enhancements such as the
 *    handling of different picture sizes in the same sequence.                         \n
 *                                                                                      \n
 *    For now, everything is just copied to the inp_par structure (gulp)
 *
 **************************************************************************************
 * \par Configuration File Format
 **************************************************************************************
 * Format is line oriented, maximum of one parameter per line                           \n
 *                                                                                      \n
 * Lines have the following format:                                                     \n
 * <ParameterName> = <ParameterValue> # Comments \\n                                    \n
 * Whitespace is space and \\t
 * \par
 * <ParameterName> are the predefined names for Parameters and are case sensitive.
 *   See configfile.h for the definition of those names and their mapping to
 *   configinput.values.
 * \par
 * <ParameterValue> are either integers [0..9]* or strings.
 *   Integers must fit into the wordlengths, signed values are generally assumed.
 *   Strings containing no whitespace characters can be used directly.  Strings containing
 *   whitespace characters are to be inclosed in double quotes ("string with whitespace")
 *   The double quote character is forbidden (may want to implement something smarter here).
 * \par
 * Any Parameters whose ParameterName is undefined lead to the termination of the program
 * with an error message.
 *
 * \par Known bug/Shortcoming:
 *    zero-length strings (i.e. to signal an non-existing file
 *    have to be coded as "".
 *
 * \par Rules for using command files
 *                                                                                      \n
 * All Parameters are initially taken from DEFAULTCONFIGFILENAME, defined in configfile.h.
 * If an -f <config> parameter is present in the command line then this file is used to
 * update the defaults of DEFAULTCONFIGFILENAME.  There can be more than one -f parameters
 * present.  If -p <ParameterName = ParameterValue> parameters are present then these
 * overide the default and the additional config file's settings, and are themselfes
 * overridden by future -p parameters.  There must be whitespace between -f and -p commands
 * and their respecitive parameters
 ***********************************************************************
 */

#define INCLUDED_BY_CONFIGFILE_C

#include <stdio.h>
#include <assert.h>

#include "global.h"
#include "configfile.h"
#include "map_hif.h" //jykim_20080715_HIF_CONV++

//static void init_conf (void);
//static void PatchInp (void);

unsigned int SampleRateX(void)
{
  unsigned int rate;
  rate = SENSOR_OUT_W << 21;
  rate /= IMAGE_OUT_W;
  return rate + 1;
}	

unsigned int SampleRateY(void)
{
  unsigned int rate;
  rate = SENSOR_OUT_H << 21;
  rate /= IMAGE_OUT_H;
  return rate + 1;
}	

unsigned int SampleRateX2(void)
{
  unsigned int rate;
  rate = SENSOR2_OUT_W << 21;
  rate /= IMAGE2_OUT_W;
  return rate + 1;
}	

unsigned int SampleRateY2(void)
{
  unsigned int rate;
  rate = SENSOR2_OUT_H << 21;
  rate /= IMAGE2_OUT_H;
  return rate + 1;
}	
//  // jarre 2009.06.09 for dual stream test +++
///////////////////////////////////////////////////////////////////

//jykim_20080715_HIF_CONV_tail++


/*!
 ***********************************************************************
 * \brief
 *    Parse the command line parameters and read the config files.
 * \param ac
 *    number of command line parameters
 * \param av
 *    command line parameters
 ***********************************************************************
 */
//void Configure (void)
//{
//  init_conf ();
//  PatchInp ();
//
//  //MSG(CONFIGURE);
//}
//

/*!
 ***********************************************************************
 * \brief
 *    Initialize input parameters with fixed values.
 *    For porting to ARM
 ***********************************************************************
 */
/*
##########################################################################################
# Loop filter parameters
##########################################################################################


LoopFilterParametersFlag = 0      # Configure loop filter (0=parameter below ingored, 1=parameters sent)
LoopFilterDisable        = 0      # Disable loop filter in slice header (0=Filter, 1=No Filter)
LoopFilterAlphaC0Offset  = 0      # Alpha & C0 offset div. 2, {-6, -5, ... 0, +1, .. +6}
LoopFilterBetaOffset     = 0      # Beta offset div. 2, {-6, -5, ... 0, +1, .. +6}
*/

//static void init_conf (void)
//{
//  int osb_fifo_rate_idx; //chae
//
////jykim_20080715_HIF_CONV_head++
//   //input.no_frames               = 65535;	// FramesToBeEncoded
//   input.img_width               = IMAGE_OUT_W * 16;	// SourceWidth
//   input.img_height              = IMAGE_OUT_H * 16;    // SourceHeight 
//   //input.img_width0              = IMAGE_OUT_W * 16;
//   //input.img_height0             = IMAGE_OUT_H * 16;
//   //input.img_width1              = IMAGE2_OUT_W * 16;
//   //input.img_height1             = IMAGE2_OUT_H * 16;
//
//   input.cam_width               = SENSOR_OUT_W * 16;	// SourceWidth
//   input.cam_height              = SENSOR_OUT_H * 16;    // SourceHeight 
//   //input.cam_width0              = SENSOR_OUT_W * 16;	// SourceWidth
//   //input.cam_height0             = SENSOR_OUT_H * 16;    // SourceHeight 
//   //input.cam_width1              = SENSOR2_OUT_W * 16;	// SourceWidth
//   //input.cam_height1             = SENSOR2_OUT_H * 16;    // SourceHeight 
////jykim_20080715_HIF_CONV_tail++
//	
//	//input.intra_period            = 5;	// IntraPeriod
//	input.intra_period            = INTRA_PERIOD;	// IntraPeriod
//	//input.qp0                     = 28;	// QPFirstFrame
//	input.qp0                     = QP_VALUE_I;	// QPFirstFrame
//	//input.qpN                     = 28;	// QPRemainingFrame
//	input.qpN                     = QP_VALUE_P;	// QPRemainingFrame
//	//input.jumpd                   = 0;	// FrameSkip
//	//input.jumpd                   = FRAME_SKIP;	// FrameSkip //090327_henry-
//	input.jumpd                   = 0;	// FrameSkip //090327_henry+
////enable_slice_mode: begin
// //input.slice_mode = 1;
// //input.slice_mode = SLICE_MODE;
// input.slice_mode = 0;
// //input.slice_argument = 12; //IP
// input.slice_argument = SLICE_ARGUMENT; //IP
// //input.slice_argument = 3; //IP
// //input.slice_argument = 10; //IP
// //input.slice_argument = 12; //IP
// //input.slice_argument = 20; //IP
// //input.slice_argument = 11; //IP
// //input.slice_argument = 50; //I
////enable_slice_mode: end
//
//
//    //input.LFSendParameters        = 1;      // LoopFilterParametersFlag 
//	 //if ( LOOP_FILTER_PARAMETERS_DISABLE_FLAG )
//     // input.LFSendParameters        = 0;      // LoopFilterParametersFlag 
//	 //else
//      input.LFSendParameters        = 1;      // LoopFilterParametersFlag 
//
////#ifdef USE_ADF	// shpark, 2008.02.16. in order to use ADF
//  //if ( USE_ADF )	// shpark, 2008.02.16. in order to use ADF
//    input.LFDisableIdc            = 0;    // LoopFilterEnable
////#else
//  //else
//  //  input.LFDisableIdc            = 1;    // LoopFilterDisable     
////#endif
//    //input.LFAlphaC0Offset         = -2;     // LoopFilterAlphaC0offset   
//    //input.LFBetaOffset            = -1;     // LoopFilterBetaOffset       
//    //input.LFAlphaC0Offset         =  LF_ALPHA_CO_OFFSET_VALUE;  //090409_jykim_remove_register-
//
//    //input.LFBetaOffset            =  LF_BETA_OFFSET_VALUE; //090409_jykim_remove_register-
//
//
//    input.LFAlphaC0Offset         =  ((char)LF_ALPHA_CO_OFFSET); //090409_jykim_remove_register+
//    input.LFBetaOffset            =  ((char)LF_BETA_OFFSET); //090409_jykim_remove_register+
//
//  	DCTQ_CR0 = 0x80;                                    //ME and IPDCTQ hardwired
//  	ME_CR11  = 0x80000000;                                    //ME and IPDCTQ hardwired
//////#ifdef H264E_MAX_VGA
////   if  ( H264E_MAX_VGA )
////  	  DCTQ_CR3 = (360 << 16) | ((input.img_width>>4)-1); // 360=number of Y,U,V neighbor pixels(D1) | image width in mb - 1
//////#else
////   else
//  	  DCTQ_CR3 = (640 << 16) | ((input.img_width>>4)-1); // 360=number of Y,U,V neighbor pixels(D1) | image width in mb - 1
////#endif
//
//
//  // Rate Control
//  // Target Spec.
//  // 1. QCIF 크기의 화면을 초당 15 frame 전송할 때에 
//  // 2. 전송률이 9.6kbps 에서 64kbps까지 변화시킬 수 있도록
//  // 3. 화질은 50kbps로 전송 시에 PSNR이 30dB 이상 되는 것을 목표 
//  //input.RCEnable = 0;
//   //if ( RATE_CONTROL_DISABLE_FLAG || (input.intra_period == 0))
//   //  input.RCEnable = 0;
//   // else
//   //  input.RCEnable = 1;
//
//	//input.bit_rate = 3686400; // 3600k
//	//input.bit_rate = 1843200; // 1800k
//	//input.bit_rate = 921600; // 900k
//	//input.bit_rate = 716800; // 700k
//	//input.bit_rate = 460800; // 450k
//	//input.bit_rate = 409600; // 400k
//	//input.bit_rate = 51200;    //  50k 
//	input.bit_rate =  RATE_CONTROL_BIT_RATE_VALUE;
//
//
//	//input.FrameRate = 11;     // init. frame rate is 15 following spec.
//	input.FrameRate = RATE_CONTROL_FRAME_RATE;     // init. frame rate is 15 following spec.
//	//input.SeinitialQP = 0;   // init. Quantization Parameter. If zero, calculate QP automatically.
//	input.SeinitialQP = RATE_CONTROL_SEINITIAL_QP_VALUE;   // init. Quantization Parameter. If zero, calculate QP automatically.
//        //for rate control test
//
//  // chae : OSB-SPI flow control
//  //osb_fifo_rate = {1,2,4,8,16,32}; fill : empty = 4 : 1 (when idx is 2)
//  //osb_fifo_rate_idx = 1;
//  osb_fifo_rate_idx = OSB_FIFO_RATE_IDX;
//  OSB_FILL_RATE =  osb_fifo_rate_idx;
//
////#ifdef SPEED_CONTROL
////  if ( SPEED_CONTROL )
////  {
//////--------- VGA 
//// //img.prevf_enc_time      = 49200  + 986000;
//// //img.targetfr_enc_time   = 49200 +  986000;//1230*40 + 850*1160 : target frame encoding time(not include extra switch time) 
//// //img.targetmb_enc_time   = 850;
//// //SPEED_CONTROL_TARGET_MB = 850;           //SPEED_CONTROL_TARGET_FR/tot_mb_nr;
//// //SPEED_CONTROL_TARGET_FR = img.targetfr_enc_time;
//// //img.prevf_enc_time      = 49200  + 928000;
//// //img.targetfr_enc_time   = 49200 +  928000;//1230*40 + 850*1160 : target frame encoding time(not include extra switch time) 
//// //img.targetmb_enc_time   = 800;
//// //SPEED_CONTROL_TARGET_MB = 800;           //SPEED_CONTROL_TARGET_FR/tot_mb_nr;
//// //SPEED_CONTROL_TARGET_FR = img.targetfr_enc_time;
//////--------- HD 
//// //img.prevf_enc_time      = 98400  + 3520000;
//// //img.targetfr_enc_time   = 98400 +  3520000;//1230*80 + 850*3520 : target frame encoding time(not include extra switch time) 
//// //img.targetmb_enc_time   = 1000;
//// //SPEED_CONTROL_TARGET_MB = 1000;           //SPEED_CONTROL_TARGET_FR/tot_mb_nr;
//// //SPEED_CONTROL_TARGET_FR = img.targetfr_enc_time;
//// //img.prevf_enc_time      = 98400  + 2886400;
//// //img.targetfr_enc_time   = 98400 +  2886400;//1230*80 + 850*3520 : target frame encoding time(not include extra switch time) 
//// //img.targetmb_enc_time   = 820;
//// //SPEED_CONTROL_TARGET_MB = 820;           //SPEED_CONTROL_TARGET_FR/tot_mb_nr;
//// //SPEED_CONTROL_TARGET_FR = img.targetfr_enc_time;
//// //img.prevf_enc_time      = 98400  + 2534400;
//// //img.targetfr_enc_time   = 98400 +  2534400;//1230*80 + 850*3520 : target frame encoding time(not include extra switch time) 
//// //img.targetmb_enc_time   = 720;
//// //SPEED_CONTROL_TARGET_MB = 720;           //SPEED_CONTROL_TARGET_FR/tot_mb_nr;
//// //SPEED_CONTROL_TARGET_FR = img.targetfr_enc_time;
//////#endif
////
////  img.targetmb_enc_time = SPEED_CONTROL_MB_CYCLE_VALUE;
////
////  img.targetfr_enc_time = (input.img_width / 16) * ( 1230 + ( (input.img_height / 16) - 1 ) * img.targetmb_enc_time); 
////  img.prevf_enc_time  = img.targetfr_enc_time;
////
////  SPEED_CONTROL_TARGET_MB = img.targetmb_enc_time;
////  SPEED_CONTROL_TARGET_FR = img.targetfr_enc_time;
////
////  }
////
//
//
//  //MSG(INIT_CONF);
//}
//
///*!
// ***********************************************************************
// * \brief
// *    Checks the input parameters for consistency.
// ***********************************************************************
// */
//static void PatchInp (void)
//{
//  // consistency check of QPs
//  if (input.qp0 > MAX_QP || input.qp0 < MIN_QP)
//  {
//	 //EXIT(0x190); 
//  }
//
//  if (input.qpN > MAX_QP || input.qpN < MIN_QP)
//  {
//	 //EXIT(0x190); 
//  }
// 
//  // consistency check size information
//
//  if ((input.img_height & 0xf) != 0 || (input.img_width & 0xf) != 0)
//  //if (input.img_height % 16 != 0 || input.img_width % 16 != 0)
//  {
//	 //EXIT(0x190); 
//  }
//
//  // check range of filter offsets
//  if (input.LFAlphaC0Offset > 6 || input.LFAlphaC0Offset < -6)
//  {
//	 //EXIT(0x190); 
//  }
//
//  if (input.LFBetaOffset > 6 || input.LFBetaOffset < -6)
//  {
//	 //EXIT(0x190); 
//  }
//
//  // Set block sizes
//
//    input.blc_size[0][0]=16;
//    input.blc_size[0][1]=16;
//
//    input.blc_size[1][0]=16;
//    input.blc_size[1][1]=16;
//
//    input.blc_size[2][0]=16;
//    input.blc_size[2][1]= 8;
//
//    input.blc_size[3][0]= 8;
//    input.blc_size[3][1]=16;
//
//    input.blc_size[4][0]= 8;
//    input.blc_size[4][1]= 8;
//
//    input.blc_size[5][0]= 8;
//    input.blc_size[5][1]= 4;
//
//    input.blc_size[6][0]= 4;
//    input.blc_size[6][1]= 8;
//
//    input.blc_size[7][0]= 4;
//    input.blc_size[7][1]= 4;
//
//  // End JVT-D095, JVT-D097
//  //MSG(PATCH_INP);
//}
