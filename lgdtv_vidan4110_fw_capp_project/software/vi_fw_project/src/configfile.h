/*!
 ***********************************************************************
 *  \file
 *     configfile.h
 *  \brief
 *     Prototypes for configfile.c and definitions of used structures.
 ***********************************************************************
 */

#ifndef _CONFIGFILE_H_
#define _CONFIGFILE_H_

#define MODE_QCIF 0
#define MODE_D1   1
#define MODE_VGA  2
#define MODE_QVGA  3
#define MODE_HD  4

//void PatchInputNoFrames(void);
//void Configure (void);


//jykim_20080715_HIF_CONV_head++
unsigned int SampleRateX(void); 
unsigned int SampleRateY(void); 
//unsigned int SampleRateX1(void);   // jarre 2009.06.09 for dual stream test +++
//unsigned int SampleRateY1(void);   // jarre 2009.06.09 for dual stream test +++
unsigned int SampleRateX2(void);   // jarre 2009.06.09 for dual stream test +++
unsigned int SampleRateY2(void);   // jarre 2009.06.09 for dual stream test +++

//void ParamToHIFConv(void); 

//extern int ORC_SYS_KIND;  //<== Move from map.h

//SW control
//extern int LTCTRL_SW_SELFCONTROL; //<== Move from map.h

//extern int LTCTRL_SW_CAM_HD; //<== Move from map.h

//extern int LTCTRL_SW_DOWNSAMPLING; //<== Move from map.h

//extern int LTCTRL_SW_ISP; //<== Move from map.h

//extern int LTCTRL_SW_UART_CONTROL; //<== Move from map.h

//extern int LTCTRL_SW_FREERUN; //<== Move from map.h

//extern int LTCTRL_SW_HIF_CONTROL; //<== Move from map.h

//Define control
//extern int H264E_SXGA_TO_VGA;

//extern int SLICE_MODE;

//extern int USE_ADF;

//extern int H264E_MAX_VGA;

//extern int SPEED_CONTROL;

//extern int OFFSET_CONTROL;

//extern int NO_FASTME;

//extern int ME_EARLY_TERMINATION;

//extern int H264E_SAFE_MODE;

//extern int TEST_DEFINE;


//jykim_20080715_HIF_CONV_tail++

#endif
