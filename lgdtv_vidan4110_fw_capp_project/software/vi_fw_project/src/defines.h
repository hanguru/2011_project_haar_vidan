
/*!
 **************************************************************************
 * \file defines.h
 *
 * \brief
 *    Headerfile containing some useful global definitions
 *
 * \author
 *    Detlev Marpe 
 *    Copyright (C) 2000 HEINRICH HERTZ INSTITUTE All Rights Reserved.
 *
 * \date
 *    21. March 2001
 **************************************************************************
 */


#ifndef _DEFINES_H_
#define _DEFINES_H_

#define G50_SPS

typedef unsigned char byte;    //!< byte type definition

// APJ: Added the following define
//#define PROFILE_IDC     88
//#define LEVEL_IDC       21
#define PROFILE_IDC     66 //baseline profile
#define LEVEL_IDC       32

#define LIST_0 0

// CAVLC
#define LUMA              0
#define LUMA_INTRA16x16DC 1
#define LUMA_INTRA16x16AC 2
#define CHROMA_DC       6
#define CHROMA_AC       7

#define TOTRUN_NUM    15
#define RUNBEFORE_NUM  7



// ---------------------------------------------------------------------------------
// FLAGS and DEFINES for new chroma intra prediction, Dzung Hoang
// Threshold values to zero out quantized transform coefficients.
// Recommend that _CHROMA_COEFF_COST_ be low to improve chroma quality
#define _LUMA_COEFF_COST_       4 //!< threshold for luma coeffs
#define _CHROMA_COEFF_COST_     4 //!< threshold for chroma coeffs, used to be 7

#define IMG_PAD_SIZE    4   //!< Number of pixels padded around the reference frame (>=4)

#define absm(A) ((A)<(0) ? (-(A)):(A)) //!< abs macro, faster than procedure
#define MAX_VALUE       999999   //!< used for start value for some variables

#define P8x8    8
#define I4MB    9
#define I16MB   10
#define IBLOCK  11

#define  LAMBDA_ACCURACY_BITS         16
#define  LAMBDA_FACTOR(lambda)        (int)((1<<LAMBDA_ACCURACY_BITS)*lambda)
#define  WEIGHTED_COST(factor,bits)   (((factor)*(bits))>>LAMBDA_ACCURACY_BITS)
#define  MV_COST(f,s,cx,cy,px,py)     (WEIGHTED_COST(f,mvbits[((cx)<<(s))-px]+mvbits[((cy)<<(s))-py]))
#define  REF_COST(f,ref)              (WEIGHTED_COST(f,refbits[(ref)]))

#define  BWD_IDX(ref)                 (((ref)<2)? 1-(ref): (ref))

#define IS_INTRA(MB)    ((MB)->mb_type==I4MB  || (MB)->mb_type==I16MB)
#define IS_NEWINTRA(MB) ((MB)->mb_type==I16MB)
#define IS_OLDINTRA(MB) ((MB)->mb_type==I4MB)
#define IS_INTERMV(MB)  ((MB)->mb_type!=I4MB  && (MB)->mb_type!=I16MB  && (MB)->mb_type!=0)
#define IS_P8x8(MB)     ((MB)->mb_type==P8x8)

// Quantization parameter range

#define MIN_QP          0
#define MAX_QP          51
#define SHIFT_QP        12

#define LOG2_MAX_FRAME_NUM_MINUS4   4           // POC200301 moved from defines.h
#define LOG2_MAX_PIC_ORDER_CNT_LSB_MINUS4 4     // POC200301 newly added

#define BLOCK_SIZE      4
#define MB_BLOCK_SIZE   16

#define NO_INTRA_PMODE  9        //!< #intra prediction modes
//!< 4x4 intra prediction modes
//#define VERT_PRED             0
//#define HOR_PRED              1
#define DC_PRED               2
//#define DIAG_DOWN_LEFT_PRED   3
//#define DIAG_DOWN_RIGHT_PRED  4
//#define VERT_RIGHT_PRED       5
//#define HOR_DOWN_PRED         6
//#define VERT_LEFT_PRED        7
//#define HOR_UP_PRED           8
//
//// 16x16 intra prediction modes
//#define VERT_PRED_16    0
//#define HOR_PRED_16     1
//#define DC_PRED_16      2
//#define PLANE_16        3
//
//// 8x8 chroma intra prediction modes
#define DC_PRED_8       0
//#define HOR_PRED_8      1
//#define VERT_PRED_8     2
//#define PLANE_8         3
//
//
//#define MVPRED_MEDIAN   0
//#define MVPRED_L        1
//#define MVPRED_U        2
//#define MVPRED_UR       3


#define BLOCK_MULTIPLE      (MB_BLOCK_SIZE/BLOCK_SIZE)

//#define MAX_SYMBOLS_PER_MB  1200  //!< Maximum number of different syntax elements for one MB
#define MAX_SYMBOLS_PER_MB 10                                 // CAVLC needs more symbols per MB

#endif

