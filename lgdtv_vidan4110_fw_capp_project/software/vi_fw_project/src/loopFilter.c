#include "global.h"
#include "image.h"
#include "mb_access.h"
//#include "dma.h"


/*!
 *****************************************************************************************
 * \brief
 *    Deblocking filter for one macroblock.
 *****************************************************************************************
 */

// new ADF register setting functions by shpark, 2008.02.16. :: begin

#define REG(a,b,c) (((a)&((1<<((b)-(c)+1))-1))<<(c))

void Deblock_Control1 (int disabled_idc, int qp)
{
	DB_CR1 = (
			REG(qp, 5, 0) |
			REG(disabled_idc, 7, 6)
			);
}

void Deblock_Control2 (int alpha_offset, int beta_offset)
{
	DB_CR2 = (
			REG(alpha_offset, 7, 0) |
			REG(beta_offset, 15, 8)
			);
}

void Deblock_Dimension (int width, int height)
{
	DB_DIM = (
			REG(width, 15, 0) |
			REG(height, 31, 16)
			);
}

void Deblock_Target_Addr (int addr_y, int addr_u, int addr_v)
{
	DB_BASE_ADDR_Y = addr_y;
	DB_BASE_ADDR_U = addr_u;
	DB_BASE_ADDR_V = addr_v;
}


// new ADF register setting functions by shpark, 2008.02.16. :: end
/*



//void DeblockMb(void)
void DeblockMb_setting1(void)
{
	int tmp;
	Macroblock *MbQ;
	//0709
       	Prev_Macroblock *MbP_V, *MbP_H;
	int mb_avail_up, mb_avail_left;
	int mb_x, mb_y;
	int mv_base_x, mv_base_y;

	mb_x = img.mb_x;
	mb_y = img.mb_y;

	mv_base_x = mb_x << 2;
	mv_base_y = mb_y << 2;

    	MbQ   = &img.mb_data_q;

	mb_avail_up   = MbQ->mbAvailB;
	mb_avail_left = MbQ->mbAvailA;

    	if(mb_avail_up)   MbP_V = &img.mb_data_v[mb_x];
	if(mb_avail_left) MbP_H = &img.mb_data_h;


#define REG(a,b,c) (((a)&((1<<((b)-(c)+1))-1))<<(c))

	if (mb_avail_up) {
		ADF_MV_16 = ( REG(enc_frame_picture->mv[mv_base_x    ][mv_base_y - 1][0], 11, 0) | 
			      REG(enc_frame_picture->mv[mv_base_x    ][mv_base_y - 1][1], 23, 12));
	
		ADF_MV_17 = ( REG(enc_frame_picture->mv[mv_base_x + 1][mv_base_y - 1][0], 11, 0) | 
			      REG(enc_frame_picture->mv[mv_base_x + 1][mv_base_y - 1][1], 23, 12));
	
		ADF_MV_18 = ( REG(enc_frame_picture->mv[mv_base_x + 2][mv_base_y - 1][0], 11, 0) | 
			      REG(enc_frame_picture->mv[mv_base_x + 2][mv_base_y - 1][1], 23, 12));
	
		ADF_MV_19 = ( REG(enc_frame_picture->mv[mv_base_x + 3][mv_base_y - 1][0], 11, 0) | 
			      REG(enc_frame_picture->mv[mv_base_x + 3][mv_base_y - 1][1], 23, 12));

	}

    ADFCR1 = (
            REG(input.LFDisableIdc, 1,0) |
            REG(MbQ->mbAvailA, 2,2) |
            REG(MbQ->mbAvailB, 3,3) |
            REG(img.qp, 9,4) |
            REG(img.qp, 15,10) |
            REG(img.qp, 21,16)
            );
    //ADFCR6 = MbP_V->cbp_blk;
    //ADFCR7 = MbP_H->cbp_blk;
    //ADFCR2 = ( 
    //        REG(MbP_V->mb_type, 7,4) |
    //        REG(MbP_H->mb_type, 11,8)
    //        );
    //for now, all sequence same offset, so once in init_img
    //ADFCR3 = (
    //        REG(MbQ  ->lf_alpha_c0_offset, 7,0) |
    //        REG(MbP_V->lf_alpha_c0_offset, 15,8) |
    //        REG(MbP_H->lf_alpha_c0_offset, 23,16)
    //        );
    //ADFCR4 = (
    //        REG(MbQ  ->lf_beta_offset, 7,0) |
    //        REG(MbP_V->lf_beta_offset, 15,8) |
    //        REG(MbP_H->lf_beta_offset, 23,16)
    //        );
	}
void DeblockMb_setting2(void)
{
	int tmp;
	Macroblock *MbQ;
	//0709
       	Prev_Macroblock *MbP_V, *MbP_H;
	int mb_avail_up, mb_avail_left;
	int mb_x, mb_y;
	int mv_base_x, mv_base_y;

	mb_x      = img.mb_x;
	mb_y      = img.mb_y;
	//mv_base_x = mb_x << 2;
	//mv_base_y = mb_y << 2;
	
    	MbQ   = &img.mb_data_q;
	
	mb_avail_up   = MbQ->mbAvailB;
	mb_avail_left = MbQ->mbAvailA;
	
    	if(mb_avail_up)   MbP_V = &img.mb_data_v[mb_x];
	if(mb_avail_left) MbP_H = &img.mb_data_h;


#define REG(a,b,c) (((a)&((1<<((b)-(c)+1))-1))<<(c))
//
//	if (mb_avail_up) {
//		ADF_MV_16 = ( REG(enc_frame_picture->mv[mv_base_x    ][mv_base_y - 1][0], 11, 0) | 
//			      REG(enc_frame_picture->mv[mv_base_x    ][mv_base_y - 1][1], 23, 12));
//	
//		ADF_MV_17 = ( REG(enc_frame_picture->mv[mv_base_x + 1][mv_base_y - 1][0], 11, 0) | 
//			      REG(enc_frame_picture->mv[mv_base_x + 1][mv_base_y - 1][1], 23, 12));
//	
//		ADF_MV_18 = ( REG(enc_frame_picture->mv[mv_base_x + 2][mv_base_y - 1][0], 11, 0) | 
//			      REG(enc_frame_picture->mv[mv_base_x + 2][mv_base_y - 1][1], 23, 12));
//	
//		ADF_MV_19 = ( REG(enc_frame_picture->mv[mv_base_x + 3][mv_base_y - 1][0], 11, 0) | 
//			      REG(enc_frame_picture->mv[mv_base_x + 3][mv_base_y - 1][1], 23, 12));
//
//	}
    ADFCR2 = (
            //REG(MbQ->mb_type, 3,0)   | 
            REG(MbP_V->mb_type, 7,4) |
            REG(MbP_H->mb_type, 11,8)
            );

    //ADFCR2 = REG(MbQ->mb_type, 3,0); 
    //ADFCR5 = MbQ->cbp_blk;

    ADFCR6 = MbP_V->cbp_blk;
    ADFCR7 = MbP_H->cbp_blk;

///---- setting is complete.
}
void DeblockMb(void){
	ADFSR1 = 0x1;           // ADF  start!
        write_one_macroblock();
	
}

// vim: fdm=marker fmr={{{,}}} cms=\ //%s

*/

