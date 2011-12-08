#include "global.h"
#include "fpga.h"
#include "configfile.h"

#include "map_hif.h"
#include "sensor_set.h"

#include "tube.h" //jykim_debug

int AEC_gain, AEC_gain_flicker;		// isp's global variable by signal97++
int AGC_gain, AGC_gain_flicker;		// isp's global variable by signal97++

extern unsigned char avata_capture_mode;
//extern int jpeg_length_array[4]; //090507_jarre_dvp2 -

extern int AlignOffsetAddr(int offset, int align);

extern int my_frame_num;

void Configure_via_SW()
{
	//if (LTCTRL_SW_CAM_HD) {
    //    Configure(MODE_HD);
    //} else {
    //    Configure(MODE_VGA);
    //}
    //Configure();
	// FPGA mode
	// OpenRISC self-control

 	input.slice_mode = 1;
//kik_fw++
        if(H264_RESOLUTION == H264_VGA){
 	 input.slice_argument = 40; //IP
        }
        else if(H264_RESOLUTION == H264_QVGA){
 	 input.slice_argument = 20; //IP
        } 

 	//input.slice_mode = 0;
 	//input.slice_argument = SLICE_ARGUMENT; //IP
    input.LFSendParameters        = 1;      // LoopFilterParametersFlag 
    input.LFDisableIdc            = 0;    // LoopFilterEnable
    //input.LFAlphaC0Offset         =  ((char)LF_ALPHA_CO_OFFSET); //090409_jykim_remove_register+
    //input.LFBetaOffset            =  ((char)LF_BETA_OFFSET); //090409_jykim_remove_register+
      //input.LFAlphaC0Offset         =  -3 ; //090409_jykim_remove_register+
      //input.LFBetaOffset            =  -3 ; //090409_jykim_remove_register+
      input.LFAlphaC0Offset         =  -3 ; //090409_jykim_remove_register+
      input.LFBetaOffset            =  -3 ; //090409_jykim_remove_register+
  	DCTQ_CR0 = 0x80;                                    //ME and IPDCTQ hardwired
  	ME_CR11  = 0x80000000;                                    //ME and IPDCTQ hardwired
  	OSB_FILL_RATE =  OSB_FIFO_RATE_IDX;
	ORC_FRAME_COUNT = 65535;
	FRAME_SRC_SEL = 0x1;		// Camera
	//STREAM_RECEIVER_SEL = 0x2;	// USB only //jykim_20080715_HIF_CONV--
   	STREAM_RECEIVER_SEL = 0x0;


}

void InitFPGA1()
{
	int cam_cb_offset;
	int cam_cr_offset;
	int cam_cb_offset_aligned;
	int cam_cr_offset_aligned;

	int cam2_cb_offset;
	int cam2_cr_offset;
	int cam2_cb_offset_aligned;
	int cam2_cr_offset_aligned;

	if ( avata_capture_mode )
	{
		//sensorSetToVGA();
		zoomControl(0, ZOOM_LEVEL);
		//Cam1 - H264
		SENSOR_OUT_W 	= 0x1E;	
		SENSOR_OUT_H 	= 0x1E;	
		IMAGE_OUT_W 	= 0x0F;	
		IMAGE_OUT_H 	= 0x0F;	
		//Sensor2 Setting
		SENSOR2_OUT_W 	= 0x1E; //SENSOR2_OUT_W
		SENSOR2_OUT_H 	= 0x1E; //SENSOR2_OUT_H
		IMAGE2_OUT_W  	= 0x0F; //IMAGE2_OUT_W
		IMAGE2_OUT_H  	= 0x0F; //IMAGE2_OUT_H

   		input.img_width  	= IMAGE_OUT_W * 16;		// SourceWidth
   		input.img_height    = IMAGE_OUT_H * 16;    	// SourceHeight 
   		input.cam_width     = SENSOR_OUT_W * 16;	// SourceWidth
   		input.cam_height    = SENSOR_OUT_H * 16;    // SourceHeight 

		QP_VALUE_I  = 0x18; 

		INTRA_PERIOD = 1; //I-Frame Only
		input.intra_period            = 1;	// IntraPeriod

		JPEG_WIDTH 	  	= 0x0F; //HIF_REG51  ; jpeg width
		JPEG_HEIGHT   	= 0x0F; //HIF_REG52  ; jpeg height
	}
	else
	{
		if ( H264_RESOLUTION == H264_VGA )
		{
			//sensorSetToVGA();
			zoomControl(0, ZOOM_LEVEL);
			//Cam1 - H264
			SENSOR_OUT_W 	= 0x28;	
			SENSOR_OUT_H 	= 0x1E;	
			IMAGE_OUT_W 	= 0x28;	
			IMAGE_OUT_H 	= 0x1E;	
			//Cam2 - JPEG
			SENSOR2_OUT_W 	= 0x28;	
			SENSOR2_OUT_H 	= 0x1E;	
			IMAGE2_OUT_W 	= 0x28;	
			IMAGE2_OUT_H 	= 0x1E;	

   			input.img_width  	= IMAGE_OUT_W * 16;		// SourceWidth
   			input.img_height    = IMAGE_OUT_H * 16;    	// SourceHeight 
   			input.cam_width     = SENSOR_OUT_W * 16;	// SourceWidth
   			input.cam_height    = SENSOR_OUT_H * 16;    // SourceHeight 
		}
		else if ( H264_RESOLUTION == H264_QVGA || H264_RESOLUTION == H264_QQVGA ) //TODO
		{
			//sensorSetToVGA();
			zoomControl(0, ZOOM_LEVEL);
			//Cam1 - JPEG
			SENSOR_OUT_W 	= 0x28;	
			SENSOR_OUT_H 	= 0x1E;	
			IMAGE_OUT_W 	= 0x28;	
			IMAGE_OUT_H 	= 0x1E;	
			//Cam2 - H264
			SENSOR2_OUT_W 	= 0x28;	
			SENSOR2_OUT_H 	= 0x1E;	
			IMAGE2_OUT_W 	= 0x14;	
			IMAGE2_OUT_H 	= 0x0F;	

   			input.img_width  	= IMAGE2_OUT_W * 16;		// SourceWidth
   			input.img_height    = IMAGE2_OUT_H * 16;    	// SourceHeight 
   			input.cam_width     = SENSOR2_OUT_W * 16;	// SourceWidth
   			input.cam_height    = SENSOR2_OUT_H * 16;    // SourceHeight 
		}
		else if ( H264_RESOLUTION == H264_HD )
		{
			sensorSetToHD();

			//Cam1 - H264
			SENSOR_OUT_W 	= 0x50;	
			SENSOR_OUT_H 	= 0x2D;	
			IMAGE_OUT_W 	= 0x50;	
			IMAGE_OUT_H 	= 0x2D;	
			//Cam2 - JPEG
			SENSOR2_OUT_W 	= 0x3C;	
			SENSOR2_OUT_H 	= 0x2D;	
			IMAGE2_OUT_W 	= 0x28;	
			IMAGE2_OUT_H 	= 0x1E;	

   			input.img_width  	= IMAGE_OUT_W * 16;		// SourceWidth
   			input.img_height    = IMAGE_OUT_H * 16;    	// SourceHeight 
   			input.cam_width     = SENSOR_OUT_W * 16;	// SourceWidth
   			input.cam_height    = SENSOR_OUT_H * 16;    // SourceHeight 
		}


		JPEG_WIDTH 	  	= 0x14; //HIF_REG51  ; jpeg width
		JPEG_HEIGHT   	= 0x0F; //HIF_REG52  ; jpeg height

		input.intra_period            = INTRA_PERIOD * 10;	// IntraPeriod
	}

	input.qp0                     = QP_VALUE_I;	// QPFirstFrame
	input.qpN                     = QP_VALUE_P;	// QPRemainingFrame
	input.jumpd                   = 0;	// FrameSkip //090327_henry+
	input.bit_rate =  RATE_CONTROL_BIT_RATE_VALUE;
	input.FrameRate = RATE_CONTROL_FRAME_RATE;     // init. frame rate is 15 following spec.
	input.SeinitialQP = RATE_CONTROL_SEINITIAL_QP_VALUE;   // init. Quantization Parameter. If zero, calculate QP automatically.

	ORC_CAM_SIZE = (input.cam_height << 16) | input.cam_width;
	ORC_FRAME_SIZE = (input.img_height << 16) | input.img_width;

	cam_cb_offset         = (IMAGE_OUT_W*16 < 640) ? 640*480: IMAGE_OUT_W*IMAGE_OUT_H*16*16;	//for QVGA SDRAMC2 mode
	cam_cb_offset_aligned = AlignOffsetAddr(cam_cb_offset, 1024);
	cam_cr_offset         = cam_cb_offset_aligned + cam_cb_offset/4;
	cam_cr_offset_aligned = AlignOffsetAddr(cam_cr_offset, 1024);

	cam2_cb_offset         = (IMAGE2_OUT_W*16 < 640) ? 640*480: IMAGE2_OUT_W*IMAGE2_OUT_H*16*16;	//for QVGA SDRAMC2 mode
	cam2_cb_offset_aligned = AlignOffsetAddr(cam2_cb_offset, 1024);
	cam2_cr_offset         = cam2_cb_offset_aligned + cam2_cb_offset/4;
	cam2_cr_offset_aligned = AlignOffsetAddr(cam2_cr_offset, 1024);

	//camera_interface
	IMAGE_Y_BASE = SRC_BASE;
	IMAGE_U_BASE = SRC_BASE + cam_cb_offset_aligned;
	IMAGE_V_BASE = SRC_BASE + cam_cr_offset_aligned;
	S_IMAGE_Y_BASE = S_SRC_BASE; // jarre 2009.06.09 for dual stream test +++
	S_IMAGE_U_BASE = S_SRC_BASE + cam2_cb_offset_aligned; // jarre 2009.06.09 for dual stream test +++
	S_IMAGE_V_BASE = S_SRC_BASE + cam2_cr_offset_aligned; // jarre 2009.06.09 for dual stream test +++

    IMAGE_CAM_X_SIZE = SENSOR_OUT_W * 16 * 2 - 1; 
    IMAGE_CAM_Y_SIZE = SENSOR_OUT_H * 16 - 1;

    S_IMAGE_CAM_X_SIZE = SENSOR2_OUT_W * 16 * 2 - 1;
    S_IMAGE_CAM_Y_SIZE = SENSOR2_OUT_H * 16 - 1;

	IMAGE_FRAME_X_SIZE = IMAGE_OUT_W*16*2-1;
	IMAGE_FRAME_Y_SIZE = IMAGE_OUT_H*16;

	S_IMAGE_FRAME_X_SIZE = IMAGE2_OUT_W*16*2-1; // jarre 2009.06.09 for dual stream test +++
	S_IMAGE_FRAME_Y_SIZE = IMAGE2_OUT_H*16;    // jarre 2009.06.09 for dual stream test +++

//	//Downsampling
//  	if ( (SENSOR_OUT_W > IMAGE_OUT_W) || (SENSOR_OUT_H > IMAGE_OUT_H) || (SENSOR2_OUT_W > IMAGE2_OUT_W) || (SENSOR2_OUT_H > IMAGE2_OUT_H) ) {
//
//		if ( SENSOR_OUT_W != IMAGE_OUT_W )
//		{
//			IMAGE_SAMPLE_RATE_X = SampleRateX();
//		}
//		if ( SENSOR_OUT_H != IMAGE_OUT_H )
//		{
//			IMAGE_SAMPLE_RATE_Y = SampleRateY();
//		}
//		///////////////////////////////////////////////////////////////////
//		//  // jarre 2009.06.09 for dual stream test +++
//		if ( SENSOR2_OUT_W != IMAGE2_OUT_W )
//		{
//			S_IMAGE_SAMPLE_RATE_X = SampleRateX2();
//		}
//		if ( SENSOR2_OUT_H != IMAGE2_OUT_H )
//		{
//			S_IMAGE_SAMPLE_RATE_Y = SampleRateY2();
//		}
//		//  // jarre 2009.06.09 for dual stream test +++
//		///////////////////////////////////////////////////////////////////
//	}
	IMAGE_SAMPLE_RATE_X = SampleRateX();
	IMAGE_SAMPLE_RATE_Y = SampleRateY();
	S_IMAGE_SAMPLE_RATE_X = SampleRateX2();
	S_IMAGE_SAMPLE_RATE_Y = SampleRateY2();

	DCTQ_CR3 = (640 << 16) | ((input.img_width>>4)-1); // 640=number of Y,U,V neighbor pixels(HD) | image width in mb - 1

	//Stream_word_to_mem
	STR_DST_PT = STREAM_BASE;
	STR_CNT_STREAM = 0;
	STR_CNT_OVERFLOW = 0;
	STR_CNT_MAX_QUEUE_SIZE = 0;
	STR_CNT_FOUND = 0;
	//STR_PATTERN = 0x02c1178d;
	//STR_PATTERN = 0x60000000;
	//STR_SEARCH_CTRL = 0x1;
	
	//OSC
	OSC_CNT_STREAM = 0;
	OSC_CNT_OVERFLOW = 0;
	OSC_MAX_QUEUE_SIZE = 0;

	//Cam2 PWDN
	HOST_RESET |= 0x10;

	//IMAGE_ENCODING_ONE_FRAME_DONE = 1;
	//S_IMAGE_ENCODING_ONE_FRAME_DONE = 1;
	//IMAGE_ENCODING_ONE_FRAME_DONE = 1;
	//S_IMAGE_ENCODING_ONE_FRAME_DONE = 1;

	IMAGE_ENABLE = 1;

	if ( H264_RESOLUTION == H264_HD )
		S_IMAGE_ENABLE = 3;
	else
		S_IMAGE_ENABLE = 1;

	IMAGE_DOUBLE_BUFFER_EN = 1;
	S_IMAGE_DOUBLE_BUFFER_EN = 1; // jarre 2009.06.09 for dual stream test +++

	IMAGE_FRAME_OFFSET = FRAME_OFFSET;
	IMAGE_FRAME_OFFSET1 = FRAME_OFFSET1;

	S_IMAGE_FRAME_OFFSET = FRAME_OFFSET; // jarre 2009.06.09 for dual stream test +++
	S_IMAGE_FRAME_OFFSET1 = FRAME_OFFSET1; // jarre 2009.06.09 for dual stream test +++

	IMAGE_VSYNC_SKIP_ONLY = 1;
	S_IMAGE_VSYNC_SKIP_ONLY = 1; // jarre 2009.06.09 for dual stream test +++

	IMAGE_AFIFO_SIZE_IN_BURST16 = AFIFO_ALMOST_FULL_SIZE;
	S_IMAGE_AFIFO_SIZE_IN_BURST16 = AFIFO_ALMOST_FULL_SIZE / 2; // jarre 2009.06.09 for dual stream test +++

        //chae
	//input.intra_period            = 0;	// IntraPeriod
	input.intra_period            = 1;	// IntraPeriod

}

int my_c2_addr_gen_by_index (int frame_base, int vga_x, int vga_y)
{
    int line_cnt_1024, line_pixel_1024, b22, b10, b11, b12, line_cnt, line_offset, frame_base_c2;

    line_cnt_1024 = ((640*(vga_y>>4) + vga_x) >> 10);  // ((640*(vga_y/16) + vga_x) /1024);
    line_pixel_1024 = ((640*(vga_y>>4) + vga_x) % 1024);  // ((640*(vga_y/16) + vga_x) /1024);
    
    b22 = (line_pixel_1024 & 0x40) >> 6;
    b10 = (line_pixel_1024 & 0x80) >> 7;
    b11 = (line_pixel_1024 & 0x100) >> 8;
    b12 = (line_pixel_1024 & 0x200) >> 9;
    
    line_cnt = (line_cnt_1024 << 13)  | ((vga_y & 0x0F) << 6);
    line_offset = (line_pixel_1024 & 0x00EFE03F) | (b10 << 10) | (b11 << 11) | (b12 << 12) | (b22 << 22);
    frame_base_c2 = ((frame_base & 0xFF800000) | ((frame_base & 0x00700000) >> 1 )) + (line_cnt | line_offset);
    //*( (char*)(frame_y_base_tmp) ) = (char)255;

    return (frame_base_c2);
}

int my_c2_addr_gen (int addr)
{
    int frame_base, vga_x, vga_y;
    frame_base =  (addr & 0xFFF00000);
    vga_y = (int)((addr & 0x000FFFFF) / 640);
    vga_x = (int)((addr & 0x000FFFFF) % 640);

    int line_cnt_1024, line_pixel_1024, b22, b10, b11, b12, line_cnt, line_offset, frame_base_c2;

    line_cnt_1024 = ((640*(vga_y>>4) + vga_x) >> 10);  // ((640*(vga_y/16) + vga_x) /1024);
    line_pixel_1024 = ((640*(vga_y>>4) + vga_x) % 1024);  // ((640*(vga_y/16) + vga_x) /1024);
    
    b22 = (line_pixel_1024 & 0x40) >> 6;
    b10 = (line_pixel_1024 & 0x80) >> 7;
    b11 = (line_pixel_1024 & 0x100) >> 8;
    b12 = (line_pixel_1024 & 0x200) >> 9;
    
    line_cnt = (line_cnt_1024 << 13)  | ((vga_y & 0x0F) << 6);
    line_offset = (line_pixel_1024 & 0x00EFE03F) | (b10 << 10) | (b11 << 11) | (b12 << 12) | (b22 << 22);
    frame_base_c2 = ((frame_base & 0xFF800000) | ((frame_base & 0x00700000) >> 1 )) + (line_cnt | line_offset);
    //*( (char*)(frame_y_base_tmp) ) = (char)255;

    return (frame_base_c2);
}



void my_draw_rect(int x, int y, int width, int height, int color, int fill)
{
    int frame_width = (ORC_CAM_SIZE & 0xffff);
    //int *frame_y_base;
    //frame_y_base = VIM_Y_BASE;
    int frame_y_base = VIM_Y_BASE;
    

    int frame_y_base_tmp;

    int x_start = (x>>2)<<2;
    int x_end   = ((x+width-1)>>2)<<2;
    int y_start = y;
    int y_end   = y+height-1;

    int i,j, i_640_sub;
    int b10, b11, b12, b22;
    int line_cnt, line_offset, line_cnt_16;
    int pixel_cnt, line_cnt_1024, line_pixel_1024;
    int a, b, c, d;

    i = 0;
    a = 0; b=0; c=0; d=0;
    i_640_sub = 0;
    line_cnt = 0;
    line_offset = 0;

    // 640 * a + b = 1024*c + d;
    // So,
    // c = (640 * a + b) / 1024;
    // d = (640 * a + b) % 1024;
/*
    //for (i=0; i< my_frame_num ; i=i+1)
    for (i=0; i< 16 ; i=i+1)
    {
	a = (int)(i / 16);
	i_640_sub = (int)(i % 16); // for [b12, b11, b10, b22]

	    for (j=0; j< 640 ; j=j+1)
	    {
		// convert 640 width line --> 1024 width line
		//pixel_cnt = i*640 + j;
		//line_cnt_1024 = (pixel_cnt >> 10);
		//line_pixel_1024 = pixel_cnt - (line_cnt_1024 << 10);

		b = j;
		c = (int)((a * 640 + b) / 1024);
		d = (int)((a * 640 + b) % 1024);

		line_cnt_1024 = c;
		line_pixel_1024 = d;

		b22 = ( i_640_sub & 0x8 ) >> 3; //(line_pixel_1024 & 0x40) >> 6;
		b10 = ( i_640_sub & 0x10 ) >> 4; //(line_pixel_1024 & 0x80) >> 7;
		b11 = ( i_640_sub & 0x20 ) >> 5; //(line_pixel_1024 & 0x100) >> 8;
		b12 = ( i_640_sub & 0x40 ) >> 6; //(line_pixel_1024 & 0x200) >> 9;

	        line_cnt = ((line_cnt_1024 & 0x3F0) << 9)  | ((line_cnt_1024 & 0x0F) << 6);
	        line_offset = (line_pixel_1024 & 0x00EFE03F) | (b10 << 10) | (b11 << 11) | (b12 << 12) | (b22 << 22);
		frame_y_base_tmp = (frame_y_base & 0xFF000000) | line_cnt | line_offset;
	        *( (char*)(frame_y_base_tmp) ) = (char)255;

	    }
    }

*/

    i = 0;
    line_cnt_1024 = 0;
    line_pixel_1024 = 0;
    line_cnt = 0;
    line_offset = 0;
    for (i=0; i< my_frame_num ; i=i+1)
    //for (i=0; i< 35 ; i=i+1)
    {
	    for (j=0; j< 640 ; j=j+1)
	    {

/*
		line_cnt_1024 = ((640*(i>>4) + j) >> 10);  // ((640*(i/16) + j) /1024);
		line_pixel_1024 = ((640*(i>>4) + j) % 1024);  // ((640*(i/16) + j) /1024);
	
		b22 = (line_pixel_1024 & 0x40) >> 6;
		b10 = (line_pixel_1024 & 0x80) >> 7;
		b11 = (line_pixel_1024 & 0x100) >> 8;
		b12 = (line_pixel_1024 & 0x200) >> 9;

	        line_cnt = (line_cnt_1024 << 13)  | ((i & 0x0F) << 6);
	        line_offset = (line_pixel_1024 & 0x00EFE03F) | (b10 << 10) | (b11 << 11) | (b12 << 12) | (b22 << 22);

		//frame_y_base_tmp = (frame_y_base & 0xFF000000) | line_cnt | line_offset;
		frame_y_base_tmp = ((frame_y_base & 0xFF800000) | ((frame_y_base & 0x00700000) >> 1 )) + (line_cnt | line_offset);

	        // *( (char*)(i*line_cnt + line_offset) ) = (char)255;
	        *( (char*)(frame_y_base_tmp) ) = (char)255;
*/
		
	        //*( (char*)(my_c2_addr_gen_by_index(frame_y_base, j, i) ) ) = (char)255;
	        
	        //*( (char*)(my_c2_addr_gen(frame_y_base+ j + i*640) ) ) = (char)255;
	        *( (char*)(my_c2_addr_gen((int)(frame_y_base + j + i*640)) ) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;

	
	    }
    }




/*
    i = 0;
    line_cnt = 0;
    line_offset = 0;
    for (i=0; i< my_frame_num ; i=i+1)
    {
	    for (j=0; j< 640 ; j=j+1)
	    {
		b22 = (j & 0x40) >> 6;
		b10 = (j & 0x80) >> 7;
		b11 = (j & 0x100) >> 8;
		b12 = (j & 0x200) >> 9;

	        line_cnt = ((i & 0x3F0) << 9)  | ((i & 0x0F) << 6);
		
	        //line_offset =  (frame_y_base & 0xFFEFE03F) | (b10 << 10) | (b11 << 11) | (b12 << 12) | (b22 << 20);
	        line_offset = (j & 0x00EFE03F) | (b10 << 10) | (b11 << 11) | (b12 << 12) | (b22 << 22);

		frame_y_base_tmp = (frame_y_base & 0xFF000000) | line_cnt | line_offset;

	        // *( (char*)(i*line_cnt + line_offset) ) = (char)255;
	        *( (char*)(frame_y_base_tmp) ) = (char)255;
	
	    }
    }



*/	


/*  DRAW TEST
    //i = y_start;
    i = 0;
    for (j=0; j< 64 ; j=j+1)
    {
        frame_y_base_tmp = frame_y_base | (1 << 22);
	//color = 255;
        *( (char*)(frame_y_base_tmp + i*frame_width + j) ) = (char)0;
        // *( (int*)(frame_y_base_tmp + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;
    }
    for (j=0; j< 64 ; j=j+1)
    {
        frame_y_base_tmp = frame_y_base | (1 << 23);
	//color = 255;
        *( (char*)(frame_y_base_tmp + i*frame_width + j) ) = (char)color;
        // *( (int*)(frame_y_base_tmp + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;
    }
    for (j=0; j< 64 ; j=j+1)
    {
        //frame_y_base_tmp = frame_y_base | (1 << 21);
        frame_y_base_tmp = frame_y_base;
	//color = 255;
        *( (char*)(frame_y_base_tmp + i*frame_width + j) ) = (char)128;
        // *( (int*)(frame_y_base_tmp + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;
    }
*/

/*
    for (j=0; j< 16 ; j=j+1)
    {
        frame_y_base = frame_y_base | (1 << 6);
	color = 128;
        // *( (char*)(frame_y_base + i*frame_width + j) ) = color;
        *( (int*)(frame_y_base + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;
    }
    for (j=0; j< 16 ; j=j+1)
    {
        frame_y_base = frame_y_base | (1 << 7);
	color = 0;
        // *( (char*)(frame_y_base + i*frame_width + j) ) = color;
        *( (int*)(frame_y_base + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;
    }
*/
/*
    // top & bottom line
    for (j=x_start; j<= x_end ; j=j+4)
    //for (j=0; j< 8 ; j=j+1)
    {
        // top
        i = y_start;
	//j = 16;
	//frame_y_base = frame_y_base | (0x1 << 4);
        *( (int*)(frame_y_base + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;
        // *( (char*)(frame_y_base + i*frame_width + j) ) = 255;

        // bottom
        i = y_end;
        *( (int*)(frame_y_base + i*frame_width + j) ) = ((color)<<24) + ((color)<<16) + ((color)<<8) + ((color)<<0) ;
    }


    // left & right line
    for (i=y_start; i<= y_end; i= i+1)
    {
        // left
        // the reason why adding 3 is the endian of ViDan is big.
        // (3, 2, 1, 0), (3, 2, 1, 0) ...
        j= x_start+3;
        *( (char*)(frame_y_base + i*frame_width + j ) ) = color;

        // right
        j= x_end;
        *( (char*)(frame_y_base + i*frame_width + j) ) = color;
    }
*/
}


