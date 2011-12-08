#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <libusb.h>
#include <pthread.h>
#include "redwood_return_code.h"
#include "redwood_usb_operation.h"
#include "redwood_device_config.h"

#define VIDEO_BUFFER_SZE	( 128 * 1024 )
#define AUDIO_BUFFER_SZE	( 16 * 1024 )

//Firmware Upgrade
#define ROM0_BASE_ADDR		0x000000
#define ROM1_BASE_ADDR		0x029000
#define ROM2_BASE_ADDR		0x031000
#define ROM3_BASE_ADDR		0x080000
#define ROM4_BASE_ADDR		0x090000
#define MAX_ROM_PACKET_SIZE 32 //If this changed, fw must be changed first
#define FLASH_PAGE_UNIT 	 256 
/**********************************************************************/
/* 	 																  */
/*                         Global Variables                           */
/* 																	  */
/**********************************************************************/
libusb_device_handle *g_usb_handle = NULL;

pthread_t usbcontrol_video_thread;
char is_usbcontrol_video_thread_started = 0;

pthread_t usbcontrol_audio_thread;
char is_usbcontrol_audio_thread_started = 0;

pthread_t usbcontrol_firmware_upgrade_thread;
char is_usbcontrol_firmware_upgrade_thread_started = 0;

pthread_mutex_t mutex_usb_operation;

char romFilePath[256] = {0};

int prev_video_prop[VIDEO_PROP_CNT] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
int curr_video_prop[VIDEO_PROP_CNT] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
/**********************************************************************/
/* 																	  */
/*                        SKYPE API									  */
/* 																	  */
/**********************************************************************/
char is_keyframe_request = 0;
char is_bitrate_set = 0;
char is_framerate_set = 0;
char is_input_db_set = 0;
char is_agc_gain_set = 0;
char is_audio_mute_set = 0;
char is_video_zoom_set = 0;
char is_video_flip_set = 0;
char is_video_property_set = 0;
int  modified_bitrate = 0;
int  modified_framerate = 0;
VIDEO_PROP_TYPE modified_vpt = 0;
VIDEO_PROP_LEVEL modified_vpl = 0;
unsigned char  modified_input_db = 0;
unsigned char modified_agc_gain_r26 = 0; 
unsigned char modified_agc_gain_r27 = 0;
unsigned char modified_agc_gain_r28 = 0;
unsigned char modified_agc_gain_r29 = 0;
unsigned char modified_agc_gain_r30 = 0;
unsigned char modified_agc_gain_r31 = 0;

unsigned char  modified_isMuteEnable = 0;
unsigned char  modified_zoomLevel = 0;
unsigned char  modified_isFlipEnable = 0;

unsigned char initial_input_db = 0;

/**********************************************************************/
/* 																	  */
/*                        Static Functions                            */
/* 																	  */
/**********************************************************************/
static int is_my_device(libusb_device *dev, unsigned short vid, unsigned short pid);
static void *usbcontrol_video_thread_func(void *ptr);
static void *usbcontrol_audio_thread_func(void *ptr);
static void *usbcontrol_firmware_upgrade_thread_func(void *ptr);
static int GetStream(GET_STREAM_EP_TYPE type, int frameLen, char *streamBuffer);
static int GetAudioStreamLength(int *pcmLength, int *lostLength);
static int GetVideoStreamLength(int *h264Length, int *jpegLength);
static int redwood_reg_keyframe_request(void);
static int redwood_reg_bitrate_set(int bitrate);
static int redwood_reg_framerate_set(int framerate);
static int redwood_reg_input_db_set(unsigned char input_db);
static int redwood_reg_agc_gain_set(unsigned char r26,
							  		unsigned char r27, 
							  		unsigned char r28,
							  		unsigned char r29,
							  		unsigned char r30,
							  		unsigned char r31);
static int redwood_reg_audio_mute_set(unsigned char isMuteEnable);
static int redwood_reg_video_zoom_set(unsigned char zoomLevel);
static int redwood_reg_video_flip_set(unsigned char isFlipEnable);
static int redwood_reg_video_property_set(VIDEO_PROP_TYPE vpt, VIDEO_PROP_LEVEL vpl);
static int usb_send_command(int cmdCount, unsigned char *cmdData, int resultCnt, unsigned char *resultData);

static int getHeaderIdx(int dataLen, char *dataBuf);

/**********************************************************************/
/* 																	  */
/*                        Extern Functions                            */
/* 																	  */
/**********************************************************************/
extern void usleep(int usec);

/**********************************************************************/
/*																	  */
/*                        Source Start                                */
/* 																	  */
/**********************************************************************/
int usbcontrol_video_thread_create(void *ptr)
{
	int ret;

	pthread_attr_t		attr;
	struct sched_param	sched;

	pthread_attr_init(&attr);
	pthread_attr_setstacksize(&attr, USBCONTROL_VIDEO_THREAD_STACKSIZE);
	//pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //After pthread_join
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);

	pthread_attr_setschedpolicy(&attr, SCHED_RR);
	pthread_attr_getschedparam(&attr, &sched);
	sched.sched_priority = USBCONTROL_THREAD_PRIORITY;
	pthread_attr_setschedparam(&attr, &sched);

	is_usbcontrol_video_thread_started = 1;

	ret  = pthread_create( &usbcontrol_video_thread,
							&attr,
							usbcontrol_video_thread_func,
						 	ptr);

	return ret;
}

int usbcontrol_video_thread_destory(void)
{
	is_usbcontrol_video_thread_started = 0; 
	return SUCCESS; 
}

int usbcontrol_audio_thread_create(void *ptr)
{
	int ret;

	pthread_attr_t		attr;
	struct sched_param	sched;

	pthread_attr_init(&attr);
	pthread_attr_setstacksize(&attr, USBCONTROL_AUDIO_THREAD_STACKSIZE);
	//pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);

	pthread_attr_setschedpolicy(&attr, SCHED_RR);
	pthread_attr_getschedparam(&attr, &sched);
	sched.sched_priority = USBCONTROL_THREAD_PRIORITY;
	pthread_attr_setschedparam(&attr, &sched);

	is_usbcontrol_audio_thread_started = 1;

	ret  = pthread_create( &usbcontrol_audio_thread,
							&attr,
							usbcontrol_audio_thread_func,
						 	ptr);

	return ret;
}

int usbcontrol_audio_thread_destory(void)
{
	is_usbcontrol_audio_thread_started = 0;
	return SUCCESS;
}

/**********************************************************************/
/*                 Video Thread Main								  */
/**********************************************************************/
static void *usbcontrol_video_thread_func(void *ptr)
{
	int ret;
	char *streamBuffer;
	char *h264StreamBuffer;
	int h264StreamLen = 0, jpegStreamLen = 0;
	int h264cnt = 0;
	int h264OutStreamLen = 0;
	int header_idx = 0;
	int i;

	struct timeval tim;
	double t1 = 0;
	double t2 = 0;
	double t3 = 0;
	double t4 = 0;
	double t5 = 0;
	double t6 = 0;
	double t7 = 0;
	double t8 = 0;

	//Video Prop API
	for ( i = 0; i < VIDEO_PROP_CNT; i++ )
		prev_video_prop[i] = -1;

	printf("===>VIDAN4110 INFO : usbcontrol_video_thread_func started\n");
	//usleep(10000);

	streamBuffer = (char*)malloc(VIDEO_BUFFER_SZE*sizeof(char));
	if ( streamBuffer == NULL )
	{
		printf("===>VIDAN4110 ERROR : %s - cannot allocate memory\n", __FUNCTION__); 
		return NULL;
	}

	h264StreamBuffer = (char*)malloc(VIDEO_BUFFER_SZE*sizeof(char));
	if ( h264StreamBuffer == NULL )
	{
		printf("===>VIDAN4110 ERROR : %s - cannot allocate memory\n", __FUNCTION__); 
		return NULL;
	}


	while (is_usbcontrol_video_thread_started)
	{
		pthread_mutex_lock(&mutex_usb_operation);

		if (is_usbcontrol_video_thread_started == 0)
		{
			pthread_mutex_unlock(&mutex_usb_operation);
			break;
		}

		if ( is_keyframe_request )
		{
			redwood_reg_keyframe_request();
			is_keyframe_request = 0;
		}
		if ( is_bitrate_set )
		{
			redwood_reg_bitrate_set(modified_bitrate);
			is_bitrate_set = 0;
		}
		if ( is_framerate_set )
		{
			redwood_reg_framerate_set(modified_framerate);
			is_framerate_set = 0;
		}
		if ( is_video_zoom_set )
		{
			redwood_reg_video_zoom_set(modified_zoomLevel);
			is_video_zoom_set = 0;
		}
		if ( is_video_flip_set )
		{
			redwood_reg_video_flip_set(modified_isFlipEnable);
			is_video_flip_set = 0;
		}

		//Video API Pro
		if ( h264StreamLen > 0 )
		{
			for ( i = 0; i < VIDEO_PROP_CNT; i++ )
			{
				if ( prev_video_prop[i] != curr_video_prop[i] )
				{
					prev_video_prop[i] = curr_video_prop[i];
					modified_vpt = i;
					modified_vpl = curr_video_prop[i];
					is_video_property_set = 1;
					break;
				}

			}
		}

		if ( is_video_property_set )
		{
			redwood_reg_video_property_set(modified_vpt, modified_vpl);
			is_video_property_set = 0;
		}

		//h264 check
		h264StreamLen = 0; 
		jpegStreamLen = 0;
		gettimeofday(&tim, NULL);
		t2 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
		if ( t2 - t1 > 100 )
			printf("h264&jpeg elapsed time : %.3lf ms\n", t2 - t1);
		t1 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
		ret = GetVideoStreamLength(&h264StreamLen, &jpegStreamLen);
		gettimeofday(&tim, NULL);
		t3 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
		if ( t3 - t1 > 100 )
			printf("h264&jpeg Length elapsed time : %.3lf ms\n", t3 - t1);
		//printf("h264&jpeg frameLen:%d,%d\n", h264StreamLen,jpegStreamLen);
		if ( h264StreamLen > 0 && h264StreamLen <= VIDEO_BUFFER_SZE )
		{
			ret = GetStream(H264_STREAM_EP_TYPE, h264StreamLen, streamBuffer);
			gettimeofday(&tim, NULL);
			t4 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
			if ( t4 - t3 > 100 )
				printf("h264 Stream elapsed time : %.3lf ms\n", t4 - t3);
			if ( ret == h264StreamLen )
			{
				if ( h264cnt == 0 )
				{
					memcpy(h264StreamBuffer, streamBuffer, h264StreamLen);
					h264OutStreamLen = h264StreamLen;
				}
				else
				{
					header_idx = getHeaderIdx(h264StreamLen, streamBuffer);
					if ( header_idx != 0 )
					{
						memcpy(h264StreamBuffer + h264OutStreamLen, streamBuffer, header_idx);
						h264OutStreamLen += header_idx;
					}

					if ( h264callbackFunc != NULL )
						h264callbackFunc(h264OutStreamLen, h264StreamBuffer);

					gettimeofday(&tim, NULL);
					t5 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
					if ( t5 - t4 > 100 )
						printf("h264 Save elapsed time : %.3lf ms, Length : %d\n", t5 - t4, h264OutStreamLen);

					memcpy(h264StreamBuffer, streamBuffer + header_idx, h264StreamLen - header_idx);
					h264OutStreamLen = h264StreamLen - header_idx;
				}
				h264cnt++;
			}
		}

		gettimeofday(&tim, NULL);
		t6 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
		if ( jpegStreamLen > 0 && jpegStreamLen <= VIDEO_BUFFER_SZE )
		{
			ret = GetStream(JPEG_STREAM_EP_TYPE, jpegStreamLen, streamBuffer);
			gettimeofday(&tim, NULL);
			t7 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
			if ( t7 - t6 > 100 )
					printf("Jpeg Stream elapsed time : %.3lf ms\n", t7 - t6);
			if ( ret == jpegStreamLen )
			{
				if ( jpegcallbackFunc != NULL )
					jpegcallbackFunc(jpegStreamLen, streamBuffer);
			}
			gettimeofday(&tim, NULL);
			t8 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
			if ( t8 - t7 > 100 )
				printf("Jpeg Save elapsed time : %.3lf ms, Length : %d\n", t8 - t7, jpegStreamLen);
		}	
		//Termination condition check

		pthread_mutex_unlock(&mutex_usb_operation);
		usleep(15000);

	}
	//Debug
	//fclose(outfile);
	if ( streamBuffer )
		free(streamBuffer);
	if ( h264StreamBuffer )
		free(h264StreamBuffer);

	//is_usbcontrol_video_thread_started = 0;

	printf("===>VIDAN4100 INFO : usbcontrol_video_thread_func terminated\n");

	return NULL;
}

/**********************************************************************/
/*                 Audio Thread Main								  */
/**********************************************************************/
static void *usbcontrol_audio_thread_func(void *ptr)
{
	int ret;
	char *streamBuffer;
	int pcmFrameLen, lostFrameLen;

	struct timeval tim;
	double t1 = 0;
	double t2 = 0;
	double t3 = 0;
	double t4 = 0;
	double t5 = 0;
	double t6 = 0;
	double t7 = 0;

	printf("===>VIDAN4110 INFO : usbcontrol_audio_thread_func started\n");
	//usleep(10000);
	
	streamBuffer = (char*)malloc(AUDIO_BUFFER_SZE*sizeof(char));
	if ( streamBuffer == NULL )
	{
		printf("===>VIDAN4110 ERROR : %s - cannot allocate memory\n", __FUNCTION__); 
		return NULL;
	}

	while (is_usbcontrol_audio_thread_started)
	{
		pthread_mutex_lock(&mutex_usb_operation);
		if (is_usbcontrol_audio_thread_started == 0)
		{
			pthread_mutex_unlock(&mutex_usb_operation);
			break;
		}

		if ( is_input_db_set )
		{
			redwood_reg_input_db_set(modified_input_db);
			is_input_db_set = 0;
		}

		if ( is_agc_gain_set )
		{
			redwood_reg_agc_gain_set(modified_agc_gain_r26,
									 modified_agc_gain_r27,
									 modified_agc_gain_r28,
									 modified_agc_gain_r29,
									 modified_agc_gain_r30,
									 modified_agc_gain_r31);
			is_agc_gain_set = 0;
		}

		if ( is_audio_mute_set )
		{
			redwood_reg_audio_mute_set(modified_isMuteEnable);
			is_audio_mute_set = 0;
		}

		pcmFrameLen = 0;
		lostFrameLen = 0;
		//pcm check
		gettimeofday(&tim, NULL);
		t2 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
		if ( t2 - t1 > 100 )
			printf("pcm elapsed time : %.3lf ms\n", t2 - t1);
		t1 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
		ret = GetAudioStreamLength(&pcmFrameLen, &lostFrameLen);
		//printf("pcm frameLen:%d\n", pcmFrameLen);
		gettimeofday(&tim, NULL);
		t3 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
		if ( t3 - t1 > 100 )
			printf("pcm Length elapsed time : %.3lf ms\n", t3 - t1);

		if ( pcmFrameLen > 0 && pcmFrameLen <= AUDIO_BUFFER_SZE )
		{
			ret = GetStream(PCM_STREAM_EP_TYPE, pcmFrameLen, streamBuffer);
			gettimeofday(&tim, NULL);
			t4 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
			if ( t4 - t3 > 100 )
				printf("pcm Stream elapsed time : %.3lf ms\n", t4 - t3);
			if ( ret == pcmFrameLen )
			{
				if ( pcmcallbackFunc != NULL )
					pcmcallbackFunc(pcmFrameLen, streamBuffer);
			}
			gettimeofday(&tim, NULL);
			t5 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
			if ( t5 - t4 > 100 )
			{
				printf("pcm Save elapsed time : %.3lf ms, frameLen : %d\n", t5 - t4, pcmFrameLen);
			}
		}
		gettimeofday(&tim, NULL);
		t6 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
		if ( t6 - t3 > 100 )
			printf("pcm Stream & Save elapsed time : %.3lf ms\n", t6 - t3);

		if ( lostFrameLen > 0 && lostFrameLen <= AUDIO_BUFFER_SZE )
		{
			printf("lost frameLen:%d\n", lostFrameLen);
			memset(streamBuffer, 0, lostFrameLen);
			if ( pcmcallbackFunc != NULL )
				pcmcallbackFunc(lostFrameLen, streamBuffer);
		}

		pthread_mutex_unlock(&mutex_usb_operation);
		usleep(5000);
		gettimeofday(&tim, NULL);
		t7 = (tim.tv_sec * 1000) + (tim.tv_usec/1000.0);
		if ( t7 - t6 > 100 )
			printf("pcm while end elapsed time : %.3lf ms\n", t7 - t6);
	}
	//Debug
	//fclose(outfile);
	if ( streamBuffer )
		free(streamBuffer);

	printf("===>VIDAN4100 INFO : usbcontrol_audio_thread_func terminated\n");

	return NULL;
}

/**********************************************************************/
/*                 Video Start Set									  */
/**********************************************************************/
int redwood_video_start_set(video_param_t *vParm)
{
	int ret;
	unsigned char commandBuf[64];
	unsigned char resultBuf[64];
	unsigned char jpegQ = 0;

	//Resolution Command
	commandBuf[0] = 0x21;
	commandBuf[1] = 6;
	commandBuf[2] = 0;
	commandBuf[3] = 1;

	if ( vParm->isAvataCaptureMode )
	{
		commandBuf[4] = 0x00;
	}
	else
	{
		switch(vParm->res_width)
		{
			case 640:
				commandBuf[4] = 0x00;
				break;
			case 320:
				commandBuf[4] = 0x01;
				break;
			case 160:
				commandBuf[4] = 0x02;
				break;
			case 1280:
				commandBuf[4] = 0x03;
				break;
			default:
				return WRONG_RESOLUTION;
		}
	}
	ret = usb_send_command(5, commandBuf, 2, resultBuf);

	//Jpeg Quality Command
	if ( vParm->jpeg_quality > MAX_JPEG_QUALITY )
		jpegQ = MAX_JPEG_QUALITY;
	else if ( vParm->jpeg_quality < MIN_JPEG_QUALITY )
		jpegQ = MIN_JPEG_QUALITY;
	else
		jpegQ = vParm->jpeg_quality;

	commandBuf[0] = 0x21;
	commandBuf[1] = 50;
	commandBuf[2] = 0;
	commandBuf[3] = 1;
	commandBuf[4] = jpegQ;
	ret = usb_send_command(5, commandBuf, 2, resultBuf);

	//TODO : Temporary 
	//Remove Blink
	commandBuf[0] = 0x31;
	commandBuf[1] = 0x30;
	commandBuf[2] = 0;
	commandBuf[3] = 3;
	commandBuf[4] = 0x30;
	commandBuf[5] = 0x13;
	commandBuf[6] = 0xf3;

	ret = usb_send_command(7, commandBuf, 3, resultBuf);

	//Flip Enable/Disable
	redwood_reg_video_flip_set(vParm->isFlipEnable);

	//Start Command
	commandBuf[0] = VIDEO_START_TYPE;
	ret = usb_send_command(1, commandBuf, 2, resultBuf);

	return ret;
}

/**********************************************************************/
/*                 Video Stop Set									  */
/**********************************************************************/
int redwood_video_stop_set(void)
{
	int ret;
	unsigned char command;
	unsigned char resultBuf[2];

	command = VIDEO_STOP_TYPE;
	ret = usb_send_command(1, &command, 2, resultBuf);

	return ret;
}

/**********************************************************************/
/*                 Audio Start Set									  */
/**********************************************************************/
int redwood_audio_start_set(audio_param_t *aParm)
{
	int ret;
	unsigned char commandBuf[5];
	unsigned char resultBuf[2];

	//Sampling Freq Command
	commandBuf[0] = 0x21;
	commandBuf[1] = 7;
	commandBuf[2] = 0;
	commandBuf[3] = 1;
	commandBuf[4] = aParm->audio_freq_type;

	ret = usb_send_command(5, commandBuf, 2, resultBuf);

	commandBuf[0] = AUDIO_START_TYPE;
	ret = usb_send_command(1, commandBuf, 2, resultBuf);

	return ret;
}

/**********************************************************************/
/*                 Audio Stop Set									  */
/**********************************************************************/
int redwood_audio_stop_set(void)
{
	int ret;
	unsigned char command;
	unsigned char resultBuf[2];

	command = AUDIO_STOP_TYPE;
	ret = usb_send_command(1, &command, 2, resultBuf);

	return ret;
}



/**********************************************************************/
/*                 Key Frame Request								  */
/**********************************************************************/
void redwood_usb_keyframe_request(void)
{
	is_keyframe_request = 1;
}

static int redwood_reg_keyframe_request(void)
{
	int ret;
	unsigned char commandBuf[4];
	unsigned char resultBuf[2];

	commandBuf[0] = 0x22;
	commandBuf[1] = 62;
	commandBuf[2] = 0xff;
	commandBuf[3] = 0x01;
	ret = usb_send_command(4, commandBuf, 2, resultBuf);

	return ret;

}
/**********************************************************************/
/*                 bit rate control									  */
/**********************************************************************/
void redwood_usb_bitrate_set(int bps)
{
	modified_bitrate = bps; 
	is_bitrate_set = 1;
}
static int redwood_reg_bitrate_set(int bitrate)
{
	int ret;
	unsigned char commandBuf[6];
	unsigned char resultBuf[2];
	int kbps = bitrate / 1024;

	commandBuf[0] = 0x21;
	commandBuf[1] = 66;
	commandBuf[2] = 0;
	commandBuf[3] = 2;
	commandBuf[4] = (unsigned char)(kbps & 0x000000ff);
	commandBuf[5] = (unsigned char)((kbps >> 8 ) & 0x000000ff);
	ret = usb_send_command(6, commandBuf, 2, resultBuf);

	return ret;
}
/**********************************************************************/
/*                 frame rate control								  */
/**********************************************************************/
void redwood_usb_framerate_set(int framerate)
{
	modified_framerate = framerate; 
	is_framerate_set = 1;
}

static int redwood_reg_framerate_set(int framerate)
{
	int ret;
	unsigned char commandBuf[5];
	unsigned char resultBuf[2];

	//Framerate range must be from 1 to 30.
	if ( framerate < 1 )
		framerate = 1;
	//else if ( framerate > 30 )
	//	framerate = 30;

	commandBuf[0] = 0x21;
	commandBuf[1] = 68;
	commandBuf[2] = 0;
	commandBuf[3] = 1;
	commandBuf[4] = framerate;
	ret = usb_send_command(5, commandBuf, 2, resultBuf);

	return ret;
}

/**********************************************************************/
/*                 Video Flip Control								  */
/**********************************************************************/
void redwood_usb_video_flip_set(unsigned char isFlipEnable)
{
	modified_isFlipEnable = isFlipEnable; 
	is_video_flip_set = 1;
}
static int redwood_reg_video_flip_set(unsigned char isFlipEnable)
{
	int ret;
	unsigned char commandBuf[7];
	unsigned char resultBuf[3];

	commandBuf[0] = 0x31;
	commandBuf[1] = 0x30;
	commandBuf[2] = 0;
	commandBuf[3] = 3;
	commandBuf[4] = 0x30;
	commandBuf[5] = 0x7c;
	if ( isFlipEnable )
		commandBuf[6] = 0x11;
	else
		commandBuf[6] = 0x10;

	ret = usb_send_command(7, commandBuf, 3, resultBuf);


	return ret;
}

/**********************************************************************/
/*                 Video Zoom Control								  */
/**********************************************************************/
void redwood_usb_video_zoom_set(unsigned char zoomLevel)
{
	modified_zoomLevel = zoomLevel; 
	is_video_zoom_set = 1;
}
static int redwood_reg_video_zoom_set(unsigned char zoomLevel)
{
	int ret;
	unsigned char commandBuf[5];
	unsigned char resultBuf[2];

	commandBuf[0] = 0x21;
	commandBuf[1] = 64;
	commandBuf[2] = 0;
	commandBuf[3] = 1;
	commandBuf[4] = zoomLevel;
	ret = usb_send_command(5, commandBuf, 2, resultBuf);

	return ret;
}
/**********************************************************************/
/*                 Video Setting Control							  */
/**********************************************************************/
void redwood_usb_video_property_set(VIDEO_PROP_TYPE vpt, VIDEO_PROP_LEVEL vpl)
{
	curr_video_prop[vpt] = vpl;
}

static int redwood_reg_video_property_set(VIDEO_PROP_TYPE vpt, VIDEO_PROP_LEVEL vpl)
{
	int ret;
	unsigned char commandBuf[5];
	unsigned char resultBuf[2];

	commandBuf[0] = 0x60;
	commandBuf[1] = 0x00;
	commandBuf[2] = (unsigned char)vpt;
	commandBuf[3] = (unsigned char)vpl;
	ret = usb_send_command(4, commandBuf, 3, resultBuf);

	return ret;
}

/**********************************************************************/
/*                 Audio Input DB Control							  */
/**********************************************************************/
void redwood_usb_input_db_set(unsigned char input_db)
{
	modified_input_db = input_db; 
	is_input_db_set = 1;
}
static int redwood_reg_input_db_set(unsigned char input_db)
{
	int ret;
	unsigned char commandBuf[5];
	unsigned char resultBuf[2];

	commandBuf[0] = 0x21;
	commandBuf[1] = 63;
	commandBuf[2] = 0;
	commandBuf[3] = 1;
	commandBuf[4] = input_db;
	ret = usb_send_command(5, commandBuf, 2, resultBuf);

	initial_input_db = input_db;

	return ret;
}

/**********************************************************************/
/*                 Audio AGC Gain Control							  */
/**********************************************************************/
void redwood_usb_agc_gain_set(unsigned char r26,
							  unsigned char r27, 
							  unsigned char r28,
							  unsigned char r29,
							  unsigned char r30,
							  unsigned char r31)
{
	modified_agc_gain_r26 = r26; 
	modified_agc_gain_r27 = r27; 
	modified_agc_gain_r28 = r28; 
	modified_agc_gain_r29 = r29; 
	modified_agc_gain_r30 = r30; 
	modified_agc_gain_r31 = r31; 
	is_agc_gain_set = 1;
}

static int redwood_reg_agc_gain_set(unsigned char r26,
							  		unsigned char r27, 
							  		unsigned char r28,
							  		unsigned char r29,
							  		unsigned char r30,
							  		unsigned char r31)
{
	int ret;
	unsigned char commandBuf[6];
	unsigned char resultBuf[3];

	commandBuf[0] = 0x31;
	commandBuf[1] = 0x18;
	commandBuf[2] = 0;
	commandBuf[3] = 2;
	commandBuf[4] = 26;
	commandBuf[5] = r26;
	ret = usb_send_command(6, commandBuf, 3, resultBuf);

	commandBuf[0] = 0x31;
	commandBuf[1] = 0x18;
	commandBuf[2] = 0;
	commandBuf[3] = 2;
	commandBuf[4] = 27;
	commandBuf[5] = r27;
	ret = usb_send_command(6, commandBuf, 3, resultBuf);

	commandBuf[0] = 0x31;
	commandBuf[1] = 0x18;
	commandBuf[2] = 0;
	commandBuf[3] = 2;
	commandBuf[4] = 28;
	commandBuf[5] = r28;
	ret = usb_send_command(6, commandBuf, 3, resultBuf);

	commandBuf[0] = 0x31;
	commandBuf[1] = 0x18;
	commandBuf[2] = 0;
	commandBuf[3] = 2;
	commandBuf[4] = 29;
	commandBuf[5] = r29;
	ret = usb_send_command(6, commandBuf, 3, resultBuf);

	commandBuf[0] = 0x31;
	commandBuf[1] = 0x18;
	commandBuf[2] = 0;
	commandBuf[3] = 2;
	commandBuf[4] = 30;
	commandBuf[5] = r30;
	ret = usb_send_command(6, commandBuf, 3, resultBuf);

	commandBuf[0] = 0x31;
	commandBuf[1] = 0x18;
	commandBuf[2] = 0;
	commandBuf[3] = 2;
	commandBuf[4] = 31;
	commandBuf[5] = r31;
	ret = usb_send_command(6, commandBuf, 3, resultBuf);

	return ret;
}

/**********************************************************************/
/*                 Audio Mute Control								  */
/**********************************************************************/
void redwood_usb_audio_mute_set(unsigned char isMuteEnable)
{
	modified_isMuteEnable = isMuteEnable; 
	is_audio_mute_set = 1;
}
static int redwood_reg_audio_mute_set(unsigned char isMuteEnable)
{
	int ret;
	unsigned char commandBuf[7];
	unsigned char resultBuf[3];

	commandBuf[0] = 0x31;
	commandBuf[1] = 0x18;
	commandBuf[2] = 0;
	commandBuf[3] = 3;
	commandBuf[4] = 15;

	if ( isMuteEnable )
	{
		commandBuf[5] = ((initial_input_db << 1) | 0x80);
		commandBuf[6] = ((initial_input_db << 1) | 0x80);
	}
	else
	{
		commandBuf[5] = ((initial_input_db << 1) & ~0x80);
		commandBuf[6] = ((initial_input_db << 1) & ~0x80);
	}

	ret = usb_send_command(7, commandBuf, 3, resultBuf);

	return ret;
}

/**********************************************************************/
/*                 Avata Start Set									  */
/**********************************************************************/
int redwood_video_avata_start_set(video_param_t *vParm)
{
	int ret;
	unsigned char commandBuf[64];
	unsigned char resultBuf[64];

	commandBuf[0] = 0x21;
	commandBuf[1] = 65;
	commandBuf[2] = 0;
	commandBuf[3] = 1;
	commandBuf[4] = 0x01;
	ret = usb_send_command(5, commandBuf, 2, resultBuf);

	//Start Command
	commandBuf[0] = VIDEO_START_TYPE;
	ret = usb_send_command(1, commandBuf, 2, resultBuf);

	return ret;
}

/**********************************************************************/
/*                 usb send command									  */
/**********************************************************************/
static int usb_send_command(int cmdCount, unsigned char *cmdData, int resultCnt, unsigned char *resultData)
{

	int ret;
	int transferred_len;

	//Send Command
   	transferred_len = 0;
	//pthread_mutex_lock(&mutex_usb_operation);
	ret = libusb_bulk_transfer(g_usb_handle,
								0x02,
								cmdData,
								cmdCount,
								&transferred_len,
								10
								);
	//pthread_mutex_unlock(&mutex_usb_operation);

	//Usb return Check
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 Send CMD ERROR : libusb result - %d\n", ret);
		ret = LIBUSB_FAIL;
		return ret;
	}

	//No response for keyframe request & Bitrate control & Reset
	if ( cmdData[0] == 0x21 || cmdData[0] == 0x22 )
	{
		if ( cmdData[1] == 62 || cmdData[1] == 66 || cmdData[1] == 63 || cmdData[1] == 23 ) 
		{
			return ret;
		}
	}

	//No response for firmware upload
	if ( cmdData[0] == 0x56 )
		return ret;


	//Receive Command
	memset(resultData, 0, resultCnt);
	transferred_len = 0;
	//pthread_mutex_lock(&mutex_usb_operation);
	ret = libusb_bulk_transfer(g_usb_handle,
								0x81,
								resultData,
								resultCnt,
								&transferred_len,
								30
								);
	//pthread_mutex_unlock(&mutex_usb_operation);

	//Usb Return Check
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 Receive RESP ERROR : libusb result - %d\n", ret);
		ret =  LIBUSB_FAIL;
	}
	else
	{
		//FW Return Value
		if ( resultData[0] != 0x00 )
		{
			ret = CMD_RESPONSE_RET_FAIL;
			printf("===>VIDAN4110 Receive RESP ERROR(%d) : 0x%02x\n", ret, resultData[0]);
		}
		//Wrong Command Check
		else if ( resultData[1] != cmdData[0] )
		{
			ret = CMD_WRONG_CMD_FAIL;
			printf("===>VIDAN4110 Receive RESP ERROR(%d) : 0x%02x\n", ret, resultData[1]);
		}
		else
		{
			ret = SUCCESS;
		}
	}

	return ret;
}

/**********************************************************************/
/*                 Get Stream Length		                          */
/**********************************************************************/
static int GetAudioStreamLength(int *pcmFrameLen, int *lostFrameLen)
{
	int ret;
	int transferred_len;

	unsigned char command;
	unsigned char resultBuf[12] = {0};

	command = 0x42;

   	transferred_len = 0;

	//Request Stream Length
	//pthread_mutex_lock(&mutex_usb_operation);
	ret = libusb_bulk_transfer(g_usb_handle,
								0x02,
								&command,
								1,
								&transferred_len,
								10
								);
	//pthread_mutex_unlock(&mutex_usb_operation);

	//Usb Return Check
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 GET LENGTH ERROR(0x42) : libusb result - %d\n", ret);
		ret = LIBUSB_FAIL;
		return ret;
	}

	//Getting Stream Length
	memset(resultBuf, 0, 12);
	transferred_len = 0;
	//pthread_mutex_lock(&mutex_usb_operation);
	ret = libusb_bulk_transfer(g_usb_handle,
								0x81,
								resultBuf,
								12,
								&transferred_len,
								30
								);
	//pthread_mutex_unlock(&mutex_usb_operation);

	//Usb Return Check
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 GET LENGTH RESP(0x42) : libusb result - %d\n", ret);
		ret =  LIBUSB_FAIL;
		memset(resultBuf, 0, 12);
	}
	else
	{
		//Receive Check
		if ( transferred_len != 12 )
		{
			ret = GET_WRONG_RESP_LEN;
			printf("===>VIDAN4110 GET LENGTH RESP(%d) : transferred_len - %d\n", ret, transferred_len);
			memset(resultBuf, 0, 12);
		}
		//FW Return Code Check
		else if ( resultBuf[0] != 0x00 )
		{
			if ( resultBuf[0] != 0xfc )
			{
				ret = GET_WRONG_RESP_RESULT;
				printf("===>VIDAN4110 GET LENGTH RESP(%d) : result - 0x%02x\n", ret, resultBuf[0]);
				memset(resultBuf, 0, 12);
			}
		}
		//Wrong Command Check
		else if ( resultBuf[1] != command )
		{
			ret = CMD_WRONG_CMD_FAIL;
			printf("===>VIDAN4110 GET LENGTH RESP(%d) : result - 0x%02x\n", ret, resultBuf[1]);
			memset(resultBuf, 0, 12);
		}

	}

	//Frame Length Setting
	*pcmFrameLen = (((int)resultBuf[7] << 24 ) & 0xff000000 )
				| (((int)resultBuf[6] << 16 ) & 0x00ff0000)
				| (((int)resultBuf[5] << 8  ) & 0x0000ff00)
				| (((int)resultBuf[4] << 0  ) & 0x000000ff);

	*lostFrameLen = (((int)resultBuf[11] << 24 ) & 0xff000000 )
				| (((int)resultBuf[10] << 16 ) & 0x00ff0000)
				| (((int)resultBuf[9] << 8  ) & 0x0000ff00)
				| (((int)resultBuf[8] << 0  ) & 0x000000ff);

	return ret;
}

static int GetVideoStreamLength(int *h264Length, int *jpegLength)
{
	int ret;
	int transferred_len;
	//int frameLen = 0;

	unsigned char command;
	unsigned char resultBuf[16] = {0};

	command = 0x41;

   	transferred_len = 0;

	//Request Stream Length
	//pthread_mutex_lock(&mutex_usb_operation);
	ret = libusb_bulk_transfer(g_usb_handle,
								0x02,
								&command,
								1,
								&transferred_len,
								10
								);
	//pthread_mutex_unlock(&mutex_usb_operation);

	//Usb Return Check
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 GET LENGTH ERROR(0x41) : libusb result - %d\n", ret);
		ret = LIBUSB_FAIL;
		return ret;
	}

	//Getting Stream Length
	memset(resultBuf, 0, 16);
	transferred_len = 0;
	//pthread_mutex_lock(&mutex_usb_operation);
	ret = libusb_bulk_transfer(g_usb_handle,
								0x81,
								resultBuf,
								16,
								&transferred_len,
								30
								);
	//pthread_mutex_unlock(&mutex_usb_operation);

	//Usb Return Check
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 GET LENGTH RESP(0x41) : libusb result - %d\n", ret);
		ret =  LIBUSB_FAIL;
		memset(resultBuf, 0, 16);
	}
	else
	{
		//Receive Check
		if ( transferred_len != 16 )
		{
			ret = GET_WRONG_RESP_LEN;
			printf("===>VIDAN4110 GET LENGTH RESP(%d) : transferred_len - %d\n", ret, transferred_len);
			memset(resultBuf, 0, 16);
		}
		//FW Return Code Check
		else if ( resultBuf[0] != 0x00 )
		{
			if ( resultBuf[0] != 0xfc )
			{
				ret = GET_WRONG_RESP_RESULT;
				printf("===>VIDAN4110 GET LENGTH RESP(%d) : result - 0x%02x\n", ret, resultBuf[0]);
				memset(resultBuf, 0, 16);
			}
		}
		//Wrong Command Check
		else if ( resultBuf[1] != command )
		{
			ret = CMD_WRONG_CMD_FAIL;
			printf("===>VIDAN4110 GET LENGTH RESP(%d) : result - 0x%02x\n", ret, resultBuf[1]);
			memset(resultBuf, 0, 16);
		}

	}

	//Frame Length Setting
	*h264Length = (((int)resultBuf[7] << 24 ) & 0xff000000 )
				| (((int)resultBuf[6] << 16 ) & 0x00ff0000)
				| (((int)resultBuf[5] << 8  ) & 0x0000ff00)
				| (((int)resultBuf[4] << 0  ) & 0x000000ff);

	*jpegLength = (((int)resultBuf[7 + 8] << 24 ) & 0xff000000 )
				| (((int)resultBuf[6 + 8] << 16 ) & 0x00ff0000)
				| (((int)resultBuf[5 + 8] << 8  ) & 0x0000ff00)
				| (((int)resultBuf[4 + 8] << 0  ) & 0x000000ff);

	return ret;
}



/**********************************************************************/
/*                 Get Stream										  */ 
/**********************************************************************/
static int GetStream(GET_STREAM_EP_TYPE type, int frameLen, char *streamBuffer)
{
	int ret;
	int transferred_len;

   	transferred_len = 0;

	//Getting Stream 
	//pthread_mutex_lock(&mutex_usb_operation);
	ret = libusb_bulk_transfer(g_usb_handle,
								(unsigned char)type,
								(unsigned char*)streamBuffer,
								frameLen,
								&transferred_len,
								100
								//1000
								);
	//pthread_mutex_unlock(&mutex_usb_operation);

	//Usb Return Check
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 GET STREAM ERROR(type : 0x%02x, frameLen : %d, tranLen : %d) : libusb result - %d\n", (unsigned char)type, frameLen, transferred_len, ret);
		ret = LIBUSB_FAIL;
		return ret;
	}
	else
	{
		//Data Length Check
		if ( frameLen != transferred_len )
		{
			ret = GET_WRONG_STREAM_LEN;
			printf("===>VIDAN4110 GET STREAM ERROR(%d) : frameLen - %d, transferredLen - %d\n", ret, frameLen, transferred_len);
			return ret;
		}
	}

	return transferred_len;
}

/**********************************************************************/
/*																	  */
/*                 USB Device Open/close	                          */
/* 																	  */
/**********************************************************************/
int redwood_usb_device_open(unsigned short vid, unsigned short pid)
{

	int ret;

	int i;

	libusb_device **list;
	libusb_device *found = NULL;

	ret = libusb_init(NULL);


	if ( ret < 0 )
	{
		printf("===>VIDAN4110 ERROR : libusb result - %d\n", ret);
		return LIBUSB_FAIL;
	}

	ret = libusb_get_device_list(NULL, &list);
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 ERROR : libusb result - %d\n", ret);
		return LIBUSB_FAIL;
	}

	for (i = 0; i < ret; i++) {
		libusb_device *device = list[i];
		//Debug
		if (is_my_device(device, vid, pid)) {
		   printf("===>VIDAN4110 INFO : Vid - 0x%04x, Pid - 0x%04x\n", vid, pid);
			found = device;

			break;
		}
	}

	if (!found) //My device is disconnected
	{
		return USB_DEVICE_FIND_FAIL;
	}

	//Open -> Reset -> Clain Interface
	ret = libusb_open(found, &g_usb_handle);
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 ERROR : libusb result - %d\n", ret);
		return LIBUSB_FAIL;
	}

	libusb_free_device_list(list, 1); // After open device, free list.

	//ret = libusb_reset_device(g_usb_handle);
	//if ( ret < 0 )
	//{
  	//	g_usb_handle = NULL;
	//	printf("===>VIDAN4110 ERROR : libusb result - %d\n", ret);
	//	return LIBUSB_FAIL;
	//}

	ret = libusb_claim_interface(g_usb_handle, 0);
	if ( ret < 0 )
	{
  		g_usb_handle = NULL;
		printf("===>VIDAN4110 ERROR : libusb result - %d\n", ret);
		return LIBUSB_FAIL;
	}

	ret = SUCCESS;

	return ret;
}


int redwood_usb_device_close(void)
{
	int ret;
	unsigned char commandBuf[64];
	unsigned char resultBuf[64];

	if ( !g_usb_handle ) return USB_DEVICE_NULL_FAIL; //if null handle

	//Reset buffer

	commandBuf[0] = 0x21;
	commandBuf[1] = 23;
	commandBuf[2] = 0;
	commandBuf[3] = 1;
	commandBuf[4] = 0x03;
	ret = usb_send_command(5, commandBuf, 2, resultBuf);


	ret = libusb_release_interface(g_usb_handle, 0);
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 ERROR : libusb result - %d\n", ret);
		return LIBUSB_FAIL;
	}

	libusb_close(g_usb_handle);

	libusb_exit(NULL); //Deinitialize libusb

	return SUCCESS;

}

static int is_my_device(libusb_device *dev, unsigned short vid, unsigned short pid)
{
   	struct libusb_device_descriptor desc;
	int ret = libusb_get_device_descriptor(dev, &desc);

	if ( ret < 0 )
	{
		printf("===>VIDAN4110 ERROR : libusb result - %d\n", ret);
		ret = 0;
	}
	else
	{
		if ( desc.idVendor == vid && desc.idProduct == pid )
			ret = 1;
		else
			ret = 0;
	}

	return ret;
}

static int getHeaderIdx(int dataLen, char *dataBuf) {
	int i;
	int idx;
	int val = 0xffffffff;

	for (i = 0; i < dataLen; i++) {
		val <<= 8;
		val |= dataBuf[i];
		if (val == 0x00000001)
			break;
	}
	if (i == dataLen)
		idx = -1;
	else
		idx = i - 3;

	return idx;
}

/***********************************************************************/
/*																							  */
/*                        Firmware Upgrade	                          */
/* 																	  					  */
/***********************************************************************/
int redwood_firmware_upgrade_start_set(char *romfilepath)
{
	int i;
	FILE *checkFile = NULL;
	char *romFileName;

	romFileName = (char*)malloc(sizeof(char)*256);
	if ( romFileName == NULL )
		return FILE_OPEN_FAIL;

	for ( i = 0; i < 5; i++ )
	{
		sprintf(romFileName, "%s/rom%d", romfilepath, i);
		checkFile = fopen(romFileName, "rb");
		if ( checkFile == NULL ) 
		{
			printf("===>VIDAN4110 ERROR : Rom file(%s) not found\n", romFileName);
			return FILE_OPEN_FAIL;
		}
		else
		{
			fclose(checkFile);
		}
	}
	strcpy(romFilePath, romfilepath);

	if ( romFileName )
		free(romFileName);

	return SUCCESS;

}

int usbcontrol_firmware_upgrade_thread_create(void *ptr)
{
	int ret;

	pthread_attr_t		attr;
	struct sched_param	sched;

	pthread_attr_init(&attr);
	pthread_attr_setstacksize(&attr, USBCONTROL_FIRMWARE_UPGRADE_THREAD_STACKSIZE);
	//pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //After pthread_join
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);

	pthread_attr_setschedpolicy(&attr, SCHED_RR);
	pthread_attr_getschedparam(&attr, &sched);
	sched.sched_priority = USBCONTROL_THREAD_PRIORITY;
	pthread_attr_setschedparam(&attr, &sched);

	is_usbcontrol_firmware_upgrade_thread_started = 1;

	ret  = pthread_create( &usbcontrol_firmware_upgrade_thread,
							&attr,
							usbcontrol_firmware_upgrade_thread_func,
						 	ptr);

	return ret;
}

int usbcontrol_firmware_upgrade_thread_destory(void)
{
	return SUCCESS;
}

//FIRMWARE upgrade sdram write command : 0x54
//FIRMWARE upgrade length command : 0x55
//FIRMWARE upgrade flash write command : 0x56
//Max legnth : MAX_ROM_PACKET_SIZE bytest per one bulk
static void *usbcontrol_firmware_upgrade_thread_func(void *ptr)
{
	int ret;
	unsigned char commandBuf[64];
	unsigned char resultBuf[64];
	unsigned char versionBuf[60];

	FILE *romfile = NULL;
	char romFileName[256] = {0};
	int  readLen = 0;
	int i = 0, totalCnt = 0, totalPage = 0;
	unsigned int rom_addr = 0;

	printf("===>VIDAN4110 INFO : usbcontrol_firmware_upgrade_thread_func started\n");

	pthread_mutex_lock(&mutex_usb_operation);
	

	//Firmware version Check
	commandBuf[0] = 0x57;
	commandBuf[1] = 0x0;
	commandBuf[2] = 0x0;
	commandBuf[3] = 0x0;
	ret = usb_send_command(4, commandBuf, 64, resultBuf);
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 ERROR : func(%s), line(%d) %d code\n", __FUNCTION__, __LINE__, ret);
		is_usbcontrol_firmware_upgrade_thread_started = 0;
		pthread_mutex_unlock(&mutex_usb_operation);
		return NULL;
	}
	printf("===>VIDAN4110 INFO : Firmware Information\n");
	printf("%s\n", resultBuf + 4);

	sprintf(romFileName, "%s/rom4", romFilePath);
	romfile = fopen(romFileName, "rb");
	if (romfile == NULL )
	{
		printf("===>VIDAN4110 ERROR : func(%s), line(%d) %s file not found\n", __FUNCTION__, __LINE__, romFileName);
		is_usbcontrol_firmware_upgrade_thread_started = 0;
		pthread_mutex_unlock(&mutex_usb_operation);
		return NULL;
	}

	memset(versionBuf, 0, 60);
	readLen = fread(versionBuf, 1, 60, romfile);
	if ( romfile )
		fclose(romfile);
	for ( i = 0; i < readLen; i++ )
	{
		if ( resultBuf[i+4] != versionBuf[i] )
			break;
	}


	//if ( i == readLen )
	//{
	//	printf("===>VIDAN4110 INFO : Last Firmware\n");
	//	is_usbcontrol_firmware_upgrade_thread_started = 0;
	//	pthread_mutex_unlock(&mutex_usb_operation);
	//	return NULL;
	//}
	//else
	{
		printf("===>VIDAN4110 INFO : New Fimware %s\n", versionBuf);
	}

	//Version Checek End

	for ( i = 0; i < 5; i++ )
	{
		//Rom File Upload
		sprintf(romFileName, "%s/rom%d", romFilePath, i);
		romfile = fopen(romFileName, "rb");
		if (romfile == NULL )
		{
			printf("===>VIDAN4110 ERROR : func(%s), line(%d) %s file not found\n", __FUNCTION__, __LINE__, romFileName);
			is_usbcontrol_firmware_upgrade_thread_started = 0;
			pthread_mutex_unlock(&mutex_usb_operation);
			return NULL;
		}

		switch(i)
		{
			case 0:
				rom_addr = ROM0_BASE_ADDR;
				break;
			case 1:
				rom_addr = ROM1_BASE_ADDR;
				break;
			case 2:
				rom_addr = ROM2_BASE_ADDR;
				break;
			case 3:
				rom_addr = ROM3_BASE_ADDR;
				break;
			case 4:
				rom_addr = ROM4_BASE_ADDR;
				break;
			default:
				printf("wierd\n");
		}

		totalCnt = 0;
		totalPage = 0;
		while(1)
		{
			memset(commandBuf, 0, 64);
			commandBuf[0] = 0x54;
			commandBuf[1] = (unsigned char)(rom_addr >> 16);
			commandBuf[2] = (unsigned char)(rom_addr >> 8);
			commandBuf[3] = (unsigned char)(rom_addr);
			readLen = fread(commandBuf + 4, 1, MAX_ROM_PACKET_SIZE, romfile);
			ret = usb_send_command(4 + MAX_ROM_PACKET_SIZE, commandBuf, 3, resultBuf);
			if ( ret < 0 )
			{
				printf("===>VIDAN4110 ERROR : func(%s), line(%d) %d code\n", __FUNCTION__, __LINE__, ret);
				is_usbcontrol_firmware_upgrade_thread_started = 0;
				pthread_mutex_unlock(&mutex_usb_operation);
				return NULL;
			}

			rom_addr += MAX_ROM_PACKET_SIZE;
			totalCnt += MAX_ROM_PACKET_SIZE;
			if (	readLen != MAX_ROM_PACKET_SIZE)
				break;
		}

		if ( romfile )
			fclose(romfile);
		
		//Send Length
		totalPage = (totalCnt / FLASH_PAGE_UNIT) + 1;
		printf("totalPage:0x%04x\n", totalPage);

		commandBuf[0] = 0x55;
		commandBuf[1] = i; //Rom Num
		commandBuf[2] = (unsigned char)(totalPage >> 8);
		commandBuf[3] = (unsigned char)(totalPage);
		ret = usb_send_command(4, commandBuf, 3, resultBuf);
		if ( ret < 0 )
		{
			printf("===>VIDAN4110 ERROR : func(%s), line(%d) %d code\n", __FUNCTION__, __LINE__, ret);
			is_usbcontrol_firmware_upgrade_thread_started = 0;
			pthread_mutex_unlock(&mutex_usb_operation);
			return NULL;
		}

	}

	//Write Command
	commandBuf[0] = 0x56;
	commandBuf[1] = 0x0;
	commandBuf[2] = 0x0;
	commandBuf[3] = 0x1f; //upload num(rom4 | rom3 | rom2 | rom1 | rom0)
	ret = usb_send_command(4, commandBuf, 3, resultBuf);
	if ( ret < 0 )
	{
		printf("===>VIDAN4110 ERROR : func(%s), line(%d) %d code\n", __FUNCTION__, __LINE__, ret);
		is_usbcontrol_firmware_upgrade_thread_started = 0;
		pthread_mutex_unlock(&mutex_usb_operation);
		return NULL;
	}

	//Maximum Firmware uploading Time
	//usleep(8000000);
	usleep(5000000);

	//Read Firmware upload error bit
	commandBuf[0] = 0x20;
	commandBuf[1] = 11;
	commandBuf[2] = 0;
	commandBuf[3] = 1;
	ret = usb_send_command(4, commandBuf, 5, resultBuf);
	if ( resultBuf[4] & 0x02 )
	{
		printf("===>VIDAN4110 ERROR : Firmware Validation Check Error\n");
		is_usbcontrol_firmware_upgrade_thread_started = 0;
		pthread_mutex_unlock(&mutex_usb_operation);
		return NULL;
	}
	else if ( !(resultBuf[4] & 0x01))
	{
		printf("===>VIDAN4110 ERROR : Firmware Upload Progress\n");
		is_usbcontrol_firmware_upgrade_thread_started = 0;
		pthread_mutex_unlock(&mutex_usb_operation);
		return NULL;
	}
	else
	{
		printf("===>VIDAN4110 INFO : Firmware Upload Done Properly\n");
	}

	//End of upload
	//Chip Reset
	//commandBuf[0] = 0x21;
	//commandBuf[1] = 23;
	//commandBuf[2] = 0;
	//commandBuf[3] = 1;
	//commandBuf[4] = 3;
	//ret = usb_send_command(5, commandBuf, 2, resultBuf);

	is_usbcontrol_firmware_upgrade_thread_started = 0;

	//Termination condition check
	pthread_mutex_unlock(&mutex_usb_operation);

	printf("===>VIDAN4100 INFO : usbcontrol_firmware_upgrade_thread_func terminated\n");

	return NULL;
}

int redwood_usb_firmware_version_check(char *strVersion)
{
	int ret;
	unsigned char commandBuf[64];
	unsigned char resultBuf[64];

	pthread_mutex_lock(&mutex_usb_operation);

	ret = redwood_usb_device_open(VIDAN_USB_VID, VIDAN_USB_PID);
	if ( ret == SUCCESS )
	{
		//Firmware version Check
		commandBuf[0] = 0x57;
		commandBuf[1] = 0x0;
		commandBuf[2] = 0x0;
		commandBuf[3] = 0x0;
		ret = usb_send_command(4, commandBuf, 64, resultBuf);
		if ( ret < 0 )
		{
			printf("===>VIDAN4110 ERROR : func(%s), line(%d) %d code\n", __FUNCTION__, __LINE__, ret);
			is_usbcontrol_firmware_upgrade_thread_started = 0;
			pthread_mutex_unlock(&mutex_usb_operation);
			return LIBUSB_FAIL;
		}
		//printf("===>VIDAN4110 INFO : Firmware Information\n");
		//printf("%s\n", resultBuf + 4);
		strcpy(strVersion, (char*)(resultBuf + 4));
	} 
	
	ret = redwood_usb_device_close();
	pthread_mutex_unlock(&mutex_usb_operation);
	return SUCCESS;
}


/**********************************************************************/
/*																	  */
/*                        Source End	                              */
/* 																	  */
/**********************************************************************/
