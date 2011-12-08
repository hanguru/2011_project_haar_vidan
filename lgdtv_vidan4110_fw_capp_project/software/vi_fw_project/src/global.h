
/*!
 ************************************************************************
 *  \file
 *     global.h
 *  \brief
 *     global definitions for for H.26L encoder.
 *  \author
 *     Copyright (C) 1999  Telenor Satellite Services,Norway
 *                         Ericsson Radio Systems, Sweden
 *
 *     Inge Lille-Langøy               <inge.lille-langoy@telenor.com>
 *
 *     Telenor Satellite Services
 *     Keysers gt.13                       tel.:   +47 23 13 86 98
 *     N-0130 Oslo,Norway                  fax.:   +47 22 77 79 80
 *
 *     Rickard Sjoberg                 <rickard.sjoberg@era.ericsson.se>
 *
 *     Ericsson Radio Systems
 *     KI/ERA/T/VV
 *     164 80 Stockholm, Sweden
 *
 ************************************************************************
 */
#ifndef _GLOBAL_H_
#define _GLOBAL_H_

//#define DUAL_STREAM 1 // jarre 2009.07.01 dual stream -

#include <stdio.h>

#include "defines.h"
#include "nalucommon.h"
#include "parsetcommon.h"
//commented by eskim
//#include "heapalloc.h"
//#include "msg.h"
#include "map.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define Q_BITS          15
#define DQ_BITS         6
#define DQ_ROUND        (1<<(DQ_BITS-1))
/***********************************************************************
 * T y p e    d e f i n i t i o n s    f o r    T M L
 ***********************************************************************
 */

#define pel_t byte

typedef enum {
  INTER_MB,
  INTRA_MB_4x4,
  INTRA_MB_16x16
} IntraInterDecision;

typedef enum {
  P_SLICE = 0,
  I_SLICE
} SliceType;

typedef struct pix_pos
{
  int available;
  int mb_addr;
  int x;
  int y;
  int pos_x;
  int pos_y;
} PixelPos;


//! Syntaxelement
typedef struct syntaxelement
{
  int                 value1;         //!< numerical value of syntax element
  int                 value2;         //!< numerical value of syntax element
  int                 len;            //!< length of code
  int                 inf;            //!< info part of UVLC code
  unsigned int        bitpattern;     //!< UVLC bitpattern

  //!< for mapping of syntaxElement to UVLC
  void    (*mapping)(int value1, int* len_ptr, int* info_ptr);
} SyntaxElement;

//! Macroblock
typedef struct macroblock
{
  int                 currSEnr;                   //!< number of current syntax element
  //int                 slice_nr;
  int                 delta_qp;
  int                 qp ;

  int                 mb_type;
  int                 mvd[BLOCK_MULTIPLE][BLOCK_MULTIPLE][2];          //!< indices correspond to [block_y][block_x][x,y]
  int                 intra_pred_modes[BLOCK_MULTIPLE*BLOCK_MULTIPLE];
  int                 cbp ;
  int                 cbp_blk ;    //!< 1 bit set for every 4x4 block with coefs (not implemented for INTRA)
  int                 b8mode[4];
  int                 b8pdir[4];

  int                 lf_disable;
  int                 lf_alpha_c0_offset;
  int                 lf_beta_offset;

  int                 c_ipred_mode;      //!< chroma intra prediction mode
  int                 IntraChromaPredModeFlag;

  int mbAddrA, mbAddrB, mbAddrC, mbAddrD;
  int mbAvailA, mbAvailB, mbAvailC, mbAvailD;

} Macroblock;

//! prev_Macroblock
typedef struct prev_macroblock
{
  int                 qp ;
  int                 mb_type;
  int                 cbp_blk ;
  int                 lf_alpha_c0_offset;
  int                 lf_beta_offset;
} Prev_Macroblock;

//! Slice
typedef struct
{
  //int                 picture_id;
  int                 qp;
  int                 start_mb_nr;
  int                 num_mb;       //!< number of MBs in the slice

} Slice;


#define MAXSLICEPERPICTURE 100
typedef struct 
{
  int   no_slices;
  Slice *slices;
} Picture;

extern Picture *frame_pic;


typedef struct
{
  // Size info
  int x_size, y_framesize;
  char *yf, *uf, *vf;                    //!< frame representation
} Sourceframe;

// global picture format dependend buffers, mem allocation in image.c
extern int    **refFrArr;           //!< Array for reference frames of each block

extern pic_parameter_set_rbsp_t *active_pps;
extern seq_parameter_set_rbsp_t *active_sps;

extern int intras;         //!< Counts the intra updates in each frame.

extern int  frame_no;
extern int  tot_time;

struct input_par;
//! all input parameters
typedef struct input_par
{
  //int no_frames;                //!< number of frames to be encoded
  int qp0;                      //!< QP of first frame
  int qpN;                      //!< QP of remaining frames
  int jumpd;                    //!< number of frames to skip in input sequence (e.g 2 takes frame 0,3,6,9...)

  //int img_width0;                //!< GH: if CUSTOM image format is chosen, use this size
  //int img_height0;               //!< GH: width and height must be a multiple of 16 pels
  //int img_width1;                //!< GH: if CUSTOM image format is chosen, use this size
  //int img_height1;               //!< GH: width and height must be a multiple of 16 pels
  int img_width;                //!< GH: if CUSTOM image format is chosen, use this size
  int img_height;               //!< GH: width and height must be a multiple of 16 pels

  //int cam_width0;                //!< GH: if CUSTOM image format is chosen, use this size
  //int cam_height0;               //!< GH: width and height must be a multiple of 16 pels
  //int cam_width1;                //!< GH: if CUSTOM image format is chosen, use this size
  //int cam_height1;               //!< GH: width and height must be a multiple of 16 pels
  int cam_width;                //!< GH: if CUSTOM image format is chosen, use this size
  int cam_height;               //!< GH: width and height must be a multiple of 16 pels
  int cb_offset;                //! This offset is not aligned value
  
  int blc_size[8][2];           //!< array for different block sizes

//  char *outfile;                //!< H.26L compressed output bitstream
  
  int intra_period;             //!< Random Access period though intra

  int LFSendParameters;
  int LFDisableIdc;
  int LFAlphaC0Offset;
  int LFBetaOffset;
  
  // Rate Control
  int RCEnable;
  int bit_rate0;
  int bit_rate1;
  int bit_rate;
  int PrevBitRate; //RC1018
  //double FrameRate;
  int FrameRate;
  int SeinitialQP0;
  int SeinitialQP1;
  int SeinitialQP;

  //enable_slice_mode
  int slice_mode;               //!< Indicate what algorithm to use for setting slices
  int slice_argument;           //!< Argument to the specified slice algorithm


} InputParameters;

extern InputParameters input;

struct img_par;
//! ImageParameters
typedef struct img_par
{
  int number;                  //!< current image number to be encoded
  int current_mb_nr;
  int total_number_mb;
  //int current_slice_nr;
  int type;
  int qp;                      //!< quant for the current frame
  int prev_qp;			// chae 2010.06.17

  //int width0;                   //!< Number of pels
  //int width_cr0;                //!< Number of pels chroma
  //int height0;                  //!< Number of lines
  //int height_cr0;               //!< Number of lines  chroma
  //int width1;                   //!< Number of pels
  //int width_cr1;                //!< Number of pels chroma
  //int height1;                  //!< Number of lines
  //int height_cr1;               //!< Number of lines  chroma
  int width;                   //!< Number of pels
  int width_cr;                //!< Number of pels chroma
  int height;                  //!< Number of lines
  int height_cr;               //!< Number of lines  chroma

  int mb_x;                    //!< current MB horizontal
  int mb_y;                    //!< current MB vertical
  int block_x;                 //!< current block horizontal
  int block_y;                 //!< current block vertical
  int subblock_x;              //!< current subblock horizontal
  int subblock_y;              //!< current subblock vertical
  int pix_x;                   //!< current pixel horizontal
  int pix_y;                   //!< current pixel vertical
  int mb_y_upd;
//  int width_mul_height;
  //int mb_y_intra;              //!< which GOB to intra code
//  int **ipredmode;             //!< GH ipredmode[90][74];prediction mode for inter frames */ /* fix from ver 4.1
  int cod_counter;             //!< Current count of number of skipped macroblocks in a row
//  int ****nz_coeff;            //!< number of coefficients per block (CAVLC)

//  int *nz_coeff_u;
//  int *nz_coeff_l;


  //Picture        *currentPicture; //!< The coded picture currently in the works (typically frame_pic, top_pic, or bottom_pic)
  Slice          *currentSlice;                                //!< pointer to current Slice data struct
//  Macroblock     *mb_data;                                   //!< array containing all MBs of a whole frame

  Macroblock      mb_data_q;	// current Macroblock
  Prev_Macroblock      mb_data_h;	// left Macroblock
  Prev_Macroblock     *mb_data_v;	// above line of Macroblock
  
  SyntaxElement   MB_SyntaxElements[MAX_SYMBOLS_PER_MB];    //!< temporal storage for all chosen syntax elements of one MB

  int num_ref_idx_l0_active;
  int num_ref_idx_l1_active;

  int i16offset;

  //int tr;


  // POC200301
  //the following is for slice header syntax elements of poc
  // for poc mode 0.
  unsigned int pic_order_cnt_lsb;

  // POC200301
  signed int framepoc;    //!< min (toppoc, bottompoc)
  unsigned int frame_num;   //!< frame_num for this frame
  
  unsigned PicWidthInMbs0;
  unsigned FrameHeightInMbs0;
  unsigned FrameSizeInMbs0;
  unsigned PicWidthInMbs1;
  unsigned FrameHeightInMbs1;
  unsigned FrameSizeInMbs1;
  unsigned PicWidthInMbs;
  unsigned FrameHeightInMbs;
  unsigned PicSizeInMbs;
  unsigned FrameSizeInMbs;

  //the following are sent in the slice header
  int nal_reference_idc;
//chae
  int prev_mb_x;                    //!< previous MB horizontal
  int prev_mb_y;                    //!< previous MB vertical
  int prev_prev_mb_x;               //!< previous MB horizontal
  int prev_prev_mb_y;               //!< previous MB vertical
  int next_mb_x;                    //!< previous MB horizontal
  int next_mb_y;                    //!< previous MB vertical
  int number_mb_per_row;
  int number_mb_per_row_mul_four;
  int number_mb_per_row_mul_six ;

//speed
  int prevf_enc_time;
  int targetfr_enc_time;
  int targetmb_enc_time;
  int *avg_mb_enc_time_of_line;


  // Rate Control - added
//  int Frame_Total_Number_MB;
  int Frame_Total_Number_MB;
  int framerate;
  int NumberofCodedPFrame0;
  int NumberofCodedPFrame1;
  int NumberofCodedPFrame;
  int NumberofGOP0;
  int NumberofGOP1;
  int NumberofGOP;
  int *MADofMB;
  int TotalQpforPPicture0;
  int TotalQpforPPicture1;
  int TotalQpforPPicture;
  int NumberofPPicture0;
  int NumberofPPicture1;
  int NumberofPPicture;
  int NumberofHeaderBits0;
  int NumberofHeaderBits1;
  int NumberofHeaderBits;
  int NumberofTextureBits0;
  int NumberofTextureBits1;
  int NumberofTextureBits;

  // image offset - added by sykim
  int width_offset;
  int height_offset;

  int cam_width;
  int cam_height;
  int cb_offset;                //! This offset is not aligned value
  
} ImageParameters;
extern ImageParameters img;


/***********************************************************************
 * P r o t o t y p e s   f o r    T M L
 ***********************************************************************
 */
void SetModesAndRefframe (int, int*, int*);
                     
void init_img(void);
int  get_picture_type(void);

extern int*   refbits;

int GetSkipCostMB (int lambda);
void FindSkipModeMotionVector (void);

// dynamic mem allocation
int  init_global_buffers(void);
void free_global_buffers(void);
void no_mem_exit  (char *where);

void free_img    (void);

// Added for (re-) structuring the TML soft
Picture *malloc_picture(void);
void  free_picture (Picture *pic);
void  encode_one_slice(void);   //! returns the number of MBs in the slice

void  encode_one_macroblock(int);
void  start_macroblock(void);
void  set_MB_parameters (int mb);           //! sets up img-> according to input-> and currSlice->
void  set_nextMB_parameters (int mb);           //! sets up img-> according to input-> and currSlice->

void  terminate_frame(void);
//void  write_one_macroblock_setting(void);
void  write_one_macroblock_setting1(void);
void  write_one_macroblock_setting2(void);
void  write_one_macroblock_setting3(void);
void  write_one_macroblock(void);
void  CheckAvailabilityOfNeighbors(void);

void free_slice_list(Picture *currPic);

int  start_sequence(void);
void start_slice(int);

void SetImgType(void);

//============= Adaptive Deblocking Filter =====================
// new ADF by shpark, 2008.02.16. :: begin
void Deblock_Control1 (int disabled_idc, int qp);
void Deblock_Control2 (int alpha_offset, int beta_offset);
void Deblock_Dimension (int width, int height);
void Deblock_Target_Addr (int addr_y, int addr_u, int addr_v);
// new ADF by shpark, 2008.02.16. :: end
/*
//void DeblockMb_setting(void) ;
void DeblockMb_setting1(void) ;
void DeblockMb_setting2(void) ;
void DeblockMb(void) ;
*/

// Tian Dong: for IGOPs
extern int FirstFrameIn2ndIGOP;
#define IMG_NUMBER (img.number)
#define PAYLOAD_TYPE_IDERP 8

void SODBtoRBSP(void);

extern int input_offset;
extern int output_offset;

extern int bits_to_go;
//#ifdef OFFSET_CONTROL //jykim_20080715_HIF_CONV--
extern int *mb_mv_x;
extern int *mb_mv_y;
//#endif //jykim_20080715_HIF_CONV--

int cam_cb_offset_aligned_temp; //2010.06.04
int cam_cr_offset_aligned_temp; //2010.06.04
//#define fake_intra_period 10   //2010.06.04
#define fake_intra_period -1   //2010.06.04
//kik_fw- #define intra_mb_lines    5     //2010.06.04
//kik_fw- #define mb_sub_groups     6     //2010.06.04
//#define intra_mb_lines    3   //2010.06.04
//#define mb_sub_groups     10  //2010.06.04


#endif
