/*!
 ***************************************************************************
 * \file ratectl.c
 *
 * \brief
 *    Rate Control algorithm
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details) 
 *     - Siwei Ma <swma@jdl.ac.cn>
 *     - Zhengguo LI<ezgli@lit.a-star.edu.sg>
 *
 * \date
 *   16 Jan. 2003
 **************************************************************************
 */

//#include <stdlib.h>
#include <math.h>

#include "global.h"
#include "ratectl.h"
#include "tube.h"
#include "map_hif.h" //090409_jykim_bit_rate_realtime_control+
#define BUFFER_SIZE       0x300000   // 3000Kbits
#define INIT_BUFFER_SIZE  (BUFFER_SIZE >> 3)
#define INIT_DELAY_OFFSET ((BUFFER_SIZE * 3) >> 2)

//#define RC_MAX_QUANT 51
//#define RC_MIN_QUANT 0
#define RC_MAX_QUANT 29
#define RC_MIN_QUANT 22
//#define PDuantQp  2  //Define the largest variation of quantization parameters
#define PDuantQp  1  //Define the largest variation of quantization parameters
#define OMEGA 0.9

const float QP2QSTEP[6] = { 0.625, 0.6875, 0.8125, 0.875, 1.0, 1.125 };

int br_div_fr; //chae
int CurrentBufferFullness; //LIZG 25/10/2002
int TargetBufferLevel;//LIZG 25/10/2002
int PAverageQp;

/*LIZG JVT50V2 distortion prediction model*/
/*coefficients of the prediction model*/
float PMADPictureC1;
float PMADPictureC2;
/* LIZG JVT50V2 picture layer MAD */
float PictureMAD[RC_MODEL_HISTORY];
float ReferenceMAD[RC_MODEL_HISTORY];

/*quadratic rate-distortion model*/
float m_rgQp[RC_MODEL_HISTORY];
float m_rgRp[RC_MODEL_HISTORY];
int m_Qc;
int PPreHeader;

float CurrentFrameMAD;
float PreviousFrameMAD;

float Pm_X1;
float Pm_X2;

/* rate control variables */
int R, Np;
int T;
//HRD consideration
int UpperBound1, LowerBound;

int DeltaP;

/***************

 math.h ´ëÃ¼.

 ****************/
//float fabs_new(float num)
//{
//  return (num>0 ? num : -num);
//}

/*! 
 *************************************************************************************
 * \brief
 *    Dynamically allocate memory needed for rate control
 *
 *************************************************************************************
 */
//void rc_alloc()
//{
//  int i;
//  TUBE_0_PRINT_WORD(img.FrameSizeInMbs * sizeof (int));
//  img.MADofMB = (int*) malloc (img.FrameSizeInMbs * sizeof (int));
//  TUBE_0_PRINT_WORD(img.MADofMB);
//   
//  if (NULL==img.MADofMB)
//    no_mem_exit("rc_alloc: img.MADofMB");
//  else
//  {
//    for(i=0;i<img.FrameSizeInMbs;i++) img.MADofMB[i] = 0;
//  }
//}

/*! 
 *************************************************************************************
 * \brief
 *    Free memory needed for rate control
 *
 *************************************************************************************
 */
//void rc_free()
//{
//  if (NULL!=img.MADofMB)
//  {
//    free (img.MADofMB);
//    img.MADofMB = NULL;
//  }
//}


/*! 
 *************************************************************************************
 * \brief
 *    Initialize rate control parameters
 *
 *************************************************************************************
 */
//kik---  void rc_init_seq() {
//kik---  	float L1, L2, L3, bpp;
//kik---  	int qp;
//kik---  	int i;
//kik---  
//kik---  	img.NumberofCodedPFrame = 0;
//kik---  
//kik---  	// frame rate / bit rate
//kik---  	img.framerate = input.FrameRate;
//kik---  	br_div_fr = input.bit_rate / img.framerate; //chae
//kik---  
//kik---  	/*compute the total number of MBs in a frame*/
//kik---  	img.Frame_Total_Number_MB = (img.width * img.height) >> 8; // Size of MB is 16x16
//kik---  
//kik---  	//MINVALUE=4.0;   // minimum value of QP is 4...?
//kik---  
//kik---  	/*initialize the parameters of fluid flow traffic model*/
//kik---  	// TO DO : appropriate buffer size & target buffer level & initial delay. => constant buffer size.
//kik---  	CurrentBufferFullness = INIT_BUFFER_SIZE; // currently, fullness is zero
//kik---  
//kik---  	/*HRD consideration*/
//kik---  	//InitialDelayOffset=BufferSize*0.75;   // For Hypothetical Reference Decoder(HRD), we need initial delay.
//kik---  	//InitialDelayOffset = (BUFFER_SIZE * 3) >> 2; // For Hypothetical Reference Decoder(HRD), we need initial delay.
//kik---  
//kik---  	/* initialize the previous window size */
//kik---  	img.NumberofGOP = 0;
//kik---  
//kik---  	/* R : remaining # of bits in GOP */
//kik---  	R = 0;
//kik---  
//kik---  	/* control parameter (in case of zero B frame) */
//kik---  	//  GAMMAP=0.5;
//kik---  	//  BETAP=0.5;
//kik---  
//kik---  	/* quadratic rate-distortion model (R-D model) */
//kik---  	PPreHeader = 0;
//kik---  	// initial value of X1 is bit rate; X2 is zero.
//kik---  	Pm_X1 = (float) input.bit_rate;
//kik---  	Pm_X2 = 0.0;
//kik---  
//kik---  	/* linear prediction model for P picture*/
//kik---  	PMADPictureC1 = 1.0;
//kik---  	PMADPictureC2 = 0.0;
//kik---  
//kik---  	for (i = 0; i < RC_MODEL_HISTORY; i++) {
//kik---  		PictureMAD[i] = 0.0;
//kik---  	}
//kik---  
//kik---  	/* compute the initial QP */
//kik---  	// JVT-H014 : Adaptive Rate Control with HRD Consideration
//kik---  	bpp = 1.0 * input.bit_rate / (img.framerate * img.width * img.height);
//kik---  	if (img.width == 176) // QCIF
//kik---  	{
//kik---  		L1 = 0.1;
//kik---  		L2 = 0.3;
//kik---  		L3 = 0.6;
//kik---  	} else if (img.width == 352) // CIF
//kik---  	{
//kik---  		L1 = 0.2;
//kik---  		L2 = 0.6;
//kik---  		L3 = 1.2;
//kik---  	} else {
//kik---  		L1 = 0.6;
//kik---  		L2 = 1.4;
//kik---  		L3 = 2.4;
//kik---  	}
//kik---  
//kik---  	if (input.SeinitialQP == 0) {
//kik---  		if (bpp <= L1)
//kik---  			qp = 35;
//kik---  		else if (bpp <= L2)
//kik---  			qp = 25;
//kik---  		else if (bpp <= L3)
//kik---  			qp = 20;
//kik---  		else
//kik---  			qp = 10;
//kik---  		input.SeinitialQP = qp;
//kik---  	}
//kik---  }

/*! 
 *************************************************************************************
 * \brief
 *    Initialize one GOP
 *
 *************************************************************************************
 */
//void rc_init_GOP(int np) {
//	int AllocatedBits;
//	//int PAverageQp;
//	int GOPDquant;
//
//	//090409_jykim_bit_rate_realtime_control_head+
//	// frame rate / bit rate
//	img.framerate = input.FrameRate = RATE_CONTROL_FRAME_RATE;
//	input.bit_rate = RATE_CONTROL_BIT_RATE_VALUE;
//	br_div_fr = input.bit_rate / img.framerate; //chae
//	//090409_jykim_bit_rate_realtime_control_tail+
//
//
//	/*initialize the lower bound and the upper bound for the target bits of each frame, HRD consideration*/
//	LowerBound = R + (br_div_fr >> 1);
//	UpperBound1 = R + INIT_DELAY_OFFSET;
//
//	/* compute the total number of bits for the current GOP */
//	/* 1+np = np + number of I frame (1) = total frames
//	 Allocated Bits = (# Frame) * (bitrate/framerate) = total bits in GOP
//	 floor(x+0.5) = round(x) */
//	AllocatedBits = (int) ((1 + np) * br_div_fr);
//	R += AllocatedBits;
//	Np = np;
//	/*Compute InitialQp for each GOP*/
//	img.NumberofGOP++;
//	if (img.NumberofGOP != 1) // first GOP
//	{
//		/*compute the average QP of P frames in the previous GOP*/
//		PAverageQp = (int) (1.0 * img.TotalQpforPPicture / img.NumberofPPicture
//				+ 0.5);
//
//		// reduce by 1 per 30 frames.
//		GOPDquant = (int) (0.5 + (np + 1) / 15.0);
//		if (GOPDquant > 2)
//			GOPDquant = 2;
//		PAverageQp -= GOPDquant;
//
//		// limiter
//		PAverageQp = MAX(img.qp - 2, PAverageQp);
//		PAverageQp = MIN(img.qp + 2, PAverageQp);
//		PAverageQp = MIN(RC_MAX_QUANT, PAverageQp);
//		PAverageQp = MAX(RC_MIN_QUANT, PAverageQp);
//
//		input.SeinitialQP = PAverageQp;
//	}
//
//	img.TotalQpforPPicture = 0;
//	img.NumberofPPicture = 0;
//}

/*! 
 *************************************************************************************
 * \brief
 *    Initialize one picture
 *
 *************************************************************************************
 */
//kik---  void rc_init_pict() {
//kik---  	int T1;
//kik---  	int UpperBound2;
//kik---  
//kik---  	img.framerate = input.FrameRate = RATE_CONTROL_FRAME_RATE;
//kik---  
//kik---  	input.PrevBitRate = input.bit_rate;
//kik---  	input.bit_rate = RATE_CONTROL_BIT_RATE_VALUE;
//kik---  	br_div_fr = input.bit_rate / img.framerate;
//kik---  
//kik---  	/* predefine a target buffer level for each frame */
//kik---  	if (img.type == P_SLICE) {
//kik---  
//kik---  		//RC1018 begin
//kik---  		if (input.PrevBitRate != input.bit_rate) {
//kik---  
//kik---  			R += (int) ((input.bit_rate - input.PrevBitRate) * (Np)
//kik---  					/ img.framerate + 0.5);
//kik---  		}
//kik---  		//RC1018 end
//kik---  
//kik---  
//kik---  		/* predefine the target buffer level for each picture.
//kik---  		 frame layer rate control */
//kik---  		if (img.NumberofPPicture == 1) {
//kik---  			TargetBufferLevel = CurrentBufferFullness;
//kik---  			DeltaP = (CurrentBufferFullness - INIT_BUFFER_SIZE) / Np;
//kik---  			TargetBufferLevel -= DeltaP;
//kik---  		} else if (img.NumberofPPicture > 1)
//kik---  			TargetBufferLevel -= DeltaP;
//kik---  
//kik---  		/* Compute the target bit for each frame */
//kik---  		// Z.G.Li, et al. Adaptive Rate Control For H.264, 2004 Internatilna Conference on Image Processing
//kik---  		if (img.NumberofCodedPFrame > 0) {
//kik---  			T = R / Np;
//kik---  
//kik---  			T1 = br_div_fr - ((CurrentBufferFullness - TargetBufferLevel) >> 1); // GAMMAP = 0.5
//kik---  			T1 = MAX(0, T1);
//kik---  			T = (T + 3 * T1) >> 2;
//kik---  		}
//kik---  
//kik---  		/* HRD consideration */
//kik---  		UpperBound2 = (UpperBound1 * 7) >> 3; //0.875*UpperBound1;
//kik---  		T = MAX(T, (long) LowerBound);
//kik---  		T = MIN(T, (long) UpperBound2);
//kik---  	}
//kik---  
//kik---  	/* frame layer rate control */
//kik---  	img.NumberofHeaderBits = 0;
//kik---  	img.NumberofTextureBits = 0;
//kik---  }
//kik---  
/*! 
 *************************************************************************************
 * \brief
 *    update one picture after frame/field encoding
 *
 * \param nbits
 *    number of bits used for picture
 *
 *************************************************************************************
 */
void rc_update_pict(int nbits) {
	int ExcessBits = nbits - br_div_fr;
	R -= nbits; /* remaining # of bits in GOP */
	CurrentBufferFullness += ExcessBits;

	/*update the lower bound and the upper bound for the target bits of each frame, HRD consideration*/
	LowerBound -= ExcessBits;
	UpperBound1 -= ExcessBits;

}

/*! 
 *************************************************************************************
 * \brief
 *    update after frame encoding
 *
 * \param nbits
 *    number of bits used for frame
 *
 *************************************************************************************
 */
void rc_update_pict_frame() {
	if (img.type == P_SLICE) {
		Np--;
		img.NumberofCodedPFrame++;
		img.NumberofPPicture++;
	}
}

/*! 
 *************************************************************************************
 * \brief
 *    compute a  quantization parameter for each frame
 *
 *************************************************************************************
 */
//kik---   int updateQuantizationParameter() {
//kik---   	int m_Qp;
//kik---   	float m_Qstep;
//kik---   
//kik---   	float m_X1;
//kik---   	float m_X2;
//kik---   
//kik---   	float MADPictureC1;
//kik---   	float MADPictureC2;
//kik---   
//kik---   	float dtmp;
//kik---   	int m_Bits;
//kik---   	float PreviousPictureMAD;
//kik---   
//kik---   	/* frame layer rate control */
//kik---   	/* fixed quantization parameter is used to coded I frame, the first P frame and the first B frame
//kik---   	 the quantization parameter is adjusted according the available channel bandwidth and
//kik---   	 the type of vide */
//kik---   	if (img.type == I_SLICE) {
//kik---   		m_Qc = input.SeinitialQP;
//kik---   		//uart_printInt(m_Qc);
//kik---   	} else if ((img.type == P_SLICE) && (img.NumberofPPicture == 0)) {
//kik---   		img.TotalQpforPPicture += m_Qc;
//kik---   	} else {
//kik---   		m_X1 = Pm_X1;
//kik---   		m_X2 = Pm_X2;
//kik---   		m_Qp = m_Qc;
//kik---   		MADPictureC1 = PMADPictureC1;
//kik---   		MADPictureC2 = PMADPictureC2;
//kik---   		PreviousPictureMAD = PictureMAD[0];
//kik---   
//kik---   		/* predict the MAD of current picture*/
//kik---   		CurrentFrameMAD = MADPictureC1 * PreviousPictureMAD + MADPictureC2;
//kik---   
//kik---   		/*compute the number of bits for the texture*/
//kik---   		if (T < 0) {
//kik---   			m_Qc = m_Qc + PDuantQp;
//kik---   			m_Qc = MIN(m_Qc, RC_MAX_QUANT); // clipping
//kik---   		} else {
//kik---   			m_Bits = T - PPreHeader;
//kik---   			m_Bits = MAX(m_Bits, (br_div_fr >> 2)); // MINVALUE = 4
//kik---   
//kik---   			dtmp = CurrentFrameMAD * m_X1 * CurrentFrameMAD * m_X1 + 4 * m_X2
//kik---   					* CurrentFrameMAD * m_Bits;
//kik---   			if ((m_X2 == 0.0) || (dtmp < 0) || ((sqrt(dtmp) - m_X1
//kik---   					* CurrentFrameMAD) <= 0.0)) // fall back 1st order mode
//kik---   				m_Qstep = (float) (m_X1 * CurrentFrameMAD / (double) m_Bits);
//kik---   			else
//kik---   				// 2nd order mode
//kik---   				m_Qstep = (float) ((2 * m_X2 * CurrentFrameMAD) / (sqrt(dtmp)
//kik---   						- m_X1 * CurrentFrameMAD));
//kik---   
//kik---   			m_Qc = Qstep2QP(m_Qstep);
//kik---   			m_Qc = MIN(m_Qp + PDuantQp, m_Qc); // control variation
//kik---   			m_Qc = MIN(m_Qc, RC_MAX_QUANT); // clipping
//kik---   			m_Qc = MAX(m_Qp - PDuantQp, m_Qc); // control variation
//kik---   			m_Qc = MAX(RC_MIN_QUANT, m_Qc);
//kik---   		}
//kik---   
//kik---   		img.TotalQpforPPicture += m_Qc;
//kik---   	}
//kik---   
//kik---   	return m_Qc;
//kik---   }

/*! 
 *************************************************************************************
 * \brief
 *    update the parameters of quadratic R-D model
 *
 *************************************************************************************
 */
//hjlee begin 2010.06.25
//void updateRCModel() {
//	int n_windowSize;
//	int i;
//	//  float error[RC_MODEL_HISTORY], std = 0, threshold;
//
//	if (img.type == P_SLICE) {
//		/// compute average MAD of all MBs.
//		CurrentFrameMAD = ComputeFrameMAD();
//
//		PPreHeader = img.NumberofHeaderBits;
//
//		// update the history
//		for (i = (RC_MODEL_HISTORY - 2); i > 0; i--) {
//			//Pm_rgQp[i] = Pm_rgQp[i - 1];
//			//m_rgQp[i]  = Pm_rgQp[i];
//			//Pm_rgRp[i] = Pm_rgRp[i - 1];
//			//m_rgRp[i]  = Pm_rgRp[i];
//			m_rgQp[i] = m_rgQp[i - 1];
//			m_rgRp[i] = m_rgRp[i - 1];
//		}
//		m_rgQp[0] = QP2Qstep(m_Qc);
//		m_rgRp[0] = (img.NumberofTextureBits + PPreHeader) / CurrentFrameMAD;
//
//		n_windowSize = MIN(img.NumberofCodedPFrame, (RC_MODEL_HISTORY - 1));
//
//		RCModelEstimator(n_windowSize);
//
//		if (img.NumberofCodedPFrame > 1)
//			updateMADModel();
//		else
//			//if(img.type==P_SLICE)
//			PictureMAD[0] = CurrentFrameMAD;
//	}
//}

/*! 
 *************************************************************************************
 * \brief
 *    Model Estimator
 *
 *************************************************************************************
 */
//void RCModelEstimator(int n_windowSize) {
//	float m_X1;
//	float m_X2;
//
//	int n_realSize = n_windowSize;
//	int i;
//	float oneSampleQ;
//	float a00 = 0.0, a01 = 0.0, a10 = 0.0, a11 = 0.0, b0 = 0.0, b1 = 0.0;
//	float MatrixValue;
//	Boolean estimateX2 = FALSE;
//	float curr_1_Qstep;
//
//	// default RD model estimation results
//	m_X1 = m_X2 = 0.0;
//
//	// find the number of samples which are not rejected
//	oneSampleQ = m_rgQp[0];
//	for (i = 0; i < n_windowSize; i++) {
//		curr_1_Qstep = 1.0 / m_rgQp[i];
//
//		// 2nd order
//		a00 = a00 + 1.0;
//		a01 += curr_1_Qstep;
//		//a10 = a01;
//		a11 += curr_1_Qstep * curr_1_Qstep;
//		b0 += m_rgQp[i] * m_rgRp[i];
//		b1 += m_rgRp[i];
//	}
//
//	// if all non-rejected Q are the same, take 1st order model
//	for (i = 0; i < n_windowSize; i++) {
//		m_X1 += (m_rgQp[i] * m_rgRp[i]) / n_realSize;
//		if (m_rgQp[i] != oneSampleQ)
//			estimateX2 = TRUE;
//	}
//
//	// take 2nd order model to estimate X1 and X2
//	if (estimateX2) {
//		a10 = a01;
//		// solve the equation of AX = B
//		MatrixValue = a00 * a11 - a01 * a10;
//		if (fabs(MatrixValue) > 0.000001) {
//			//m_X1=(b0*a11-b1*a01)/MatrixValue;
//			//m_X2=(b1*a00-b0*a10)/MatrixValue;
//			MatrixValue = 1.0 / MatrixValue;
//			m_X1 = (b0 * a11 - b1 * a01) * MatrixValue;
//			m_X2 = (b1 * a00 - b0 * a10) * MatrixValue;
//		} else {
//			m_X1 = b0 / a00;
//			m_X2 = 0.0;
//		}
//
//	}
//	if (img.type == P_SLICE) {
//		Pm_X1 = m_X1;
//		Pm_X2 = m_X2;
//	}
//}
//

/*! 
 *************************************************************************************
 * \brief
 *    Compute Frame MAD
 *
 *************************************************************************************
 */
//float ComputeFrameMAD() {
//	//chae :it's just the last MB's mincost. should be modified!!!
//	int SAD;
//	float MAD;
//	SAD = ME_FR_TOT_COST;
//	MAD = (float) SAD / (float) (256 * img.width * img.height);
//	return MAD;
//}

/*! 
 *************************************************************************************
 * \brief
 *    update the parameters of linear prediction model
 *
 *************************************************************************************
 */
//void updateMADModel() {
//	float MADPictureC1;
//	float MADPictureC2;
//
//	int n_windowSize;
//	int i;
//	//  float error[RC_MODEL_HISTORY], std = 0.0, threshold;
//
//	if (img.NumberofCodedPFrame > 0) {
//		// update the history
//		for (i = (RC_MODEL_HISTORY - 2); i > 0; i--) {
//			//PPictureMAD[i]  = PPictureMAD[i-1];
//			//PictureMAD[i]   = PPictureMAD[i];
//			PictureMAD[i] = PictureMAD[i - 1];
//			ReferenceMAD[i] = ReferenceMAD[i - 1];
//		}
//		//PPictureMAD[0]  = CurrentFrameMAD;
//		//PictureMAD[0]   = PPictureMAD[0];
//		PictureMAD[0] = CurrentFrameMAD;
//		ReferenceMAD[0] = PictureMAD[1];
//		MADPictureC1 = PMADPictureC1;
//		MADPictureC2 = PMADPictureC2;
//
//		//update the MAD for the previous frame
//		if (img.type == P_SLICE)
//			PreviousFrameMAD = CurrentFrameMAD;
//
//		n_windowSize = MIN((img.NumberofCodedPFrame - 1),
//				(RC_MODEL_HISTORY - 1));
//		n_windowSize = MIN(1, n_windowSize);
//
//		MADModelEstimator(n_windowSize);
//	}
//}


/*! 
 *************************************************************************************
 * \brief
 *    MAD mode estimator
 *
 *************************************************************************************
 */
//void MADModelEstimator(int n_windowSize) {
//	float MADPictureC1;
//	float MADPictureC2;
//
//	int n_realSize = n_windowSize;
//	int i;
//	float oneSampleQ;
//	float a00 = 0.0, a01 = 0.0, a10 = 0.0, a11 = 0.0, b0 = 0.0, b1 = 0.0;
//	float MatrixValue;
//	Boolean estimateX2 = FALSE;
//
//	// default MAD model estimation results
//	MADPictureC1 = MADPictureC2 = 0.0;
//
//	// find the number of samples which are not rejected
//	oneSampleQ = PictureMAD[0];
//	for (i = 0; i < n_windowSize; i++) {
//		// 2nd order
//		a00 = a00 + 1.0;
//		a01 += ReferenceMAD[i];
//		//a10 = a01;
//		a11 += ReferenceMAD[i] * ReferenceMAD[i];
//		b0 += PictureMAD[i];
//		b1 += PictureMAD[i] * ReferenceMAD[i];
//	}
//
//	// if all non-rejected MAD are the same, take 1st order model
//	for (i = 0; i < n_windowSize; i++) {
//		MADPictureC1 += PictureMAD[i] / (ReferenceMAD[i] * n_realSize);
//		if (PictureMAD[i] != oneSampleQ)
//			estimateX2 = TRUE;
//	}
//
//	// take 2nd order model to estimate X1 and X2
//	if (estimateX2) {
//		a10 = a01;
//		// solve the equation of AX = B
//		MatrixValue = a00 * a11 - a01 * a10;
//		if (fabs(MatrixValue) > 0.000001) {
//			//MADPictureC2=(b0*a11-b1*a01)/MatrixValue;
//			//MADPictureC1=(b1*a00-b0*a10)/MatrixValue;
//			MatrixValue = 1.0 / MatrixValue;
//			MADPictureC2 = (b0 * a11 - b1 * a01) * MatrixValue;
//			MADPictureC1 = (b1 * a00 - b0 * a10) * MatrixValue;
//		} else {
//			MADPictureC1 = b0 / a01;
//			MADPictureC2 = 0.0;
//		}
//	}
//	if (img.type == P_SLICE) {
//		PMADPictureC1 = MADPictureC1;
//		PMADPictureC2 = MADPictureC2;
//	}
//}


/*! 
 *************************************************************************************
 * \brief
 *    map QP to Qstep
 *
 *************************************************************************************
 */
//float QP2Qstep(int QP) {
//	int tmp_for_mul = 1;
//	int QP_tmp = 6;
//	float Qstep;
//
//	while (QP >= QP_tmp) {
//		tmp_for_mul = tmp_for_mul << 1;
//		QP_tmp += 6;
//	}
//	QP_tmp -= 6;
//	Qstep = QP2QSTEP[QP - QP_tmp] * tmp_for_mul;
//
//	return Qstep;
//}

/*! 
 *************************************************************************************
 * \brief
 *    map Qstep to QP
 *
 *************************************************************************************
 */
//int Qstep2QP(float Qstep) {
//	int Qstepx32_int = (int) (Qstep * 32);
//	int qp = 0;

	/////////////////////////////////////////////////////////////////
	//                                                             //
	//                         20                              22  //
	// QP2Qstep(0) = 0.6250 = ----     QP2Qstep(1) = 0.6875 = ---- //
	//                         32                              32  //
	//                                                             //
	//                         26                              28  //
	// QP2Qstep(2) = 0.8125 = ----     QP2Qstep(3) = 0.8750 = ---- //
	//                         32                              32  //
	//                                                             //
	//                         32                              36  //
	// QP2Qstep(4) = 1.0000 = ----     QP2Qstep(5) = 1.1250 = ---- //
	//                         32                              32  //
	//                                                             //
	/////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////
	//                                                              //
	//  Qstepx32 |  19-20   21-23   24-26   27-29   30-33   34-37   //
	// ----------|------------------------------------------------- //
	//     QP    |    0       1       2       3       4       5     //
	//                                                              //
	//////////////////////////////////////////////////////////////////

//	if (Qstepx32_int <= 20) // QP2Qstep(0) = 0.625 * 32 = 20
//		return 0;
//	else if (Qstepx32_int >= 7168) // QP2Qstep(51) = (0.875 * 256) * 32 = 7168
//		return 51;
//
//	while (Qstepx32_int >= 38) // ((1.125+1.25)/2) * 32 = 38
//	{
//		Qstepx32_int = Qstepx32_int >> 1;
//		qp += 6;
//	}
//
//	if (Qstepx32_int < 21) // ((0.6250+0.6875)/2) * 32 = 21
//		return qp;
//	else if (Qstepx32_int < 24) // ((0.6875+0.8125)/2) * 32 = 24
//		return (qp + 1);
//	else if (Qstepx32_int < 27) // ((0.8125+0.8750)/2) * 32 = 27
//		return (qp + 2);
//	else if (Qstepx32_int < 30) // ((0.8750+1.0000)/2) * 32 = 30
//		return (qp + 3);
//	else if (Qstepx32_int < 34) // ((1.0000+1.1250)/2) * 32 = 34
//		return (qp + 4);
//	else
//		// ((1.1250+1.2500)/2) * 32 = 38
//		return (qp + 5);
//}

// hjlee 2010.06.25
