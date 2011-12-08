/*!
 ***********************************************************************
 *  \mainpage
 *     This is the H.264/AVC encoder reference software. For detailed documentation
 *     see the comments in each file.
 *
 *  \author
 *     The main contributors are listed in contributors.h
 *
 *  \version
 *     JM 7.3
 *
 *  \note
 *     tags are used for document system "doxygen"
 *     available at http://www.doxygen.org
 */
/*!
 *  \file
 *     lencod.c
 *  \brief
 *     H.264/AVC reference encoder project main()
 *  \author
 *     Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Inge Lille-Lang?y               <inge.lille-langoy@telenor.com>
 *     - Rickard Sjoberg                 <rickard.sjoberg@era.ericsson.se>
 *     - Stephan Wenger                  <stewe@cs.tu-berlin.de>
 *     - Jani Lainema                    <jani.lainema@nokia.com>
 *     - Byeong-Moon Jeon                <jeonbm@lge.com>
 *     - Yoon-Seong Soh                  <yunsung@lge.com>
 *     - Thomas Stockhammer              <stockhammer@ei.tum.de>
 *     - Detlev Marpe                    <marpe@hhi.de>
 *     - Guido Heising                   <heising@hhi.de>
 *     - Karsten Suehring                <suehring@hhi.de>
 *
 ***********************************************************************
 */

#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "configfile.h"
#include "memalloc.h"
#include "mbuffer.h"
#include "parset.h"
#include "image.h"
#include "header.h"
#include "vlc.h"
//#include "dma.h"
#include "ratectl.h"
//added by eskim
#include "fpga.h"
//#include "common.h"
//#include "clocks.h"
#include "uart.h"
#include "uartc.h"

#include "map_hif.h"
#include "dvp.h" // jarre 2008.04.18 dvp +
#include "task_manage.h"
#include "tube.h"
#include "jpeg_global.h"
#include "jpeglib.h"  // jarre 2008.05.22 jpeg +
#include "jpeg.h"
#include "map.h"
#include "gpio.h"  //090408_jykim_dvp_handshaking+
#include "i2s.h"	//090408_jykim_mux+
#include "usb.h" //usb.h
#include "commandProcess.h"
#include "sensor_set.h" //sensor_set.h
#include "interrupt_handler.h"
#include "flash_operation.h"
#include "i2c_operation.h"
extern int jpeg_api(j_compress_ptr cinfo, int jpeg_sel);
extern void jpeg_init(int jpeg_sel, j_compress_ptr cinfo, int jpeg_ref_frame, int dst_buf_num);
void jpeg_task(j_compress_ptr cinfo, int jpeg_ref_frame, int dst_buf_num);

#define JM      "7"
#define VERSION "7.3"

#define MAX_FRAME_RATE		30
#define JPEG_FRAME_RATE		15
#define SENSOR_FRAME_RATE	30
extern volatile int isJpegDataExist;
extern volatile int isH264Pend;
extern volatile int isJPEGPend;
extern int isAudioStarted;

extern unsigned int calulate_system_clock(void);
extern unsigned char avata_capture_mode;

/************** GLOBAL VARIABLES ******************/

// global picture format dependend buffers, mem allocation in image.c
//pic_parameter_set_rbsp_t *active_pps0;
//pic_parameter_set_rbsp_t *active_pps1;
pic_parameter_set_rbsp_t *active_pps;
//seq_parameter_set_rbsp_t *active_sps0;
//seq_parameter_set_rbsp_t *active_sps1;
seq_parameter_set_rbsp_t *active_sps;

//int intras; //!< Counts the intra updates in each frame.

//int frame_no;
//#ifdef OFFSET_CONTROL //jykim_20080715_HIF_CONV--
//int *mb_mv_x;
//int *mb_mv_y;
//#endif //jykim_20080715_HIF_CONV--
//int ds_coef;

//struct input_par input0;
//struct input_par input1;
struct input_par input;
//struct img_par img0;
//struct img_par img1;
struct img_par img;

//int input_offset;
//int output_offset;
int bits_to_go;
int bits_per_frame;
int tmp_y, tmp_u, tmp_v;//kik_fw
//int total_target_bit;

//unsigned int motion_sum_value = 0;

//int jpeg_length_array[5] = { 0 }; //090507_jarre_dvp2 +
//int jpeg_length_array[4] = {0}; //090507_jarre_dvp2 -
//int jpeg_mot_enable = 0;

OS_EVENT *pStartSem;



/************** GLOBAL VARIABLES ******************/
void set_img_size_to_dmac(int width, int height) {
	VIM_SIZE 		= ((width >> 4) & 0xff) | (((height >> 4) & 0xff) << 8);
	VIM_FRAME_SIZE 	= ((width >> 4) & 0xff) | (((height >> 4) & 0xff) << 8);
	VLC_SIZE 		= ((width >> 4) & 0xff) | (((height >> 4) & 0xff) << 8);
}

void simpleRateControl(void);

int AlignOffsetAddr(int offset, int align);
void SetupForDoubleBuffer(int frame_sel, int double_buffer_en, int width_offset, int height_offset, int src_ref_frame_diff);
int max_bit_rate_value;
int less_than_orig_target_cnt;
int more_than_orig_target_cnt; // hjlee 2010.06.25
int qpN_minus_1_flag; // hjlee 2010.06.25
int qpN_plus_1_flag; // hjlee 2010.06.25
/*!
 ***********************************************************************
 * \brief
 *    Main function for encoder.
 * \param argc
 *    number of command line arguments
 * \param argv
 *    command line arguments
 * \return
 *    exit code
 ***********************************************************************
 */
#define MAX_SIMPLE_RATE_CONTROL_QP		51
#define MIN_SIMPLE_RATE_CONTROL_QP		12 // hjlee 2010.06.25	
int lencod(void) //jykim_080725_ucos_porintg-- 
{
	INT8U err = 0;
	OS_CPU_SR cpu_sr;
	int prevFrameRate;
	int prevZoomLevel = 0;

	int frame_sel = 0;
	int j_frame_sel = 0;
	int encodeDone = 0;
	int jpeg_frame_cnt = 0;
	int isJDone = 0;
	int nop_i = 0;
	int i;
	volatile int jpeg_temp_len;
	unsigned char jpeg_temp[8];
	int jpeg_int_temp0;
	int jpeg_int_temp1;
	int prev_i = 0;
	int temp_jpeg_quality;
	int temp_input_qp0;
	int isFirst = 1;
	int encodeCnt = 0;
	int sensor_get_retry_cnt = 0;
	int jpeg_fps;

	char tempBuf[256];
	int ret;
	unsigned int targetClockTick = 0;
	unsigned int temp_rptc_cntr = 0;

	struct jpeg_compress_struct cinfo; // jarre 2008.05.22 jpeg +
	struct jpeg_compress_struct *p_cinfo = &cinfo; // jarre 2008.05.22 jpeg +

	jpeg_create_compress(p_cinfo); //create cinfo structure  // jarre 2008.05.22 jpeg +

	pStartSem = OSSemCreate(0);

	//frame_sel = 0;
	//j_frame_sel = 0;
	//InitFPGA();

	mtspr(SPR_TTMR, ((TTMR_M(0x1) & TTMR_MMASK) | (0x0fffffff & TTMR_TPMASK)));

	mtspr(SPR_TTCR, 0);

	while (1) {

		//uart_print("Video Start Wait\n\r");

		if ( !isAudioStarted )
			GPIOSetHigh(GPIO12);


		tempBuf[0] = 0x30; tempBuf[1] = 0x12; tempBuf[2] = 0x80;
		ret = i2c_write(0x30, 3, tempBuf); if ( ret ) uart_print("sensor set error!!!\n\r");
 		//for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");

		OSSemPend(pStartSem, 0, &err);

		//uart_print("Video Started\n\r");

		flash_avata_mode_check();

		if ( avata_capture_mode )
		{
			flash_write_initial_sdramc2_register(); //move safe area
		}

		//Check Avata Mode
		if ( AVATA_MODE & 0x01 )
		{
			flash_write_initial_sdramc1_register();
		}

		//uart_print("Res:");
		//uart_printInt(H264_RESOLUTION);
		//uart_print("\n\r");

		//Zoom Level
		//ZOOM_LEVEL = 0;
		prevZoomLevel = ZOOM_LEVEL;

		////////////////////////////
		//frame_sel = 0;
		//j_frame_sel = 0;
		Configure_via_SW();
		InitFPGA1();
		while (IMAGE_FRAME_CNT < 2)
				;
		while (S_IMAGE_FRAME_CNT < 2)
				;

		//Remove Initial Sensor Gargbage Data
		for ( i = 0; i < 3; i++ )
		{
			IMAGE_ENCODING_ONE_FRAME_DONE = 1;
			S_IMAGE_ENCODING_ONE_FRAME_DONE = 1;
			while (IMAGE_FRAME_CNT < 2)
					;
			while (S_IMAGE_FRAME_CNT < 2)
					;
		}

		//////////////////////////////

		init_img();
		Deblock_Dimension(img.width, img.height);

		
		//Video Start
		GPIOSetLow(GPIO12);

		OSSemSet(pH264StreamSem, 0, &err);
		OSSemSet(pJPEGStreamSem, 0, &err);

		//Frame Rate control
		prevFrameRate = MAX_FRAME_RATE;
		//Frame Rate Control
		if ( RATE_CONTROL_FRAME_RATE > MAX_FRAME_RATE )
			RATE_CONTROL_FRAME_RATE = MAX_FRAME_RATE;
		targetClockTick = calulate_system_clock()/(RATE_CONTROL_FRAME_RATE);

		mtspr(SPR_TTCR, 0);

		jpeg_frame_cnt = 0; 
		isJDone = 0;

		init_video_streamBuf();

		GenerateParameterSets(); // don't care

		start_sequence(); // write sequence header (with parameter sets)
		FreeParameterSets();
		set_img_size_to_dmac(img.width, img.height); // to set width, height in DMAC reg

		isFirst = 1;
		encodeCnt = 0;

		max_bit_rate_value = MAX_BIT_RATE_VALUE;
		jpeg_fps = JPEG_FPS;

		for (img.number = 0; /*img.number < input.no_frames*/; /*img.number++*/) {


			img.framepoc = IMG_NUMBER * 2;
			img.frame_num = IMG_NUMBER & 0xff;

			if ( !isFirst )
			{
				if ( isVideoPropertySet )
				{
					isVideoPropertySet = 0;

					while (IMAGE_FRAME_CNT < 2)
							;
					while (S_IMAGE_FRAME_CNT < 2)
							;

					//Remove Initial Sensor Gargbage Data
					for ( i = 0; i < 9; i++ )
					{
						IMAGE_ENCODING_ONE_FRAME_DONE = 1;
						S_IMAGE_ENCODING_ONE_FRAME_DONE = 1;
						while (IMAGE_FRAME_CNT < 2)
								;
						while (S_IMAGE_FRAME_CNT < 2)
								;
					}
					OPERATION_DEFINE3 |= KEYFRAME_REQUEST_BIT;
				}
			}
			else
				isFirst = 0;

			//Zoom Function
			if ( prevZoomLevel != ZOOM_LEVEL )
			{
				while (IMAGE_FRAME_CNT < 2)
						;
				while (S_IMAGE_FRAME_CNT < 2)
						;
				zoomControl(prevZoomLevel, ZOOM_LEVEL);
				prevZoomLevel = ZOOM_LEVEL;
 				for ( nop_i = 0; nop_i < 1000000; nop_i++ ) __asm __volatile("l.nop   0");
			}

			//Strange
			if ( !avata_capture_mode )
			{
				if ( encodeCnt == 1 )
				{
					input.qp0 = 33;
					OPERATION_DEFINE3 |= KEYFRAME_REQUEST_BIT;
				}
			}


			SetImgType();

			SetupForDoubleBuffer(frame_sel, 1, 0, 0, 0);


			//ESD Dead
			sensor_get_retry_cnt = 0;
			while (IMAGE_FRAME_CNT == 0)
			{
 				for ( nop_i = 0; nop_i < 100; nop_i++ ) __asm __volatile("l.nop   0");
				if ( sensor_get_retry_cnt++ > 300000 )
				{
					uart_print("Sensor Dead\n\r");
					HOST_RESET = 0x03;
					break;
				}
			}
			sensor_get_retry_cnt = 0;
			while (S_IMAGE_FRAME_CNT == 0)
			{
 				for ( nop_i = 0; nop_i < 100; nop_i++ ) __asm __volatile("l.nop   0");
				if ( sensor_get_retry_cnt++ > 300000 )
				{
					uart_print("Sensor Dead\n\r");
					HOST_RESET = 0x03;
					break;
				}
			}
			
			//////////////////////////////////////////////////////
			//													//
			//				H.264 Encoder Routine				//
			//													//
			//////////////////////////////////////////////////////

			//Stream Buffer Check

			if ( img.type == P_SLICE && prev_i == 0 )
			{
				OS_ENTER_CRITICAL();
				while (h264DualStreamBuf.full[(int)h264DualStreamBuf.set_idx]) {
					//OSSemSet(pH264StreamSem, 0, &err);
					//uart_print("hpend\n\r");
					isH264Pend = 1;
					OS_EXIT_CRITICAL();
					//WDT Interrupt Enable
					if ( H264_RESOLUTION == H264_HD )
						*(volatile int*)WDT_BASE_ADDR = 120000000; //100ms
					else
						*(volatile int*)WDT_BASE_ADDR = 120000000; //100ms
					IntEnable(WDT_WB_INT_BIT);
					OSSemPend(pH264StreamSem, 0, &err);
					IntDisable(WDT_WB_INT_BIT);
					*(volatile int*)WDT_BASE_ADDR = 0xffffffff; //100ms
					isH264Pend = 0;
					////uart_print("hpost\n\r");
				}
				OS_EXIT_CRITICAL();
			}
			else
			{
				OS_ENTER_CRITICAL();
				while (h264DualStreamBuf.full[0] || h264DualStreamBuf.full[1]) {
					//OSSemSet(pH264StreamSem, 0, &err);
					//uart_print("hpend\n\r");
					isH264Pend = 1;
					OS_EXIT_CRITICAL();
					//WDT Interrupt Enable
					if ( H264_RESOLUTION == H264_HD )
						*(volatile int*)WDT_BASE_ADDR = 120000000; //100ms
					else
						*(volatile int*)WDT_BASE_ADDR = 120000000; //100ms
					IntEnable(WDT_WB_INT_BIT);
					OSSemPend(pH264StreamSem, 0, &err);
					IntDisable(WDT_WB_INT_BIT);
					*(volatile int*)WDT_BASE_ADDR = 0xffffffff; //100ms
					isH264Pend = 0;
					////uart_print("hpost\n\r");
				}
				OS_EXIT_CRITICAL();
				h264DualStreamBuf.set_idx = 0;
				h264DualStreamBuf.get_idx = 0;
			}

			//Frame Rate Control
			if ( RATE_CONTROL_FRAME_RATE > MAX_FRAME_RATE )
				RATE_CONTROL_FRAME_RATE = MAX_FRAME_RATE;

			if ( prevFrameRate != RATE_CONTROL_FRAME_RATE )
			{
				targetClockTick = calulate_system_clock()/(RATE_CONTROL_FRAME_RATE);
				prevFrameRate = RATE_CONTROL_FRAME_RATE;
			}
			encodeDone = 0;

			if ( targetClockTick < mfspr(SPR_TTCR) )
			{
				temp_rptc_cntr = mfspr(SPR_TTCR);
				if ( temp_rptc_cntr - targetClockTick > 0 )
					mtspr(SPR_TTCR, temp_rptc_cntr - targetClockTick);
				else
					mtspr(SPR_TTCR, 0);

				h264DualStreamBuf.len[(int)h264DualStreamBuf.set_idx] = 0;


				Deblock_Control1(input.LFDisableIdc, input.qpN);
				Deblock_Control2(input.LFAlphaC0Offset, input.LFBetaOffset);

				encode_one_frame();
				//uart_print("ed\n\r");
				encodeDone = 1;
				if ( img.type == P_SLICE )
					simpleRateControl();
				else {
					less_than_orig_target_cnt = 0;
					more_than_orig_target_cnt = 0;
				}

				if ( encodeCnt > 0 )
				{
					//Stream Too big Detection
					if ( img.type == P_SLICE )
					{
						if ( h264DualStreamBuf.len[(int)h264DualStreamBuf.set_idx] > MAX_H264_STREAM_LEN )
						{
							//uart_print("Size Toog Big!!\n\r");
							temp_input_qp0 = input.qp0 + 3;
							if ( temp_input_qp0 > MAX_SIMPLE_RATE_CONTROL_QP )
								temp_input_qp0 = MAX_SIMPLE_RATE_CONTROL_QP;
							input.qp0 = temp_input_qp0;

							OPERATION_DEFINE3 |= KEYFRAME_REQUEST_BIT;
						}	
						else
						{
							OS_ENTER_CRITICAL();
							h264DualStreamBuf.full[(int)h264DualStreamBuf.set_idx] = 1;
							if ( img.type == P_SLICE )
							{
								h264DualStreamBuf.set_idx++;
								if (h264DualStreamBuf.set_idx == VIDEO_BUFFER_CNT)
									h264DualStreamBuf.set_idx = 0;
							}
							OS_EXIT_CRITICAL();
						}
						prev_i = 0;
					}
					else
					{
						if ( h264DualStreamBuf.len[(int)h264DualStreamBuf.set_idx] > MAX_H264_STREAM_LEN*2 )
						{
							//uart_print("Size Toog Big!!\n\r");
							temp_input_qp0 = input.qp0 + 3;
							if ( temp_input_qp0 > MAX_SIMPLE_RATE_CONTROL_QP )
								temp_input_qp0 = MAX_SIMPLE_RATE_CONTROL_QP;
							input.qp0 = temp_input_qp0;

							OPERATION_DEFINE3 |= KEYFRAME_REQUEST_BIT;
						}	
						else
						{
							OS_ENTER_CRITICAL();
							h264DualStreamBuf.full[(int)h264DualStreamBuf.set_idx] = 1;
							if ( img.type == P_SLICE )
							{
								h264DualStreamBuf.set_idx++;
								if (h264DualStreamBuf.set_idx == VIDEO_BUFFER_CNT)
									h264DualStreamBuf.set_idx = 0;
							}
							OS_EXIT_CRITICAL();
						}
						prev_i = 1;
					}
				}
				encodeCnt++;
			}


			//////////////////////////////////////////////////////
			//													//
			//				JPEG Encoder Routine				//
			//													//
			//////////////////////////////////////////////////////

			if ( (H264_RESOLUTION == H264_HD) 
			|| (jpeg_frame_cnt % (int)( SENSOR_FRAME_RATE / jpeg_fps ) == 1) )
			{
				//Stream Buffer Check
				OS_ENTER_CRITICAL();
				while ( jpegDualStreamBuf.full[(int)jpegDualStreamBuf.set_idx] )
				{
					isJPEGPend = 1;
					OS_EXIT_CRITICAL();
					if ( H264_RESOLUTION == H264_HD )
						*(volatile int*)WDT_BASE_ADDR = 120000000; //100ms
					else
						*(volatile int*)WDT_BASE_ADDR = 120000000; //100ms
					IntEnable(WDT_WB_INT_BIT);
					OSSemPend(pJPEGStreamSem, 0, &err);
					IntDisable(WDT_WB_INT_BIT);
					*(volatile int*)WDT_BASE_ADDR = 0xffffffff; //100ms
					isJPEGPend = 0;
				}
				OS_EXIT_CRITICAL();

				jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx] = 0;
				OS_ENTER_CRITICAL();
				jpeg_task(p_cinfo, j_frame_sel, jpegDualStreamBuf.set_idx);
				//Wait Jpeg Done
				while (!((JPEG_CTRL_STATUS) & 0x1))
					; //JPEG Done Wait

				if ( jpeg_frame_cnt > 3 ) 
				{
					jpeg_temp_len = JPEG_MI_OS_LEN;
 					for ( nop_i = 0; nop_i < 1000; nop_i++ ) __asm __volatile("l.nop   0");
					while ( jpeg_temp_len != JPEG_MI_OS_LEN )
					{
						jpeg_temp_len = JPEG_MI_OS_LEN;
 						for ( nop_i = 0; nop_i < 1000; nop_i++ ) __asm __volatile("l.nop   0");
					}

					jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx]
							= JPEG_MI_OS_LEN;

					if ( jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx] < 12 * 1024 )
					{

						jpeg_int_temp0 = 
							*(volatile int*)(JPEG_STREAM_ADDR + (jpegDualStreamBuf.set_idx * MAX_JPEG_STREAM_LEN) + jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx] - 8);
						jpeg_int_temp1 = 
							*(volatile int*)(JPEG_STREAM_ADDR + (jpegDualStreamBuf.set_idx * MAX_JPEG_STREAM_LEN) + jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx] - 4);

						jpeg_temp[0] = jpeg_int_temp0; 
						jpeg_temp[1] = jpeg_int_temp0 >> 8; 
						jpeg_temp[2] = jpeg_int_temp0 >> 16; 
						jpeg_temp[3] = jpeg_int_temp0 >> 24; 
						jpeg_temp[4] = jpeg_int_temp1; 
						jpeg_temp[5] = jpeg_int_temp1 >> 8; 
						jpeg_temp[6] = jpeg_int_temp1 >> 16; 
						jpeg_temp[7] = jpeg_int_temp1 >> 24; 
						for ( i = 1; i < 8; i++ )
						{
							if ( jpeg_temp[i-1] == 0xff )
								if ( jpeg_temp[i] == 0xd9 )
									break;
						}

						if ( i != 8 )
						{
							i++;
							for ( ; i < 8; i++ )
								jpeg_temp[i] = 0x00;

							jpeg_int_temp0 = (((int)jpeg_temp[0] <<  0) & 0x000000ff )
										   | (((int)jpeg_temp[1] <<  8) & 0x0000ff00 )
										   | (((int)jpeg_temp[2] << 16) & 0x00ff0000 )
										   | (((int)jpeg_temp[3] << 24) & 0xff000000 );
							jpeg_int_temp1 = (((int)jpeg_temp[4] <<  0) & 0x000000ff )
										   | (((int)jpeg_temp[5] <<  8) & 0x0000ff00 )
										   | (((int)jpeg_temp[6] << 16) & 0x00ff0000 )
										   | (((int)jpeg_temp[7] << 24) & 0xff000000 );

							*(volatile int*)(JPEG_STREAM_ADDR + (jpegDualStreamBuf.set_idx * MAX_JPEG_STREAM_LEN) + jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx] - 8)
								= jpeg_int_temp0;
							*(volatile int*)(JPEG_STREAM_ADDR + (jpegDualStreamBuf.set_idx * MAX_JPEG_STREAM_LEN) + jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx] - 4)
								= jpeg_int_temp1;
							for ( i = 0; i < 16; i+= 4 )
							{
								*(volatile int*)(JPEG_STREAM_ADDR + (jpegDualStreamBuf.set_idx * MAX_JPEG_STREAM_LEN) + jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx] + i)
									= 0x00000000;
							}
							
							jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx] = 
								((jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx] >> 4) << 4) + 16;
							if ( !command_video_stop )
								jpegDualStreamBuf.full[(int)jpegDualStreamBuf.set_idx] = 1;
							//uart_print("jr\n");	
						}

						if ( jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx] > 8 * 1024 )
						{
							temp_jpeg_quality = JPEG_QUALITY_FACTOR - 1;
							if ( temp_jpeg_quality < 10 )
								temp_jpeg_quality = 10;
							JPEG_QUALITY_FACTOR = temp_jpeg_quality;
						}
						else if ( jpegDualStreamBuf.len[(int)jpegDualStreamBuf.set_idx] < 4 * 1024 )
						{
 							temp_jpeg_quality = JPEG_QUALITY_FACTOR + 1;
							if ( temp_jpeg_quality > 80 )
								temp_jpeg_quality = 80;
							JPEG_QUALITY_FACTOR = temp_jpeg_quality;
						}
					}
					else
					{
						temp_jpeg_quality = JPEG_QUALITY_FACTOR - 5;
						if ( temp_jpeg_quality < 10 )
							temp_jpeg_quality = 10;
						JPEG_QUALITY_FACTOR = temp_jpeg_quality;
					}
				}
				OS_EXIT_CRITICAL();
			}

			if ( encodeDone )
			{
				img.number++;
				if ( avata_capture_mode )
				{
					if ( img.number % 30 == 29 )
						OPERATION_DEFINE3 |= KEYFRAME_REQUEST_BIT;
				}
				else if ( encodeCnt == 60 )
				{
					OPERATION_DEFINE3 |= KEYFRAME_REQUEST_BIT;
				}
				else if ( encodeCnt == 120 )
				{
					OPERATION_DEFINE3 |= KEYFRAME_REQUEST_BIT;
				}

				if (frame_sel == 0)
					frame_sel = 1;
				else if (frame_sel == 1)
					frame_sel = 2;
				else
					frame_sel = 0;

  				if ( H264_RESOLUTION == H264_VGA || H264_RESOLUTION == H264_HD)
  				{
					IMAGE_ENCODING_ONE_FRAME_DONE = 1;
				}
				else if ( H264_RESOLUTION == H264_QVGA || H264_RESOLUTION == H264_QQVGA ) //TODO
				{
					S_IMAGE_ENCODING_ONE_FRAME_DONE = 1;
				}
			}

			if (j_frame_sel == 0)
				j_frame_sel = 1;
			else if (j_frame_sel == 1)
				j_frame_sel = 2;
			else
				j_frame_sel = 0;

			jpeg_frame_cnt++;

  			if ( H264_RESOLUTION == H264_VGA || H264_RESOLUTION == H264_HD)
  			{
				S_IMAGE_ENCODING_ONE_FRAME_DONE = 1;
			}
			else if ( H264_RESOLUTION == H264_QVGA || H264_RESOLUTION == H264_QQVGA ) //TODO
			{
			  IMAGE_ENCODING_ONE_FRAME_DONE = 1;
			}

			if ( command_video_stop )
			{
				if ( avata_capture_mode )
				{
					//uart_print("Avata Capture Mode Done\n\r");
 					for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");
					HOST_RESET = 0x03;
					while(1);
				}
				command_video_stop = 0;

				while (frame_sel != 1 )
				{
					while (IMAGE_FRAME_CNT < 2)
							;
					while (S_IMAGE_FRAME_CNT < 2)
							;
					if (frame_sel == 0)
						frame_sel = 1;
					else if (frame_sel == 1)
						frame_sel = 2;
					else
						frame_sel = 0;

  					if ( H264_RESOLUTION == H264_VGA || H264_RESOLUTION == H264_HD)
  					{
						IMAGE_ENCODING_ONE_FRAME_DONE = 1;
					}
					else if ( H264_RESOLUTION == H264_QVGA || H264_RESOLUTION == H264_QQVGA ) //TODO
					{
						S_IMAGE_ENCODING_ONE_FRAME_DONE = 1;
					}
				}

				while (j_frame_sel != 1 )
				{
					while (IMAGE_FRAME_CNT < 2)
							;
					while (S_IMAGE_FRAME_CNT < 2)
							;
					if (j_frame_sel == 0)
						j_frame_sel = 1;
					else if (j_frame_sel == 1)
						j_frame_sel = 2;
					else
						j_frame_sel = 0;

  					if ( H264_RESOLUTION == H264_VGA || H264_RESOLUTION == H264_HD)
  					{
						S_IMAGE_ENCODING_ONE_FRAME_DONE = 1;
					}
					else if ( H264_RESOLUTION == H264_QVGA || H264_RESOLUTION == H264_QQVGA ) //TODO
					{
						IMAGE_ENCODING_ONE_FRAME_DONE = 1;
					}
				}

				while (IMAGE_FRAME_CNT < 2)
					;
				while (S_IMAGE_FRAME_CNT < 2)
					;

				IMAGE_ENABLE = 0;
				S_IMAGE_ENABLE = 0;

				init_video_streamBuf();
				free_global_buffers();
				//uart_print("Command Stop\n\r");
				break;
			}
		}

	}


	uart_print("out loop\n\r");
	__asm __volatile("l.nop   0");
	__asm __volatile("l.nop   0");
	__asm __volatile("l.nop   0");
	__asm __volatile("l.nop   0");
	__asm __volatile("l.nop   0");
	__asm __volatile("l.nop   0");
	__asm __volatile("l.nop   0");
	__asm __volatile("l.nop   0");
	__asm __volatile("l.nop   0");
	__asm __volatile("l.nop   0");
	__asm __volatile("l.nop   0");

	while (1)
		; 

	return 0;
}

/*!
 ***********************************************************************
 * \brief
 *    Initializes the img.nz_coeff
 * \par Input:
 *    none
 * \par  Output:
 *    none
 * \ side effects
 *    sets omg->nz_coef[][][][] to -1
 ***********************************************************************
 */
//void CAVLC_init()
//{
//  int i, j, k, l;
//
//  for (i=0;i < img.width/MB_BLOCK_SIZE; i++)
//    for (j=0; j < img.height/MB_BLOCK_SIZE; j++)
//      for (k=0;k<4;k++)
//        for (l=0;l<6;l++)
//          img.nz_coeff[i][j][k][l]= 0xffffffff;
//
//  MSG(CAVLC_INIT);
//}


/*!
 ***********************************************************************
 * \brief
 *    Initializes the Image structure with appropriate parameters.
 * \par Input:
 *    Input Parameters struct inp_par *inp
 * \par  Output:
 *    Image Parameters struct img_par *img
 ***********************************************************************
 */
void init_img() {
	//  int j;

	img.nal_reference_idc = 1;

	// INIT_MEMORY_OFFSET
	//init_offset();
	bitstream_init();

	//img.width0 = input.img_width0;
	//img.height0 = input.img_height0;
	//img.width1 = input.img_width1;
	//img.height1 = input.img_height1;
	img.width = input.img_width;
	img.height = input.img_height;
	//  img.width_mul_height  = img.width * img.height;
	//  img.cam_width    = input.cam_width;
	//  img.cam_height   = input.cam_height;
	//img.width_cr0 = input.img_width0 >> 1;
	//img.height_cr0 = input.img_height0 >> 1;
	//img.width_cr1 = input.img_width1 >> 1;
	//img.height_cr1 = input.img_height1 >> 1;
	img.width_cr = input.img_width >> 1;
	img.height_cr = input.img_height >> 1;

	//MSGX(img.width);
	//MSGX(img.height);

	//img.PicWidthInMbs0 = input.img_width0 / MB_BLOCK_SIZE;
	//img.FrameHeightInMbs0 = input.img_height0 / MB_BLOCK_SIZE;
	//img.FrameSizeInMbs0 = img.PicWidthInMbs0 * img.FrameHeightInMbs0;
	//img.PicWidthInMbs1 = input.img_width1 / MB_BLOCK_SIZE;
	//img.FrameHeightInMbs1 = input.img_height1 / MB_BLOCK_SIZE;
	//img.FrameSizeInMbs1 = img.PicWidthInMbs1 * img.FrameHeightInMbs1;
	img.PicWidthInMbs = input.img_width / MB_BLOCK_SIZE;
	img.FrameHeightInMbs = input.img_height / MB_BLOCK_SIZE;
	img.FrameSizeInMbs = img.PicWidthInMbs * img.FrameHeightInMbs;

	//  if(((img.mb_data) = (Macroblock *) malloc(img.FrameSizeInMbs*sizeof(Macroblock))) == NULL)
	//    no_mem_exit("init_img: img.mb_data");
	//tube_print("malloc init_img\n");
	//TUBE_0_PRINT_WORD(img.PicWidthInMbs*sizeof(Macroblock));
	if (((img.mb_data_v) = (Prev_Macroblock *) malloc(img.PicWidthInMbs
			* sizeof(Prev_Macroblock))) == NULL)
		no_mem_exit("init_img: img.mb_data_v");
	//TUBE_0_PRINT_WORD(img.mb_data_v);

	// CAVLC mem
	//  if((img.nz_coeff = (int****)malloc((img.width/MB_BLOCK_SIZE)*sizeof(int***))) == NULL)
	//    no_mem_exit("get_mem4global_buffers: nzcoeff");
	//
	//  for(j=0;j<img.width/MB_BLOCK_SIZE;j++)
	//  {
	//    get_mem3Dint(&(img.nz_coeff[j]), img.height/MB_BLOCK_SIZE, 4, 6);
	//  }

	//int *nz_coeff_u;
	//int *nz_coeff_l;

	//tube_print("malloc init_img2\n");
	//TUBE_0_PRINT_WORD(img.PicWidthInMbs*8*sizeof(int));
	//  if((img.nz_coeff_u = (int*) malloc(img.PicWidthInMbs*8*sizeof(int))) == NULL)
	//	no_mem_exit("init_img: nz_coeff_u");
	//TUBE_0_PRINT_WORD(img.nz_coeff_u);

	//tube_print("malloc init_img3\n");
	//TUBE_0_PRINT_WORD(8*sizeof(int));
	//  if((img.nz_coeff_l = (int*) malloc(8*sizeof(int))) == NULL)
	//	no_mem_exit("init_img: nz_coeff_l");
	//TUBE_0_PRINT_WORD(img.nz_coeff_l);

	img.mb_y_upd = 0;

	if (input.LFSendParameters) {
		input.LFAlphaC0Offset <<= 1;
		input.LFBetaOffset <<= 1;
	} else {
		input.LFDisableIdc = 0;
		input.LFAlphaC0Offset = 0;
		input.LFBetaOffset = 0;
	}
	//MSG(LOOP_FILTER_PARAMETER_INIT);

	//#ifdef USE_ADF
	//if ( USE_ADF )
	//{
	Deblock_Control1(input.LFDisableIdc, input.qp0);
	Deblock_Control2(input.LFAlphaC0Offset, input.LFBetaOffset);
	//#endif
	//}
	//  Deblock_Dimension(img.width, img.height);

	//MSG(INIT_IMG);
}

/*!
 ***********************************************************************
 * \brief
 *    Free the Image structures
 * \par Input:
 *    Image Parameters struct img_par *img
 ***********************************************************************
 */
void free_img() {
	//MSG(FREE_IMG);
}

/*!
 ************************************************************************
 * \brief
 *    Allocates the picture structure along with its dependent
 *    data structures
 * \return
 *    Pointer to a Picture
 ************************************************************************
 */

Picture *malloc_picture() {
	Picture *pic;
	//tube_print("malloc malloc_picture\n");
	//TUBE_0_PRINT_WORD(sizeof (Picture));
	if ((pic = malloc(sizeof(Picture))) == NULL)
		no_mem_exit("malloc_picture: Picture structure");
	//TUBE_0_PRINT_WORD(pic);

	//MSG(MALLOC_PICTURE);
	return pic;
}

/*!
 ************************************************************************
 * \brief
 *    Frees a picture
 * \param
 *    pic: POinter to a Picture to be freed
 ************************************************************************
 */
void free_picture(Picture *pic) {
	if (pic != NULL) {
		//    free_slice_list(pic);
		free(pic);
	}
	//MSG(FREE_PICTURE);

}

/*!
 ************************************************************************
 * \brief
 *    Dynamic memory allocation of frame size related global buffers
 *    buffers are defined in global.h, allocated memory must be freed in
 *    void free_global_buffers()
 * \par Input:
 *    Input Parameters struct inp_par *inp,                            \n
 *    Image Parameters struct img_par *img
 * \return Number of allocated bytes
 ************************************************************************
 */
//int init_global_buffers()
//{
//  int memory_size=0;
//
//  // Rate Control
//  //if(input.RCEnable) rc_alloc();
//  
//  MSG(INIT_GLOBAL_BUFFERS);
//  
//  return (memory_size);
//}

/*!
 ************************************************************************
 * \brief
 *    Free allocated memory of frame size related global buffers
 *    buffers are defined in global.h, allocated memory is allocated in
 *    int get_mem4global_buffers()
 * \par Input:
 *    Input Parameters struct inp_par *inp,                             \n
 *    Image Parameters struct img_par *img
 * \par Output:
 *    none
 ************************************************************************
 */
void free_global_buffers() {
	if ( img.mb_data_v )
		free(img.mb_data_v);

	//  if(img.nz_coeff_u != NULL) free(img.nz_coeff_u);
	//  if(img.nz_coeff_l != NULL) free(img.nz_coeff_l);

	// Rate Control
	//if (input.RCEnable) rc_free();

	//MSG(FREE_GLOBAL_BUFFERS);
}

/*!
 ************************************************************************
 * \brief
 *    Set the image type for I,P and SP pictures (not B!)
 ************************************************************************
 */
void SetImgType() {


	//SKYPE Request
	if ( KEYFRAME_REQUEST )
	{
		//uart_print("key\n\r");
		OPERATION_DEFINE3 &= ~KEYFRAME_REQUEST_BIT;
		//init_video_streamBuf();
		GenerateParameterSets(); // don't care
		start_sequence(); // write sequence header (with parameter sets)
		FreeParameterSets();
		set_img_size_to_dmac(img.width, img.height); // to set width, height in DMAC reg
		img.number = 0;
		img.framepoc = IMG_NUMBER * 2;
		img.frame_num = IMG_NUMBER & 0xff;
	}

	if (input.intra_period == 0) {
		if (IMG_NUMBER == 0)
			img.type = I_SLICE; // set image type for first image to I-frame
		else
		//{
		//	if ( KEYFRAME_REQUEST )
		//	{
		//		OPERATION_DEFINE3 &= ~KEYFRAME_REQUEST_BIT;
		//		img.type = I_SLICE;
		//	}
		//	else
		//	{
		//		img.type = P_SLICE; // P-frame
		//	}
		//}
			img.type = P_SLICE; // P-frame
	} else {
		if ((IMG_NUMBER % input.intra_period) == 0)
			img.type = I_SLICE;
		else
			img.type = P_SLICE; // P-frame
	}
	//MSGX(img.frame_num);
	//MSGX(img.framepoc);
	//MSG(SET_IMG_TYPE);
}

void jpeg_task(j_compress_ptr cinfo, int jpeg_ref_frame, int dst_buf_num)
{
	//When camera interface, jpeg can start only after whole frame is ready
	//if (FRAME_SRC_SEL == 0x1)
	//{
	//	while(IMAGE_FRAME_CNT == 0);
	//}

	//if ( no_downsampling )
	//{
	//	JPEG_SIZE_W = IMAGE_OUT_W;
	//	JPEG_SIZE_H = IMAGE_OUT_H;
	//	ds_coef = 2;
	//}
	//else
	//{
	//	JPEG_SIZE_W = JPEG_WIDTH;
	//	JPEG_SIZE_H = JPEG_HEIGHT;
	//	switch (JPEG_HEIGHT)
	//	{
	//		case 9: // qcif
	//		switch (IMAGE_OUT_H)
	//		{
	//			case 64: // sxga
	//			ds_coef = 14;
	//			break;
	//			case 45: // hd720
	//			ds_coef = 10;
	//			break;
	//			case 30: // vga
	//			ds_coef = 6;
	//			break;
	//			default:
	//			ds_coef = 2;
	//			break;
	//		}
	//		case 18: // cif
	//		switch (IMAGE_OUT_H)
	//		{
	//			case 64: // sxga
	//			ds_coef = 7;
	//			break;
	//			case 45: // hd720
	//			ds_coef = 5;
	//			break;
	//			case 30: // vga
	//			ds_coef = 3;
	//			break;
	//			default:
	//			ds_coef = 2;
	//			break;
	//		}
	//		case 15: // qvga
	//		switch (IMAGE_OUT_H)
	//		{
	//			case 64: // sxga
	//			ds_coef = 8;
	//			break;
	//			case 45: // hd720
	//			ds_coef = 6;
	//			break;
	//			case 30: // vga
	//			ds_coef = 4;
	//			break;
	//			default:
	//			ds_coef = 2;
	//			break;
	//		}
	//		case 30: // vga
	//		switch (IMAGE_OUT_H)
	//		{
	//			case 64: // sxga
	//			ds_coef = 4;
	//			break;
	//			case 45: // hd720
	//			ds_coef = 3;
	//			break;
	//			default:
	//			ds_coef = 2;
	//			break;
	//		}
	//		default:
	//		ds_coef = 2;
	//		break;
	//	}
	//}

	JPEG_SIZE_W = JPEG_WIDTH;
	JPEG_SIZE_H = JPEG_HEIGHT;

	jpeg_init(1, cinfo, jpeg_ref_frame, dst_buf_num); //kik+++      initialization
	jpeg_api(cinfo, 1);
}

// hjlee 2010.06.25 (begin: new simpleRateControl)
void simpleRateControl(void)
{
	//Simple Rate Control
	int target_bit_rate = 0;
	int target_frame_rate = 0;
	int target_one_frame_size_byte = 0;
	int orig_target_one_frame_size_byte = 0;
	int result_one_frame_size_byte = 0;
	//int average_frame_size = 0;
	static int prev_target_bit_rate = 0;
	static int prev_target_frame_rate = 0;

	target_bit_rate  = RATE_CONTROL_BIT_RATE_VALUE;
	if ( target_bit_rate > max_bit_rate_value )  target_bit_rate =  max_bit_rate_value;
	target_frame_rate  = RATE_CONTROL_FRAME_RATE;

	if ( target_bit_rate != prev_target_bit_rate )
	{
		//Setting Default QP // {{{
		if ( target_bit_rate > ( 1000 * 1024 ) )
		{
			input.qp0 = input.qpN = 29;
		}
		else if ( target_bit_rate >  ( 900 * 1024 ) )
		{
			input.qp0 = input.qpN = 30;
		}
		else if ( target_bit_rate >  ( 800 * 1024 ) )
		{
			input.qp0 = input.qpN = 32;
		}
		else if ( target_bit_rate >  ( 700 * 1024 ) )
		{
			input.qp0 = input.qpN = 34;
		}
		else if ( target_bit_rate >  ( 600 * 1024 ) )
			input.qp0 = input.qpN = 36;
		else if ( target_bit_rate >  ( 500 * 1024 ) )
			input.qp0 = input.qpN = 39;
		else if ( target_bit_rate >  ( 400 * 1024 ) )
			input.qp0 = input.qpN = 41;
		else if ( target_bit_rate >  ( 300 * 1024 ) )
			input.qp0 = input.qpN = 43;
		else if ( target_bit_rate >  ( 200 * 1024 ) )
			input.qp0 = input.qpN = 45;
		else if ( target_bit_rate >  ( 100 * 1024 ) )
			input.qp0 = input.qpN = 47;
		else
			input.qp0 = input.qpN = 49;
		// }}}
	}

	target_one_frame_size_byte = (target_bit_rate / target_frame_rate) / 8;
	orig_target_one_frame_size_byte = (target_bit_rate / RATE_CONTROL_FRAME_RATE) / 8;

	result_one_frame_size_byte = 
		h264DualStreamBuf.len[(int)h264DualStreamBuf.set_idx];

	if  ( target_one_frame_size_byte > result_one_frame_size_byte + 2048)
	{
		input.qpN -= 4;
		more_than_orig_target_cnt=0; 
	}
	else if  ( target_one_frame_size_byte > result_one_frame_size_byte + 1024 )
	{
		input.qpN -= 3;
		if (qpN_minus_1_flag) {
			input.qpN -= 1;
			qpN_minus_1_flag = 0;
		} else
			qpN_minus_1_flag = 1;
		more_than_orig_target_cnt=0; 
	}
	else if  ( target_one_frame_size_byte > result_one_frame_size_byte + 768 )
	{
		input.qpN -= 2;
		if (qpN_minus_1_flag) {
			input.qpN -= 1;
			qpN_minus_1_flag = 0;
		} else
			qpN_minus_1_flag = 1;
		more_than_orig_target_cnt=0; 
	}
	else if  ( target_one_frame_size_byte > result_one_frame_size_byte + 512 )
	{
		input.qpN -= 2;
		more_than_orig_target_cnt=0; 
	}
	else if (target_one_frame_size_byte > result_one_frame_size_byte + 384) {
		input.qpN -= 1;
		if (qpN_minus_1_flag) {
			input.qpN -= 1;
			qpN_minus_1_flag = 0;
		} else
			qpN_minus_1_flag = 1;
		more_than_orig_target_cnt=0; 
	}
	else if  ( target_one_frame_size_byte > result_one_frame_size_byte + 256 )
	{
		input.qpN -= 1;
		more_than_orig_target_cnt=0; 
	}
	else if ( target_one_frame_size_byte < result_one_frame_size_byte - 2048 )
	{	
		input.qpN += 5;
		less_than_orig_target_cnt=0; 
	}
	else if ( target_one_frame_size_byte < result_one_frame_size_byte - 1536)
	{	
		input.qpN += 4;
		less_than_orig_target_cnt=0; // hjlee 2010.06.25
	}
	else if ( target_one_frame_size_byte < result_one_frame_size_byte - 1024 )
	{	
		input.qpN += 3;
		less_than_orig_target_cnt=0; // hjlee 2010.06.25
	}
	else if ( target_one_frame_size_byte < result_one_frame_size_byte - 768)
	{	
		input.qpN += 2;
		if (qpN_plus_1_flag) {
			input.qpN += 1;
			qpN_plus_1_flag = 0;
		} else
			qpN_plus_1_flag = 1;
		less_than_orig_target_cnt=0; // hjlee 2010.06.25
	}
	else if ( target_one_frame_size_byte < result_one_frame_size_byte - 512 )
	{	
		input.qpN += 2;
		less_than_orig_target_cnt=0; // hjlee 2010.06.25
	}
	else if ( target_one_frame_size_byte < result_one_frame_size_byte - 384)
	{	
		input.qpN += 1;
		if (qpN_plus_1_flag) {
			input.qpN += 1;
			qpN_plus_1_flag = 0;
		} else
			qpN_plus_1_flag = 1;
		less_than_orig_target_cnt=0; // hjlee 2010.06.25
	}
	else if ( target_one_frame_size_byte < result_one_frame_size_byte - 256 )
	{	
		input.qpN += 1;
		less_than_orig_target_cnt=0; // hjlee 2010.06.25
	}
	else {
	    //if  ( orig_target_one_frame_size_byte > result_one_frame_size_byte + 256 )
	    if  ( result_one_frame_size_byte < target_one_frame_size_byte ) {
		less_than_orig_target_cnt++;
		if ( less_than_orig_target_cnt > 2 ) 
		{
			input.qpN -= 1;
		} else
		more_than_orig_target_cnt = 0;
	    }
	    else if  ( result_one_frame_size_byte >= target_one_frame_size_byte )
	    {
		more_than_orig_target_cnt++;
		if ( more_than_orig_target_cnt > 2 ) 
		{
			input.qpN += 1;
		} else
		less_than_orig_target_cnt = 0;
	    }
	}

	if ( input.qpN < MIN_SIMPLE_RATE_CONTROL_QP )
		input.qpN = MIN_SIMPLE_RATE_CONTROL_QP;
	else if ( input.qpN > MAX_SIMPLE_RATE_CONTROL_QP )
		input.qpN = MAX_SIMPLE_RATE_CONTROL_QP;

	input.qp0 = input.qpN;

/* simpleLIneRateControl
	if(img.type==P_SLICE &&
	   img.number%fake_intra_period!=0&&
	   img.number%fake_intra_period!=1&&
	   img.number%fake_intra_period!=(fake_intra_period-1))
		input.qpN -= 2; // chae 2010.06.17
*/
	prev_target_bit_rate = target_bit_rate;
	prev_target_frame_rate = target_frame_rate;

	//uart_print("rate:");
	//uart_printInt(input.qpN);
	//uart_print(",");
	//uart_printInt(target_one_frame_size_byte);
	//uart_print(",");
	//uart_printInt(result_one_frame_size_byte);
	//uart_print("\n\r");

}
// hjlee 2010.06.25 (end: new simpleRateControl)

/*
void simpleRateControl(void)
{
	//Simple Rate Control
	int target_bit_rate = 0;
	int target_frame_rate = 0;
	int target_one_frame_size_byte = 0;
	int orig_target_one_frame_size_byte = 0;
	int result_one_frame_size_byte = 0;
	//int average_frame_size = 0;
	static int prev_target_bit_rate = 0;
	static int prev_target_frame_rate = 0;

	target_bit_rate  = RATE_CONTROL_BIT_RATE_VALUE;
	if ( target_bit_rate > max_bit_rate_value )  target_bit_rate =  max_bit_rate_value;
	target_frame_rate  = RATE_CONTROL_FRAME_RATE;

	if ( target_bit_rate != prev_target_bit_rate )
	{
		//Setting Default QP // {{{
		if ( target_bit_rate > ( 1000 * 1024 ) )
		{
			input.qp0 = input.qpN = 29;
		}
		else if ( target_bit_rate >  ( 900 * 1024 ) )
		{
			input.qp0 = input.qpN = 30;
		}
		else if ( target_bit_rate >  ( 800 * 1024 ) )
		{
			input.qp0 = input.qpN = 32;
		}
		else if ( target_bit_rate >  ( 700 * 1024 ) )
		{
			input.qp0 = input.qpN = 34;
		}
		else if ( target_bit_rate >  ( 600 * 1024 ) )
			input.qp0 = input.qpN = 36;
		else if ( target_bit_rate >  ( 500 * 1024 ) )
			input.qp0 = input.qpN = 39;
		else if ( target_bit_rate >  ( 400 * 1024 ) )
			input.qp0 = input.qpN = 41;
		else if ( target_bit_rate >  ( 300 * 1024 ) )
			input.qp0 = input.qpN = 43;
		else if ( target_bit_rate >  ( 200 * 1024 ) )
			input.qp0 = input.qpN = 45;
		else if ( target_bit_rate >  ( 100 * 1024 ) )
			input.qp0 = input.qpN = 47;
		else
			input.qp0 = input.qpN = 49;
		// }}}
	}

	target_one_frame_size_byte = (target_bit_rate / target_frame_rate) / 8;
	orig_target_one_frame_size_byte = (target_bit_rate / RATE_CONTROL_FRAME_RATE) / 8;

	result_one_frame_size_byte = 
		h264DualStreamBuf.len[(int)h264DualStreamBuf.set_idx];

	if  ( target_one_frame_size_byte > result_one_frame_size_byte + 1024 )
	{
		input.qpN -= 3;
	}
	else if  ( target_one_frame_size_byte > result_one_frame_size_byte + 512 )
	{
		input.qpN -= 2;
	}
	else if  ( target_one_frame_size_byte > result_one_frame_size_byte + 256 )
	{
		input.qpN -= 1;
	}
	else if  ( orig_target_one_frame_size_byte > result_one_frame_size_byte + 256 )
	{
		less_than_orig_target_cnt++;
		if ( less_than_orig_target_cnt > 2 ) 
		{
			input.qpN -= 1;
		}
	}
	else if ( target_one_frame_size_byte < result_one_frame_size_byte - 2048 )
	{	
		input.qpN += 6;
	}
	else if ( target_one_frame_size_byte < result_one_frame_size_byte - 1024 )
	{	
		input.qpN += 3;
	}
	else if ( target_one_frame_size_byte < result_one_frame_size_byte - 512 )
	{	
		input.qpN += 2;
	}
	else if ( target_one_frame_size_byte < result_one_frame_size_byte - 256 )
	{	
		input.qpN += 1;
	}
	else if ( orig_target_one_frame_size_byte < result_one_frame_size_byte - 256 )
	{
		less_than_orig_target_cnt = 0;

	}

	if ( input.qpN < MIN_SIMPLE_RATE_CONTROL_QP )
		input.qpN = MIN_SIMPLE_RATE_CONTROL_QP;
	else if ( input.qpN > MAX_SIMPLE_RATE_CONTROL_QP )
		input.qpN = MAX_SIMPLE_RATE_CONTROL_QP;

	input.qp0 = input.qpN;

// simpleLIneRateControl
//	if(img.type==P_SLICE &&
//	   img.number%fake_intra_period!=0&&
//	   img.number%fake_intra_period!=1&&
//	   img.number%fake_intra_period!=(fake_intra_period-1))
//		input.qpN -= 2; // chae 2010.06.17
//
	prev_target_bit_rate = target_bit_rate;
	prev_target_frame_rate = target_frame_rate;

	//uart_print("rate:");
	//uart_printInt(input.qpN);
	//uart_print(",");
	//uart_printInt(target_one_frame_size_byte);
	//uart_print(",");
	//uart_printInt(result_one_frame_size_byte);
	//uart_print("\n\r");

}
*/
int AlignOffsetAddr(int offset, int align)
{
    int aligned_addr;

    if (offset % align) {
        aligned_addr = offset - (offset % align) + align;
    }
	 else
        aligned_addr = offset;

    return aligned_addr;
}

void SetupForDoubleBuffer(int frame_sel, int double_buffer_en, int width_offset, int height_offset, int src_ref_frame_diff)
{
	const int width = (ORC_FRAME_SIZE & 0xffff);
	const int height = ((ORC_FRAME_SIZE >> 16) & 0xffff);
	const int cam_width = (ORC_CAM_SIZE & 0xffff);
	int cam_cb_offset;
	int cam_cr_offset;
	int cam_cb_offset_aligned;
	int cam_cr_offset_aligned;
	int src_frame_base;
	int ref_frame_base;
	int recon_frame_base; //2010.06.04

	int src_base = 0;

  	if ( H264_RESOLUTION == H264_VGA || H264_RESOLUTION == H264_HD)
	{
		src_base = SRC_BASE;
	}
	else if ( H264_RESOLUTION == H264_QVGA || H264_RESOLUTION == H264_QQVGA ) //TODO
	{
		src_base = S_SRC_BASE;
	}

	if (width < 640)
		cam_cb_offset         = 640*480;
	else
		cam_cb_offset         = width*height;

	cam_cb_offset_aligned = AlignOffsetAddr(cam_cb_offset, 1024);
	cam_cr_offset         = cam_cb_offset_aligned + cam_cb_offset/4;
	cam_cr_offset_aligned = AlignOffsetAddr(cam_cr_offset, 1024);

        cam_cb_offset_aligned_temp = cam_cb_offset_aligned;  //2010.06.04
        cam_cr_offset_aligned_temp = cam_cr_offset_aligned;  //2010.06.04

//kik_fw---  
//kik_fw---          if(frame_sel == 0)
//kik_fw---          {
//kik_fw---              if(img.type==P_SLICE && img.number%fake_intra_period==0){
//kik_fw---                  src_frame_base   = SRC_BASE + FRAME_OFFSET1;        //prev
//kik_fw---                  recon_frame_base = SRC_BASE;                        //curr
//kik_fw---                  ref_frame_base   = SRC_BASE + FRAME_OFFSET1;        //don't care
//kik_fw---              }else if(img.type==P_SLICE && img.number%fake_intra_period==(fake_intra_period-1)){
//kik_fw---                  src_frame_base   = SRC_BASE;                        //curr
//kik_fw---                  recon_frame_base = JPEG_STREAM_BASE2;               //temp
//kik_fw---                  ref_frame_base   = SRC_BASE+FRAME_OFFSET1;          //prev
//kik_fw---              }else if(img.type==P_SLICE && img.number%fake_intra_period==1 && img.number!=1){
//kik_fw---                  src_frame_base   = SRC_BASE;                        //curr
//kik_fw---                  recon_frame_base = SRC_BASE;                        //curr
//kik_fw---                  ref_frame_base   = SRC_BASE+FRAME_OFFSET1;          //prev when I
//kik_fw---              }else{
//kik_fw---                  src_frame_base   = SRC_BASE;
//kik_fw---                  recon_frame_base = SRC_BASE;
//kik_fw---                  ref_frame_base   = SRC_BASE + FRAME_OFFSET1;
//kik_fw---              }
//kik_fw---          }
//kik_fw---          else if(frame_sel == 1)
//kik_fw---          {
//kik_fw---              if(img.type==P_SLICE && img.number%fake_intra_period==0){
//kik_fw---                  src_frame_base   = SRC_BASE;                       //prev
//kik_fw---                  recon_frame_base = SRC_BASE + FRAME_OFFSET;        //curr
//kik_fw---                  ref_frame_base   = SRC_BASE;                       //don't care
//kik_fw---              }else if(img.type==P_SLICE && img.number%fake_intra_period==(fake_intra_period-1)){
//kik_fw---                  src_frame_base   = SRC_BASE + FRAME_OFFSET;    //curr
//kik_fw---                  recon_frame_base = JPEG_STREAM_BASE2;          //temp
//kik_fw---                  ref_frame_base   = SRC_BASE;                   //prev
//kik_fw---              }else if(img.type==P_SLICE && img.number%fake_intra_period==1 && img.number!=1){
//kik_fw---                  src_frame_base   = SRC_BASE + FRAME_OFFSET;           //curr
//kik_fw---                  recon_frame_base = SRC_BASE + FRAME_OFFSET;           //curr
//kik_fw---                  ref_frame_base   = SRC_BASE;                          //prev when I
//kik_fw---              }else{
//kik_fw---                  src_frame_base   = SRC_BASE + FRAME_OFFSET;
//kik_fw---                  recon_frame_base = SRC_BASE + FRAME_OFFSET;
//kik_fw---                  ref_frame_base   = SRC_BASE;
//kik_fw---              }
//kik_fw---          }
//kik_fw---          else
//kik_fw---          {
//kik_fw---              if(img.type==P_SLICE && img.number%fake_intra_period==0){
//kik_fw---                  src_frame_base   = SRC_BASE + FRAME_OFFSET;  //prev
//kik_fw---                  recon_frame_base = SRC_BASE + FRAME_OFFSET1; //curr
//kik_fw---                  ref_frame_base   = SRC_BASE + FRAME_OFFSET;  //don't care
//kik_fw---              }else if(img.type==P_SLICE && img.number%fake_intra_period==(fake_intra_period-1)){
//kik_fw---                  src_frame_base   = SRC_BASE + FRAME_OFFSET1;  //curr
//kik_fw---                  recon_frame_base = JPEG_STREAM_BASE2;         //temp
//kik_fw---                  ref_frame_base   = SRC_BASE + FRAME_OFFSET;   //prev
//kik_fw---              }else if(img.type==P_SLICE && img.number%fake_intra_period==1 && img.number!=1){
//kik_fw---                  src_frame_base   = SRC_BASE + FRAME_OFFSET1;           //curr
//kik_fw---                  recon_frame_base = SRC_BASE + FRAME_OFFSET1;           //curr
//kik_fw---                  ref_frame_base   = SRC_BASE + FRAME_OFFSET;            //prev when I
//kik_fw---              }else{
//kik_fw---                  src_frame_base   = SRC_BASE + FRAME_OFFSET1;
//kik_fw---                  recon_frame_base = SRC_BASE + FRAME_OFFSET1;
//kik_fw---                  ref_frame_base   = SRC_BASE + FRAME_OFFSET;
//kik_fw---              }
//kik_fw---          }

        if(frame_sel == 0)
        {
            if(img.type==P_SLICE && img.number%fake_intra_period==0){
                src_frame_base   = src_base + FRAME_OFFSET1;        //prev
                recon_frame_base = src_base;                        //curr
                ref_frame_base   = src_base + FRAME_OFFSET1;        //don't care
            }else if(img.type==P_SLICE && img.number%fake_intra_period==(fake_intra_period-1)){
                src_frame_base   = src_base;                        //curr
                recon_frame_base = JPEG_STREAM_BASE2;               //temp
                ref_frame_base   = src_base+FRAME_OFFSET1;          //prev
            }else if(img.type==P_SLICE && img.number%fake_intra_period==1 && img.number!=1){
                src_frame_base   = src_base;                        //curr
                recon_frame_base = src_base;                        //curr
                ref_frame_base   = src_base+FRAME_OFFSET1;          //prev when I
            }else{
                src_frame_base   = src_base;
                recon_frame_base = src_base;
                ref_frame_base   = src_base + FRAME_OFFSET1;
            }
        }
        else if(frame_sel == 1)
        {
            if(img.type==P_SLICE && img.number%fake_intra_period==0){
                src_frame_base   = src_base;                       //prev
                recon_frame_base = src_base + FRAME_OFFSET;        //curr
                ref_frame_base   = src_base;                       //don't care
            }else if(img.type==P_SLICE && img.number%fake_intra_period==(fake_intra_period-1)){
                src_frame_base   = src_base + FRAME_OFFSET;    //curr
                recon_frame_base = JPEG_STREAM_BASE2;          //temp
                ref_frame_base   = src_base;                   //prev
            }else if(img.type==P_SLICE && img.number%fake_intra_period==1 && img.number!=1){
                src_frame_base   = src_base + FRAME_OFFSET;           //curr
                recon_frame_base = src_base + FRAME_OFFSET;           //curr
                ref_frame_base   = src_base;                          //prev when I
            }else{
                src_frame_base   = src_base + FRAME_OFFSET;
                recon_frame_base = src_base + FRAME_OFFSET;
                ref_frame_base   = src_base;
            }
        }
        else
        {
            if(img.type==P_SLICE && img.number%fake_intra_period==0){
                src_frame_base   = src_base + FRAME_OFFSET;  //prev
                recon_frame_base = src_base + FRAME_OFFSET1; //curr
                ref_frame_base   = src_base + FRAME_OFFSET;  //don't care
            }else if(img.type==P_SLICE && img.number%fake_intra_period==(fake_intra_period-1)){
                src_frame_base   = src_base + FRAME_OFFSET1;  //curr
                recon_frame_base = JPEG_STREAM_BASE2;         //temp
                ref_frame_base   = src_base + FRAME_OFFSET;   //prev
            }else if(img.type==P_SLICE && img.number%fake_intra_period==1 && img.number!=1){
                src_frame_base   = src_base + FRAME_OFFSET1;           //curr
                recon_frame_base = src_base + FRAME_OFFSET1;           //curr
                ref_frame_base   = src_base + FRAME_OFFSET;            //prev when I
            }else{
                src_frame_base   = src_base + FRAME_OFFSET1;
                recon_frame_base = src_base + FRAME_OFFSET1;
                ref_frame_base   = src_base + FRAME_OFFSET;
            }
        }

        //VIM_TO_MEM
	VIM_Y_BASE = src_frame_base + cam_width*height_offset + width_offset;
	VIM_U_BASE = src_frame_base + cam_cb_offset_aligned + cam_width*height_offset/4 + width_offset/2;
	VIM_V_BASE = src_frame_base + cam_cr_offset_aligned + cam_width*height_offset/4 + width_offset/2;

	//Deblock_Target_Addr(src_frame_base, src_frame_base + cam_cb_offset_aligned, src_frame_base + cam_cr_offset_aligned);
	Deblock_Target_Addr(recon_frame_base, recon_frame_base + cam_cb_offset_aligned, recon_frame_base + cam_cr_offset_aligned); //2010.06.03

	//ME_DMA
	ME_DMA_Y_BASE = ref_frame_base;
	ME_DMA_U_BASE = ref_frame_base + cam_cb_offset_aligned;
	ME_DMA_V_BASE = ref_frame_base + cam_cr_offset_aligned;
//kik_fw+
	tmp_y = ref_frame_base;
	tmp_u = ref_frame_base + cam_cb_offset_aligned;
	tmp_v = ref_frame_base + cam_cr_offset_aligned;

}



////////////////////////////////////////////////////////////////////////////
/*
 void DVP_diagnosis()
 {
 *((volatile int *)(0xF1000000 + 0x00)) = 0x02000000;
 *((volatile int *)(0xF1000000 + 0x04)) = 0x756D614D;
 *((volatile int *)(0xF1000000 + 0x08)) = 0x6E616972;
 *((volatile int *)(0xF1000000 + 0x0C)) = 0x73654420;
 *((volatile int *)(0xF1000000 + 0x10)) = 0x206E6769;
 *((volatile int *)(0xF1000000 + 0x14)) = 0x2E636E49;
 *((volatile int *)(0xF1000000 + 0x18)) = 0xFFFF0403;
 DVP_INIT_J_ADDR = 0xF1000000 + 0x00;
 DVP_FINAL_J_ADDR = 0xF1000000 + 0x1C;
 DVP_CTRL_REG0 = 0x0;
 DVP_CTRL_REG1 = 0x9A001103;
 DVP_CTRL_REG2 = 0x5;
 DVP_CTRL_REG2 = 0x0;
 if ( OUTPUT_PATH == OUTPUT_PATH_DVP)
 STREAM_RECEIVER_SEL = 0x2;
 while(!((DVP_STATUS >> 2) & 0x1)); // wait for DVP done
 if ( OUTPUT_PATH == OUTPUT_PATH_DVP)
 STREAM_RECEIVER_SEL = 0x4;
 MSGX(0x0000DDDD); //  jarre 2008.05.22 temp temp temp debug +
 }
 */
