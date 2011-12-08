#ifndef _COMMANDPROCESS_H_
#define _COMMANDPROCESS_H_

#include "map.h"
#include "ucos_ii.h"

#define DUMMY	0x00
enum
{
	USB_COMMAND_FIRMWARE_VERSION_CHECK_FAIL = -9,
	USB_COMMAND_FIRMWARE_UPLOAD_FAIL = -8,
	USB_COMMAND_FIRMWARE_SET_LENGTH_FAIL = -7,
	USB_COMMAND_FIRMWARE_SDRAM_WRITE_FAIL = -6,
	USB_COMMAND_VIDEOAPISET_FAIL = -5,
	USB_COMMAND_STREAM_NOT_READY = -4,
	USB_COMMAND_I2C_FAIL = -3,
	USB_COMMAND_UNDEFINED_COMMAND = -2,
	USB_COMMAND_FAIL = -1,
	USB_COMMAND_SUCCESS = 0,
};

enum
{
	INTERNAL_REGISTER_READ		=	0x10,
	INTERNAL_REGISTER_WRITE		=	0x11,
	HIF_REGISTER_READ					=	0x20,
	HIF_REGISTER_WRITE				=	0x21,
	HIF_REGISTER_BIT_SET			=	0x22,
	HIF_REGISTER_BIT_RESET		=	0x23,
	I2C_MASTER_READ						= 0x30,
	I2C_MASTER_WRITE					= 0x31,
	STREAM_GET_JPEG_LENGTH		= 0x40,
	STREAM_GET_H264_LENGTH		= 0x41,
	STREAM_GET_PCMIN_LENGTH		= 0x42,
	COMMAND_VIDEO_START					= 0x50,
	COMMAND_VIDEO_STOP					= 0x51,
	COMMAND_AUDIO_START					= 0x52,
	COMMAND_AUDIO_STOP					= 0x53,
	COMMAND_FIRMWARE_SDRAM_WRITE		= 0x54,
	COMMAND_FIRMWARE_SET_LENGTH			= 0x55,
	COMMAND_FIRMWARE_UPLOAD				= 0x56,
	COMMAND_FIRMWARE_VERSION_CHECK		= 0x57,
	VIDEO_API_SET						= 0x60,
};

#define VIDEO_BUFFER_CNT			2
typedef struct
{
	volatile int len[VIDEO_BUFFER_CNT];
	volatile int address[VIDEO_BUFFER_CNT];
	volatile char full[VIDEO_BUFFER_CNT];
	volatile char set_idx;
	volatile char get_idx;
	volatile char count;
} VIDEO_STREAM_BUF;

#define PCM_BUFFER_CNT			10
typedef struct
{
	volatile int len[PCM_BUFFER_CNT];
	volatile int address[PCM_BUFFER_CNT];
	volatile char full[PCM_BUFFER_CNT];
	volatile char set_idx;
	volatile char get_idx;
	volatile char count;
} PCM_STREAM_BUF;

void commandProcess(char *commandBuf, int commandLen);

extern VIDEO_STREAM_BUF jpegDualStreamBuf;
extern VIDEO_STREAM_BUF h264DualStreamBuf;
extern PCM_STREAM_BUF pcminDualStreamBuf;

//jykim_usb_stream_test
#define JPEG_STREAM_BASE_TEST			0xf1000100


#define MAX_JPEG_STREAM_LEN	( 12 * 1024 ) //128Kbytes
#define JPEG_STREAM_ADDR		JPEG_STREAM_BASE_TEST //jykim_usb_stream_test

#define MAX_H264_STREAM_LEN	( 36 * 1024 ) //128Kbytes
//#define MAX_H264_STREAM_LEN	( 128 * 1024 ) //128Kbytes
#define H264_STREAM_ADDR		( JPEG_STREAM_ADDR + (MAX_JPEG_STREAM_LEN * VIDEO_BUFFER_CNT) )

#define MAX_PCM_STREAM_LEN	( 3 * 1024 ) //128Kbytes
#define PCMIN_STREAM_ADDR		( H264_STREAM_ADDR + (MAX_H264_STREAM_LEN * VIDEO_BUFFER_CNT) )


extern OS_EVENT *pH264StreamSem;
extern OS_EVENT *pJPEGStreamSem;
extern OS_EVENT *pPCMINStreamSem;

extern volatile int command_video_start;
extern volatile int command_video_stop;
#endif

