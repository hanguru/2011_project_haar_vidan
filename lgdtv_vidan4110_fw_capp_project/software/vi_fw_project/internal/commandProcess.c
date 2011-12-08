#include "usb.h"
#include "uart.h"
#include "i2s.h"
#include "i2c_operation.h"
#include "commandProcess.h"
#include "gpio.h"  //090408_jykim_dvp_handshaking+
#include "AIC3101.h"
#include "sensor_set.h"
#include "firmware_upload.h"
#include "interrupt_handler.h"
#include "interrupt_handler_gpio.h"

int dummy_k = 0x12345678;
////////////////////////////////////////////////////////
//																										//
//								Global Variables										//
//																										//
////////////////////////////////////////////////////////
VIDEO_STREAM_BUF jpegDualStreamBuf;
VIDEO_STREAM_BUF h264DualStreamBuf;
PCM_STREAM_BUF pcminDualStreamBuf;

volatile int command_video_start = 0;
volatile int command_video_stop = 0;
volatile int command_audio_start = 0;
volatile int command_audio_stop = 0;
extern OS_EVENT *pStartSem;
int isVideoStarted = 0;
int isAudioStarted = 0;
extern int pcm_exist;
volatile int isJpegDataExist = 0;
////////////////////////////////////////////////////////
//																										//
//										Functions												//
//																										//
////////////////////////////////////////////////////////
void setCommandResponse(char *responseBuf, int responseLen);
void internalRegisterRead(char *commandBuf);
void internalRegisterWrite(char *commandBuf);
void hifRegisterRead(char *commandBuf);
void hifRegisterWrite(char *commandBuf);
void hifRegisterBitSet(char *commandBuf);
void hifRegisterBitReset(char *commandBuf);
void i2cMasterRead(char *commandBuf);
void i2cMasterWrite(char *commandBuf);
void streamGetJpegLength(char *commandBuf);
void streamGetH264Length(char *commandBuf);
void streamGetPCMInLength(char *commandBuf);
void commandVideoStart(char *commandBuf);
void commandVideoStop(char *commandBuf);
void commandAudioStart(char *commandBuf);
void commandAudioStop(char *commandBuf);
void videoApiSet(char *commandBuf);
void firmware_sdram_write(char *commandBuf);
void firmware_set_length(char *commandBuf);
void firmware_upload(char *commandBuf);
void firmware_version_check(char *commandBuf);

void commandProcess(char *commandBuf, int commandLen)
{

	//static char prevCommand = 0x00;
	char responseBuf[64] = {0};

	//Debug
	//if ( commandBuf[3] == prevCommand )
	//{
		//uart_print("cd:");
		//uart_printInt(prevCommand);
		//uart_print(",");
		//uart_printInt(commandBuf[3]);
		//uart_print(",");
		//uart_printInt(*(volatile int*)commandBuf);
	 	//uart_print(",");
		//uart_printInt(*(volatile int*)(commandBuf + 4));
		//uart_print("\n\r");
	//}
	//prevCommand = commandBuf[3];

	//Identifier - commandBuf[3]
	switch(commandBuf[3])
	{
		case INTERNAL_REGISTER_READ: // 0x10
			internalRegisterRead(commandBuf);
			break;
		case INTERNAL_REGISTER_WRITE: // 0x11
			internalRegisterWrite(commandBuf);
			break;
		case HIF_REGISTER_READ: // 0x20
			hifRegisterRead(commandBuf);
			break;
		case HIF_REGISTER_WRITE: // 0x21
			hifRegisterWrite(commandBuf);
			break;
		case HIF_REGISTER_BIT_SET: // 0x22
			hifRegisterBitSet(commandBuf);
			break;
		case HIF_REGISTER_BIT_RESET: // 0x23
			hifRegisterBitReset(commandBuf);
			break;
		case I2C_MASTER_READ: // 0x30
			i2cMasterRead(commandBuf);
			break;
		case I2C_MASTER_WRITE: // 0x31
			i2cMasterWrite(commandBuf);
			break;
		case STREAM_GET_JPEG_LENGTH: // 0x40
			streamGetJpegLength(commandBuf);
			break;
		case STREAM_GET_H264_LENGTH: // 0x41
			streamGetH264Length(commandBuf);
			break;
		case STREAM_GET_PCMIN_LENGTH: // 0x42
			streamGetPCMInLength(commandBuf);
			break;
		case COMMAND_VIDEO_START: // 0x50
			commandVideoStart(commandBuf);
			break;
		case COMMAND_VIDEO_STOP: // 0x51
			commandVideoStop(commandBuf);
			break;
		case COMMAND_AUDIO_START: // 0x52
			commandAudioStart(commandBuf);
			break;
		case COMMAND_AUDIO_STOP: // 0x53
			commandAudioStop(commandBuf);
			break;
		case VIDEO_API_SET: // 0x60
			videoApiSet(commandBuf);
			break;
		case COMMAND_FIRMWARE_SDRAM_WRITE: // 0x54
			GPIOSetLow(GPIO12);
			firmware_sdram_write(commandBuf);
			break;
		case COMMAND_FIRMWARE_SET_LENGTH: // 0x55
			firmware_set_length(commandBuf);
			break;
		case COMMAND_FIRMWARE_UPLOAD: // 0x56
			firmware_upload(commandBuf);
			break;
		case COMMAND_FIRMWARE_VERSION_CHECK: // 0x57
			firmware_version_check(commandBuf);
			break;
		default:
			responseBuf[3] = USB_COMMAND_UNDEFINED_COMMAND;
			setCommandResponse(responseBuf, 1);
	}

	return;
}

void internalRegisterRead(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int readToLen = commandBuf[0];
	int registerAddress = *(int*)(commandBuf + 4);

	int i;

	for ( i = 0; i < readToLen; i++ )
	{
		*(int*)(responseBuf + (i+1)*4) = *(volatile int*)(registerAddress + i*4);
		responseLen += 4;
	}

	//Return Code
	responseBuf[3] = USB_COMMAND_SUCCESS;
	responseBuf[2] = INTERNAL_REGISTER_READ;
	responseBuf[1] = DUMMY;
	responseBuf[0] = readToLen;
	responseLen += 4;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void internalRegisterWrite(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int writeToLen = commandBuf[0];
	int registerAddress = *(int*)(commandBuf + 4);

	int i;

	for ( i = 0; i < writeToLen; i++ )
	{
		*(volatile int*)(registerAddress + i*4) = *(int*)(commandBuf + (i+2)*4);
	}

	//Return Code
	responseBuf[3] = USB_COMMAND_SUCCESS;
	responseBuf[2] = INTERNAL_REGISTER_WRITE;
	responseLen += 2;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void hifRegisterRead(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int readToLen = commandBuf[0];
	int registerAddress = HIF_BASE_ADDR + ( ( ((int)commandBuf[2] & 0x000000ff) ) * 4 );

	int i;

	for ( i = 0; i < readToLen; i++ )
	{
		responseBuf[8*(i>>2)+7-i] = 
			(char)(*(volatile int*)(registerAddress + i*4) & 0x000000ff);
		responseLen += 1;
	}

	//Return Code
	responseBuf[3] = USB_COMMAND_SUCCESS;
	responseBuf[2] = HIF_REGISTER_READ;
	responseBuf[1] = commandBuf[2];
	responseBuf[0] = readToLen;
	responseLen += 4;

	//Firmware upgrade end
	if ( commandBuf[2] == 11 )
		GPIOSetHigh(GPIO12);

	setCommandResponse(responseBuf, responseLen);

	return;
}

void hifRegisterWrite(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int writeToLen = commandBuf[0];
	int registerAddress = HIF_BASE_ADDR + ( ( ((int)commandBuf[2] & 0x000000ff) ) * 4 );

	int i;

	//Reset Delay for device Close
	if ( commandBuf[2] == 23 )
 		for ( i = 0; i < 10000000; i++ ) __asm __volatile("l.nop   0");

	for ( i = 0; i < writeToLen; i++ )
	{
		//uart_print("hif set:");
		//uart_printInt(registerAddress + i*4);
		//uart_print(",");
		//uart_printInt(((int)commandBuf[8*(i>>2)+7-i]) & 0x000000ff);
		//uart_print("\n\r");
		
		*(volatile int*)(registerAddress + i*4) = 
			((int)commandBuf[8*(i>>2)+7-i]) & 0x000000ff;
	}

	//Return Code
	responseBuf[3] = USB_COMMAND_SUCCESS;
	responseBuf[2] = HIF_REGISTER_WRITE;
	responseLen += 2;

	//No response for bitrate control and key frame request & reset
	if ( (commandBuf[2] == 62) || ( commandBuf[2] == 66 ) || ( commandBuf[2] == 23 ))
   	{
		return;
	} 
	//Audio Gain
	else if (commandBuf[2] == 63) 
	{
		AIC3101InputGain( AUDIO_GAIN );
		return;
	}

	setCommandResponse(responseBuf, responseLen);

	return;
}

void hifRegisterBitSet(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int registerAddress = HIF_BASE_ADDR + ( ( ((int)commandBuf[2] & 0x000000ff) ) * 4 );

	char value;

	value = (char)(*(volatile int*)registerAddress & 0x000000ff);
	value |= ( commandBuf[1] & commandBuf[0] );
	*(volatile int*)registerAddress = ((int)value) & 0x000000ff;

	//Return Code
	responseBuf[3] = USB_COMMAND_SUCCESS;
	responseBuf[2] = HIF_REGISTER_BIT_SET;
	responseLen += 2;

	//No response for bitrate control and key frame request
	if ( (commandBuf[2] == 62) || ( commandBuf[2] == 66 ) )
		return;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void hifRegisterBitReset(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int registerAddress = HIF_BASE_ADDR + ( ( ((int)commandBuf[2] & 0x000000ff) ) * 4 );

	char value;

	value = (char)(*(volatile int*)registerAddress & 0x000000ff);
	value &= ~( commandBuf[1] & commandBuf[0] );
	*(volatile int*)registerAddress = ((int)value) & 0x000000ff;

	//Return Code
	responseBuf[3] = USB_COMMAND_SUCCESS;
	responseBuf[2] = HIF_REGISTER_BIT_RESET;
	responseLen += 2;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void i2cMasterRead(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int len;
	char slaveID;

	char dataBuf[60] = {0};
	char i2cRet = 0;
	int i;

	len = commandBuf[0];
 	slaveID = commandBuf[2];

	//uart_print("cd2:");
	//uart_printInt(*(volatile int*)commandBuf);
	//uart_print(",");
	//uart_printInt(commandBuf[3]);
	//uart_print(",");
	//uart_printInt(commandBuf[2]);
	//uart_print(",");
	//uart_printInt(commandBuf[1]);
	//uart_print(",");
	//uart_printInt(commandBuf[0]);
	//uart_print(" slaveID:");
	//uart_printInt(slaveID);
	//uart_print(" len:");
	//uart_printInt(len);
	//uart_print("\n\r");

	i2cRet = i2c_read(slaveID, len, dataBuf);

	for ( i = 0; i < len; i++ )
	{
		responseBuf[8*(i>>2)+7-i] = dataBuf[i];
		responseLen += 1;
	}

	//Return Code
	if ( i2cRet == I2C_SUCCESS )
		responseBuf[3] = USB_COMMAND_SUCCESS;
	else
		responseBuf[3] = USB_COMMAND_I2C_FAIL;

	responseBuf[2] = I2C_MASTER_READ;
	responseBuf[1] = i2cRet;
	responseBuf[0] = len;
	responseLen += 4;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void i2cMasterWrite(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int len;
	char slaveID;

	char dataBuf[60] = {0};
	char i2cRet = 0;
	int i;

	len = commandBuf[0];
 	slaveID = commandBuf[2];

	//uart_print("cd1:");
	//uart_printInt(*(volatile int*)commandBuf);
	//uart_print(",");
	//uart_printInt(commandBuf[3]);
	//uart_print(",");
	//uart_printInt(commandBuf[2]);
	//uart_print(",");
	//uart_printInt(commandBuf[1]);
	//uart_print(",");
	//uart_printInt(commandBuf[0]);
	//uart_print(" slaveID:");
	//uart_printInt(slaveID);
	//uart_print(" len:");
	//uart_printInt(len);
	//uart_print("\n\r");


	for ( i = 0; i < len; i++ )
	{
		dataBuf[i] = commandBuf[8*(i>>2)+7-i];
	}

	i2cRet = i2c_write(slaveID, len, dataBuf);

	//Return Code
	if ( i2cRet == I2C_SUCCESS )
		responseBuf[3] = USB_COMMAND_SUCCESS;
	else
		responseBuf[3] = USB_COMMAND_I2C_FAIL;

	responseBuf[2] = I2C_MASTER_WRITE;
	responseBuf[1] = i2cRet;
	responseLen += 3;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void streamGetJpegLength(char *commandBuf) // {{{
{ 
	char responseBuf[64] = {0};
	int responseLen = 0;
	int packet_len = 0;
	if ( jpegDualStreamBuf.count > 0 )
	{
		responseBuf[3] = USB_COMMAND_SUCCESS;
		responseBuf[2] = STREAM_GET_JPEG_LENGTH;
		responseBuf[1] = DUMMY;
		responseBuf[0] = DUMMY;


		responseBuf[7] =  
			(char)((jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] & 0x000000ff)>>0 );
		responseBuf[6] =  
			(char)((jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] & 0x0000ff00)>>8 );
		responseBuf[5] =  
			(char)((jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] & 0x00ff0000)>>16);
		responseBuf[4] =  
			(char)((jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] & 0xff000000)>>24);

		//JPEGendpoint set & toggle ep3
		packet_len = 
			( jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] > USB_EP_MAX_BUFFER_SIZE ) ? USB_EP_MAX_BUFFER_SIZE : jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx];

		//uart_print("addr:");
		//uart_printInt(packet_len);
		//uart_print(",");
		//uart_printInt(jpegDualStreamBuf.address[jpegDualStreamBuf.get_idx]);
		//uart_print("\n\r");
		USB_EP3_IBA = ( packet_len << USB_EP_BUF_SZ_BIT ) 
			| ( jpegDualStreamBuf.address[(int)jpegDualStreamBuf.get_idx] & USB_EP_BUF_PTR_MSK );
#ifdef USB_SET_DELAY
		ms50_delay();
#endif
		//uart_print("1:");
		//uart_printInt(USB_EP3_IBA);
		//uart_print("\n\r");
		//jpegDualStreamBuf.full[jpegDualStreamBuf.get_idx] = 0;
		//jpegDualStreamBuf.count--;
		//jpegDualStreamBuf.get_idx++; 
		//if ( jpegDualStreamBuf.get_idx == VIDEO_BUFFER_CNT )
		//{
		//	jpegDualStreamBuf.get_idx = 0; 
		//}
		jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] -= packet_len; 
		jpegDualStreamBuf.address[(int)jpegDualStreamBuf.get_idx] += packet_len;
		//ep3_nack_toggle();
#ifdef USB_SET_DELAY
		ms50_delay();
#endif
	}
	else
	{
		responseBuf[3] = USB_COMMAND_STREAM_NOT_READY;
		responseBuf[2] = STREAM_GET_JPEG_LENGTH;
		responseBuf[1] = 0x00;
		responseBuf[0] = 0x00; 
		responseBuf[7] = 0x00;
		responseBuf[6] = 0x00; 
		responseBuf[5] = 0x00;
		responseBuf[4] = 0x00; 
	}
	responseLen += 8;

	setCommandResponse(responseBuf, responseLen);

	return;
} // }}}

void streamGetH264Length(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;
	int packet_len = 0;
	if ( (h264DualStreamBuf.full[(int)h264DualStreamBuf.get_idx]) && (h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx] > 0) )
	{
		responseBuf[3] = USB_COMMAND_SUCCESS;
		responseBuf[2] = STREAM_GET_H264_LENGTH; 
		responseBuf[1] = DUMMY;
		responseBuf[0] = DUMMY;

		responseBuf[7] =  
			(char)((h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx] & 0x000000ff)>>0 );
		responseBuf[6] =  
			(char)((h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx] & 0x0000ff00)>>8 );
		responseBuf[5] =  
			(char)((h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx] & 0x00ff0000)>>16);
		responseBuf[4] =  
			(char)((h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx] & 0xff000000)>>24);
		//H264endpoint set & toggle ep4
		packet_len = 
			( h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx] > USB_EP_MAX_BUFFER_SIZE ) ? USB_EP_MAX_BUFFER_SIZE : h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx];

		USB_EP4_IBA = ( packet_len << USB_EP_BUF_SZ_BIT ) 
			| ( h264DualStreamBuf.address[(int)h264DualStreamBuf.get_idx] & USB_EP_BUF_PTR_MSK );
		
		h264DualStreamBuf.len[(int)h264DualStreamBuf.get_idx] -= packet_len; 
		h264DualStreamBuf.address[(int)h264DualStreamBuf.get_idx] += packet_len;

		ms50_delay();
		ep4_nack_toggle();
	}
	else
	{
		responseBuf[3] = USB_COMMAND_STREAM_NOT_READY;
		responseBuf[2] = STREAM_GET_H264_LENGTH; 
		responseBuf[1] = 0x00;
		responseBuf[0] = 0x00; 
		responseBuf[7] = 0x00;
		responseBuf[6] = 0x00; 
		responseBuf[5] = 0x00;
		responseBuf[4] = 0x00; 
	}
	responseLen += 8;

	if ( (jpegDualStreamBuf.full[(int)jpegDualStreamBuf.get_idx]) && (jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx]) > 0 )
	{
		responseBuf[3 + 8] = USB_COMMAND_SUCCESS;
		responseBuf[2 + 8] = STREAM_GET_JPEG_LENGTH;
		responseBuf[1 + 8] = DUMMY;
		responseBuf[0 + 8] = DUMMY;

		responseBuf[7 + 8] =  
			(char)((jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] & 0x000000ff)>>0 );
		responseBuf[6 + 8] =  
			(char)((jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] & 0x0000ff00)>>8 );
		responseBuf[5 + 8] =  
			(char)((jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] & 0x00ff0000)>>16);
		responseBuf[4 + 8] =  
			(char)((jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] & 0xff000000)>>24);

		if ( packet_len == 0 ) //no h264 data
		{
			//JPEGendpoint set & toggle ep3
			packet_len = 
				( jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] > USB_EP_MAX_BUFFER_SIZE ) ? USB_EP_MAX_BUFFER_SIZE : jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx];
//
			USB_EP3_IBA = ( packet_len << USB_EP_BUF_SZ_BIT ) 
				| ( jpegDualStreamBuf.address[(int)jpegDualStreamBuf.get_idx] & USB_EP_BUF_PTR_MSK );
			jpegDualStreamBuf.len[(int)jpegDualStreamBuf.get_idx] -= packet_len; 
			jpegDualStreamBuf.address[(int)jpegDualStreamBuf.get_idx] += packet_len;

			ms50_delay();
			ep3_nack_toggle();
		}
		else
			isJpegDataExist = 1;
	}
	else
	{
		responseBuf[3 + 8] = USB_COMMAND_STREAM_NOT_READY;
		responseBuf[2 + 8] = STREAM_GET_JPEG_LENGTH;
		responseBuf[1 + 8] = 0x00;
		responseBuf[0 + 8] = 0x00; 
		responseBuf[7 + 8] = 0x00;
		responseBuf[6 + 8] = 0x00; 
		responseBuf[5 + 8] = 0x00;
		responseBuf[4 + 8] = 0x00; 
	}
	responseLen += 8;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void streamGetPCMInLength(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;
	int pcmBufferLen = 0;
	int dummyPcmLen = 0;
	//if ( pcminDualStreamBuf.count > 0 )
  	if ( pcminDualStreamBuf.full[(int)pcminDualStreamBuf.get_idx] ) 	
	{
		pcmBufferLen = pcminDualStreamBuf.len[(int)pcminDualStreamBuf.get_idx];
		if ( pcmBufferLen > MAX_PCM_STREAM_LEN )
			pcmBufferLen = MAX_PCM_STREAM_LEN;
		//uart_print("pcmlen:");
		//uart_printInt(pcmBufferLen);
		//uart_print("\n\r");
		responseBuf[3] = USB_COMMAND_SUCCESS;
		responseBuf[2] = STREAM_GET_PCMIN_LENGTH;
		responseBuf[1] = DUMMY;
		responseBuf[0] = DUMMY;

		responseBuf[7] =  
			(char)((pcmBufferLen & 0x000000ff)>>0 );
		responseBuf[6] =  
			(char)((pcmBufferLen & 0x0000ff00)>>8 );
		responseBuf[5] =  
			(char)((pcmBufferLen & 0x00ff0000)>>16);
		responseBuf[4] =  
			(char)((pcmBufferLen & 0xff000000)>>24);

		//PCMINendpoint set & toggle
		USB_EP5_IBA = ( pcmBufferLen << USB_EP_BUF_SZ_BIT ) 
			| ( pcminDualStreamBuf.address[(int)pcminDualStreamBuf.get_idx] & USB_EP_BUF_PTR_MSK );
#ifdef USB_SET_DELAY
		ms50_delay();
#endif
#ifdef USB_SET_DELAY
		ms50_delay();
#endif
		pcminDualStreamBuf.count--;
		pcminDualStreamBuf.len[(int)pcminDualStreamBuf.get_idx] = 0;
		pcminDualStreamBuf.address[(int)pcminDualStreamBuf.get_idx]
			= PCMIN_STREAM_ADDR + MAX_PCM_STREAM_LEN * pcminDualStreamBuf.get_idx;
		pcminDualStreamBuf.full[(int)pcminDualStreamBuf.get_idx] = 0;

		pcminDualStreamBuf.get_idx++;
		if ( pcminDualStreamBuf.get_idx == PCM_BUFFER_CNT )
			pcminDualStreamBuf.get_idx = 0;

		ms50_delay();
		ep5_nack_toggle();
	}
	else
	{
		responseBuf[3] = USB_COMMAND_STREAM_NOT_READY;
		responseBuf[2] = STREAM_GET_PCMIN_LENGTH;
		responseBuf[1] = 0x00;
		responseBuf[0] = 0x00; 
		responseBuf[7] = 0x00;
		responseBuf[6] = 0x00; 
		responseBuf[5] = 0x00;
		responseBuf[4] = 0x00; 
	}

	if ( lost_pcm_len > MAX_PCM_STREAM_LEN )
		dummyPcmLen = MAX_PCM_STREAM_LEN;
	else
		dummyPcmLen = lost_pcm_len;

	lost_pcm_len -= dummyPcmLen;

	responseBuf[11] =  
		(char)((dummyPcmLen & 0x000000ff)>>0 );
	responseBuf[10] =  
		(char)((dummyPcmLen & 0x0000ff00)>>8 );
	responseBuf[ 9] =  
		(char)((dummyPcmLen & 0x00ff0000)>>16);
	responseBuf[ 8] =  
		(char)((dummyPcmLen & 0xff000000)>>24);

	responseLen += 12;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void commandVideoStart(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	//uart_print("Commandvideostart\n\r");
	//command_video_start = 1;
	if ( !isVideoStarted )
	{
		isVideoStarted = 1;
		OSSemPost(pStartSem);

		//Default Frame to 15
		//Bitrate to 32 kbps
		//INTRA_PERIOD = 240; //I-Frame Only
		QP_VALUE_I  = 22; //HIF_REG24  ;qp value i : 28 1c
		QP_VALUE_P  = CONSTANT_QP_VALUE; //HIF_REG25  ;qp value p : 28 1c
		RATE_CONTROL_BIT_RATE_LOW = 0x20;
		RATE_CONTROL_BIT_RATE_HIGH = 0x00; //32 kbps
		RATE_CONTROL_FRAME_RATE = 0xf; //15 fps
	}

	//Return Code
	responseBuf[3] = USB_COMMAND_SUCCESS;
	responseBuf[2] = COMMAND_VIDEO_START;
	responseLen += 2;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void commandVideoStop(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	//uart_print("Commandvideostop\n\r");
	if ( isVideoStarted )
	{
		isVideoStarted = 0;
		command_video_stop = 1;
		init_video_streamBuf();
		OSSemPost(pH264StreamSem);
	}
	//Return Code
	responseBuf[3] = USB_COMMAND_SUCCESS;
	responseBuf[2] = COMMAND_VIDEO_STOP;
	responseLen += 2;

	setCommandResponse(responseBuf, responseLen);

	return;
}


void commandAudioStart(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;
	volatile int temp = 0;
	int pcmDataCnt = 0;
	int pcmDataCnt_i = 0;

	if ( !isAudioStarted )
	{
		//uart_print("AudioStart\n\r");
		if ( AIC_CONTROL_FREQ == AIC_FREQ_12KHZ )
		{
			AIC3101Init( MASTER, AIC3101_FS_12KHz, MIC, AUDIO_GAIN );
			//uart_print("AIC:12Khz\n\r");
		}
		else
		{
			AIC3101Init( MASTER, AIC3101_FS_16KHz, MIC, AUDIO_GAIN );
			//uart_print("AIC:16Khz\n\r");
		}

		isAudioStarted = 1; 
		//flush i2s_fifo
		pcmDataCnt = I2S_RxCnt;
		for (pcmDataCnt_i = 0; pcmDataCnt_i < pcmDataCnt; pcmDataCnt_i
				+= 4) {
			temp = *(volatile int*) I2S_FIFO;
		}
		pcm_exist = 0;

  		init_audio_streamBuf();
		//I2S_RegSet(I2S_RxCR, I2S_En);
		//GPIO Interrupt Enable
		GPIOIntEnable(GPIO15); 

		IntEnable(I2S_RX_IRQ_BIT|AHB2APB_GPIO_INT_BIT);

		GPIOSetLow(GPIO12);
	}
	//Return Code
	responseBuf[3] = USB_COMMAND_SUCCESS;
	responseBuf[2] = COMMAND_AUDIO_START;
	responseLen += 2;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void commandAudioStop(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	if ( isAudioStarted )
	{
		//uart_print("AudioStop\n\r");
		isAudioStarted = 0; 
  		init_audio_streamBuf();
		while(I2S_RxCnt % 4);
		I2S_RegClr(I2S_RxCR, I2S_En);
		IntDisable(I2S_RX_IRQ_BIT);
		pcm_exist = 0;

		if ( !isVideoStarted )
			GPIOSetHigh(GPIO12);
	}
	responseBuf[3] = USB_COMMAND_SUCCESS;
	responseBuf[2] = COMMAND_AUDIO_STOP;
	responseLen += 2;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void videoApiSet(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int videoApicRet = 0;

	videoApicRet = videoApiControl(commandBuf[1], commandBuf[0]);
	//Return Code
	if ( videoApicRet == VIDEOAPISET_SUCCESS )
		responseBuf[3] = USB_COMMAND_SUCCESS;
	else
		responseBuf[3] = USB_COMMAND_VIDEOAPISET_FAIL;

	responseBuf[2] = VIDEO_API_SET;
	responseBuf[1] = videoApicRet;
	responseLen += 3;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void firmware_sdram_write(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int ret = 0;
	unsigned int relativeAddr;

	relativeAddr = (((unsigned int)commandBuf[2] << 16) & 0x00ff0000)
				|  (((unsigned int)commandBuf[1] << 8) & 0x0000ff00)	
				|  (((unsigned int)commandBuf[0]) & 0x000000ff);

	ret = firmwareSdramWrite( relativeAddr, commandBuf + 4);

	//Return Code
	if ( ret == FIRMWARE_OPERATION_SUCCESS )
		responseBuf[3] = USB_COMMAND_SUCCESS;
	else
		responseBuf[3] = FIRMWARE_OPERATION_SUCCESS;

	responseBuf[2] = COMMAND_FIRMWARE_SDRAM_WRITE;
	responseBuf[1] = ret;
	responseLen += 3;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void firmware_set_length(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int ret = 0;
	unsigned char romNum = 0;
	unsigned short pageCnt = 0;

	romNum = (unsigned char)commandBuf[2];

	pageCnt	 = (((unsigned short)commandBuf[1] << 8) & 0xff00)	
			 | (((unsigned short)commandBuf[0]) & 0x00ff);	


	ret = firmwareSetLength(romNum, pageCnt);

	//Return Code
	if ( ret == FIRMWARE_OPERATION_SUCCESS )
		responseBuf[3] = USB_COMMAND_SUCCESS;
	else
		responseBuf[3] = USB_COMMAND_FIRMWARE_SET_LENGTH_FAIL;

	responseBuf[2] = COMMAND_FIRMWARE_SET_LENGTH;
	responseBuf[1] = ret;
	responseLen += 3;

	setCommandResponse(responseBuf, responseLen);

	return;
}

void firmware_upload(char *commandBuf)
{
	//char responseBuf[64] = {0};
	//int responseLen = 0;

	int ret = 0;

	ret = firmwareUpload((unsigned char)commandBuf[0]);

	////Return Code
	//if ( ret == FIRMWARE_OPERATION_SUCCESS )
	//	responseBuf[3] = USB_COMMAND_SUCCESS;
	//else
	//	responseBuf[3] = USB_COMMAND_FIRMWARE_UPLOAD_FAIL;

	//responseBuf[2] = COMMAND_FIRMWARE_UPLOAD;
	//responseBuf[1] = ret;
	//responseLen += 3;

	//setCommandResponse(responseBuf, responseLen);

	return;


}

void firmware_version_check(char *commandBuf)
{
	char responseBuf[64] = {0};
	int responseLen = 0;

	int ret = 0;

	ret = firmwareVersionCheck(responseBuf+4);

	//Return Code
	if ( ret == FIRMWARE_OPERATION_SUCCESS )
		responseBuf[3] = USB_COMMAND_SUCCESS;
	else
		responseBuf[3] = USB_COMMAND_FIRMWARE_VERSION_CHECK_FAIL;

	responseBuf[2] = COMMAND_FIRMWARE_VERSION_CHECK;
	responseBuf[1] = ret;
	responseLen = 64;

	setCommandResponse(responseBuf, responseLen);

	return;
}

////////////////////////////////////////////////////////////
//		Response Set			    					//
////////////////////////////////////////////////////////////
void setCommandResponse(char *responseBuf, int responseLen)
{
	int i;

	//memcpy(EP1_BUF_ADDR, responseBuf, responseLen + 4);
	for ( i = 0; i < responseLen; i += 4)
	{
		*(volatile int*)(EP1_BUF_ADDR + i) = *(volatile int*)((int)responseBuf + i);
	}
 	USB_EP1_IBA = ( responseLen << USB_EP_BUF_SZ_BIT ) | ( EP1_BUF_ADDR & USB_EP_BUF_PTR_MSK );
#ifdef USB_SET_DELAY
	ms50_delay();
#endif
	ep1_nack_toggle();
#ifdef USB_SET_DELAY
	ms50_delay();
#endif

	return;
}

