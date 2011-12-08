/*!
 ***************************************************************************
 * \file
 *    ratectl.h
 *
 * \author
 *    Zhengguo LI
 *
 * \date
 *    14 Jan 2003
 *
 * \brief
 *    Headerfile for rate control 
 **************************************************************************
 */

#ifndef _RATE_CTL_H_
#define _RATE_CTL_H_

#define MIN(a,b)  (((a)<(b)) ? (a) : (b))//LIZG 28/10/2002
#define MAX(a,b)  (((a)<(b)) ? (b) : (a))//LIZG 28/10/2002
//#define RC_MODEL_HISTORY 21 
//#define RC_MODEL_HISTORY 15 
#define RC_MODEL_HISTORY 8 

//void rc_alloc(void);
//void rc_free(void);

void rc_init_seq(void);
//void rc_init_GOP(int np);
void rc_update_pict_frame();
void rc_init_pict(void);
void rc_update_pict(int nbits);

int updateQuantizationParameter(void);
void updateRCModel(void);
void updateMADModel(void);
Boolean skipThisFrame(void);
void RCModelEstimator(int n_windowSize);
void MADModelEstimator(int n_windowSize);
float ComputeFrameMAD(void);
int Qstep2QP(float Qstep);
float QP2Qstep(int QP);

#endif

