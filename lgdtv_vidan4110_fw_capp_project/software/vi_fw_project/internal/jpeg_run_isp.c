#include "cdjpeg.h"		
#include "jpeg.h"
#include "jpeglib.h"
#include "map.h"
#include "map_hif.h"
#include "jpeg_global.h"
#include "commandProcess.h" //usb.h

void jpeg_init(int jpeg_sel, j_compress_ptr cinfo, int jpeg_ref_frame, int dst_buf_num);
void jpeg_parameter_set(j_compress_ptr cinfo, int qfacter, int jpeg_sel);
void jpeg_header_write(j_compress_ptr cinfo);
void jpeg_run(j_compress_ptr cinfo, int jpeg_sel, int number);
void jpeg_end_write(void);
int jpeg_api(j_compress_ptr cinfo, int jpeg_sel);

extern int AlignOffsetAddr(int offset, int align);
extern GLOBAL(void)pass_startup(j_compress_ptr cinfo);

extern GLOBAL(boolean)compress_data JPP((j_compress_ptr cinfo, int iMBY, int jpeg_sel)); //JSY+ //kik+

int JPEG_SIZE_W;
int JPEG_SIZE_H;

void jpeg_init(int jpeg_sel, j_compress_ptr cinfo, int jpeg_ref_frame, int dst_buf_num)
{
  int qfacter;
  int burst_len;
  int cb_offset;
  int cr_offset;
  int cb_offset_aligned;
  int cr_offset_aligned;
  static int prev_qfacter;
  int JPEG_SRC_BASE = 0; // jarre 2009.07.02 cam2 jpeg +
  int JPEG_IMAGE_OUT_W = 0; // jarre 2009.07.02 cam2 jpeg +
  int JPEG_IMAGE_OUT_H = 0; // jarre 2009.07.02 cam2 jpeg +

  /////////////select jpeg_size
  cinfo->image_width = (JPEG_SIZE_W)*16;
  cinfo->image_height = (JPEG_SIZE_H)*16;

  ////////////////////////////////////////////////////
  // // jarre 2009.07.02 cam2 jpeg + vvvvv
  	if ( H264_RESOLUTION == H264_VGA || H264_RESOLUTION == H264_HD )
  	{
    	JPEG_SRC_BASE = S_SRC_BASE;
    	JPEG_IMAGE_OUT_W = IMAGE2_OUT_W;
    	JPEG_IMAGE_OUT_H = IMAGE2_OUT_H;
	}
	else if ( H264_RESOLUTION == H264_QVGA || H264_RESOLUTION == H264_QQVGA ) //TODO
	{
    	JPEG_SRC_BASE = SRC_BASE;
    	JPEG_IMAGE_OUT_W = IMAGE_OUT_W;
    	JPEG_IMAGE_OUT_H = IMAGE_OUT_H;
	}

  // // jarre 2009.07.02 cam2 jpeg + ^^^^^
  ////////////////////////////////////////////////////

  //sw0_fromMEM
  cb_offset = (JPEG_IMAGE_OUT_W*16 < 640) ? 640*480: ((JPEG_IMAGE_OUT_W) * (JPEG_IMAGE_OUT_H) * 16 * 16); // for QVGA SDRAMC2 mode +
  cb_offset_aligned = AlignOffsetAddr(cb_offset, 1024);
  cr_offset = cb_offset_aligned + cb_offset/4;
  cr_offset_aligned = AlignOffsetAddr(cr_offset, 1024);

  ////////////////////////////////////////////////////
  // // jarre 2009.07.02 cam2 jpeg + vvvvv
  *MI_IY_ADDR = JPEG_SRC_BASE;
  *MI_IU_ADDR = JPEG_SRC_BASE + cb_offset_aligned;
  if (SDRAM_SDRAMC_TRMODE) // for foolish map
    {
  *MI_IV_ADDR = JPEG_SRC_BASE + cr_offset_aligned + 5120;
    }
  else
    {
  *MI_IV_ADDR = JPEG_SRC_BASE + cr_offset_aligned;
    }
  // // jarre 2009.07.02 cam2 jpeg + ^^^^^
  ////////////////////////////////////////////////////
  ////////////////////////////////////////////////////
  // // jarre 2009.07.02 cam2 jpeg - vvvvv
  //  *MI_IY_ADDR = SRC_BASE;
  //  *MI_IU_ADDR = SRC_BASE + cb_offset_aligned;
  //  if (SDRAM_SDRAMC_TRMODE) // for foolish map
  //    {
  //  *MI_IV_ADDR = SRC_BASE + cr_offset_aligned + 5120;
  //    }
  //  else
  //    {
  //  *MI_IV_ADDR = SRC_BASE + cr_offset_aligned;
  //    }
  // // jarre 2009.07.02 cam2 jpeg - ^^^^^
  ////////////////////////////////////////////////////

  //*MI_IY_ADDR = SRC_BASE;
  //*MI_IU_ADDR = SRC_BASE + cb_offset;
  //*MI_IV_ADDR = SRC_BASE + cb_offset + cb_offset/4;

 	if ( dst_buf_num == 0 )
	{
		*MI_S_ADDR = JPEG_STREAM_ADDR; //mux
	}
	else
	{
		*MI_S_ADDR = JPEG_STREAM_ADDR + MAX_JPEG_STREAM_LEN; //mux
	}

  if (jpeg_ref_frame == 1)
    *MI_FO = 0x00200000;
  else if (jpeg_ref_frame == 2)
    *MI_FO = 0x00400000;
  else
    *MI_FO = 0x00000000;
  //-----------------------------------------------------------------
  //read qfacter and gray_level value
  //qfacter = 0x7F & *HIF_REG25; //(6:0) 1~100
    qfacter = JPEG_QUALITY_FACTOR;
	if ( qfacter > 80 ) qfacter = 80; //jpeg Debug
    //qfacter = (0x7F & JPEG_QUALITY_FACTOR);
    if (OM_SELECT_EXTERN_CODE_MEM_TYPE)
      burst_len = 0;
    else
      burst_len = 1;

    //gray level
    *MI_REG0 = ((((cinfo->image_width) >> 4)<<8) |
		((JPEG_IMAGE_OUT_W << 24)&0xFF000000) | // jarre 2009.07.02 cam2 jpeg +
		((JPEG_IMAGE_OUT_H << 16)&0x00FF0000) | // jarre 2009.07.02 cam2 jpeg +
		(burst_len << 6));
    *MI_REG2 = SDRAM_SDRAMC_TRMODE | 0x0; // for res32_mode off
  //----------------------------------------------------------------
if (prev_qfacter != qfacter)
{
  jpeg_parameter_set(cinfo, qfacter, jpeg_sel);
}
prev_qfacter = qfacter;
}

void jpeg_parameter_set(j_compress_ptr cinfo, int qfacter, int jpeg_sel)
{

  //setting jpeg parameter
  jpeg_set_defaults(cinfo, qfacter, jpeg_sel);

}


void jpeg_header_write(j_compress_ptr cinfo)
{
  /* Start compressor */
  jpeg_start_compress(cinfo, TRUE);

  pass_startup(cinfo);
}

void jpeg_run(j_compress_ptr cinfo, int jpeg_sel, int number)
{
  compress_data(cinfo, number, jpeg_sel);
}


void jpeg_end_write()
{
  int i;

  for (i = 0; i < 500; i++){} //kik+

  *TCR0 = 0x22; //JJS+ jpeg VLC hardware flushing
  *TCR0 = 0x20; //JJS+ jpeg should remain as asserted while flushing;

  while (!((*TCR2 &0x4) == 0x4))
    ;
  *TCR0 = 0x80; //JJS+ VLC Hardware reset
  *TCR0 = 0x00; // JPEG END for sjpeg
}

int jpeg_api(j_compress_ptr cinfo, int jpeg_sel)
{
	*MI_REG1 = 0x6; // frame_st, os_write_st
	*MI_REG1 = 0x0;
	jpeg_header_write(cinfo);
	*DQ_OPMODE = 0x2014;
	JPEG_CTRL_REG0 = (((cinfo->image_height) / 16)*((cinfo->image_width) / 16));
	//OS_ENTER_CRITICAL();
	//JPEG_CTRL_REG1 = 0x80000001;
	//JPEG_CTRL_REG1 = 0x80000000;
	__asm __volatile("b.ori r6,r0,0x80000001");
	__asm __volatile("b.ori r7,r0,0x80000000");
	__asm __volatile("b.sw  0xb009b004(r0),r6");
	__asm __volatile("b.sw  0xb009b004(r0),r7");
	//OS_EXIT_CRITICAL();
	
	return 0;
}

