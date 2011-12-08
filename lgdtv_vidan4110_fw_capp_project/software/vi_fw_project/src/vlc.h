
/*!
 *************************************************************************************
 * \file vlc.h
 *
 * \brief
 *    Prototypes for VLC coding funtions
 * \author
 *     Karsten Suehring
 *************************************************************************************
 */

#ifndef _VLC_H_
#define _VLC_H_

#include <global.h>

int u_1 (int value);
int se_v (int value);
int ue_v (int value);
int u_v (int n, int value);


//void levrun_linfo_c2x2(int level,int run,int *len,int *info);
//void levrun_linfo_intra(int level,int run,int *len,int *info);
//void levrun_linfo_inter(int level,int run,int *len,int *info);

void  writeSyntaxElement_UVLC(SyntaxElement *se);
void  writeSyntaxElement_fixed(SyntaxElement *se);
void  writeSyntaxElement2Buf_UVLC(SyntaxElement *se);
void  writeUVLC2buffer(SyntaxElement *se);
void  writeSyntaxElement2Buf_Fixed(SyntaxElement *se);
int   symbol2uvlc(SyntaxElement *se);
void  ue_linfo(int n, int *len,int *info);
void  se_linfo(int mvd, int *len,int *info);
//void  cbp_linfo_intra(int cbp, int *len,int *info);
//void  cbp_linfo_inter(int cbp, int *len,int *info);

// CAVLC
void  CAVLC_init(void);
//int writeCoeff4x4_CAVLC (int block_type, int b8, int b4, int param);
//
//void  writeSyntaxElement_VLC(SyntaxElement *se);
//void  writeSyntaxElement_TotalZeros(SyntaxElement *se);
//void  writeSyntaxElement_TotalZerosChromaDC(SyntaxElement *se);
//void  writeSyntaxElement_Run(SyntaxElement *se);
//void  writeSyntaxElement_NumCoeffTrailingOnes(SyntaxElement *se);
//void  writeSyntaxElement_NumCoeffTrailingOnesChromaDC(SyntaxElement *se);
//void  writeSyntaxElement_Level_VLC1(SyntaxElement *se);
//void  writeSyntaxElement_Level_VLCN(SyntaxElement *se, int vlc);
void  writeSyntaxElement_Intra4x4PredictionMode(SyntaxElement *se);

// OSC Simulation
void  OutputStreamController(int, int);
//int   file_out(void);

#endif

