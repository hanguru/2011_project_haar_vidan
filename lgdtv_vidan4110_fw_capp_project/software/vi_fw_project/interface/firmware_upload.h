#ifndef _FIRMWARE_UPLOAD_H_
#define _FIRMWARE_UPLOAD_H_


#define FIRMWARE_UPLOAD_SDRAM_BASE		0xf11d3800
#define MAX_ROM_PACKET_SIZE		32
#define FLASH_PAGE_UNIT			256

#define ROM0_BASE_ADDR			0x000000
#define ROM1_BASE_ADDR			0x029000
#define ROM2_BASE_ADDR			0x031000
#define ROM3_BASE_ADDR			0x080000
#define ROM4_BASE_ADDR			0x090000

enum
{
	FIRMWARE_OPERATION_FAIL = -1,
	FIRMWARE_OPERATION_SUCCESS = 0,
};


int firmwareSdramWrite( unsigned int relativeAddr, char *databuf);

int firmwareSetLength( unsigned char romNum, unsigned short pageCnt);

int firmwareUpload(unsigned char uploadNumBit);

int firmwareVersionCheck(char *responseBuf);

#endif



