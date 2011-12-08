#include <string.h>
#include "map_hif.h"
#include "spi_operation.h"
#include "flash_operation.h"
#include "firmware_upload.h"
#include "uart.h"

#define FLASH_CMD_WRITE_ENABLE				0x06
#define FLASH_CMD_WRITE_DISABLE				0x04
#define FLASH_CMD_READ_STATUS_REGISTER		0x05
#define FLASH_CMD_WRITE_STATUS_REGISTER		0x01
#define FLASH_CMD_READ_DATA					0x03
#define FLASH_CMD_PAGE_PROGRAM				0x02
#define FLASH_CMD_SECTOR_ERASE				0x20
#define BP2		( 1 << 4 )
#define BP1		( 1 << 3 )
#define BP0		( 1 << 2 )
#define WEL		( 1 << 1 )
#define WIP		( 1 << 0 )

extern unsigned char avata_capture_mode;

void flash_write(char *srcBuf, int srcLen, unsigned int baseAddress)
{
	int i;

	spi_open(4000000); //4mhz

	//Write Enable 
	spi_write_buf[0] = FLASH_CMD_WRITE_ENABLE;
	spi_write(1, 1);
	//Unprotect
	spi_write_buf[0] = FLASH_CMD_WRITE_STATUS_REGISTER;
	spi_write_buf[1] = 0x00;
	spi_write(1, 2);
	do //Write in Progress Check
	{
		spi_write_buf[0] = FLASH_CMD_READ_STATUS_REGISTER;
		spi_write(1, 2);
	} while( spi_read_buf[1] & 0x01);
	//Write Enable 
	spi_write_buf[0] = FLASH_CMD_WRITE_ENABLE;
	spi_write(1, 1);
	//Erase Sector
	spi_write_buf[0] = FLASH_CMD_SECTOR_ERASE;
	spi_write_buf[1] = baseAddress >> 16; spi_write_buf[2] = baseAddress >> 8;
	spi_write_buf[3] = baseAddress;
	spi_write(1, 4);
	do //Write in Progress Check
	{
		spi_write_buf[0] = FLASH_CMD_READ_STATUS_REGISTER;
		spi_write(1, 2);
	} while( spi_read_buf[1] & 0x01);
	//Write Enable 
	spi_write_buf[0] = FLASH_CMD_WRITE_ENABLE;
	spi_write(1, 1);
	//Page Program
	spi_write_buf[0] = FLASH_CMD_PAGE_PROGRAM;
	spi_write_buf[1] = baseAddress >> 16;
	spi_write_buf[2] = baseAddress >> 8;
	spi_write_buf[3] = baseAddress;
	for ( i = 0; i < srcLen; i++ )
	{
		spi_write_buf[i+4] = srcBuf[i];
	}
	spi_write(1, srcLen + 4);
	do //Write in Progress Check
	{
		spi_write_buf[0] = FLASH_CMD_READ_STATUS_REGISTER;
		spi_write(1, 2);
	} while( spi_read_buf[1] & 0x01);
	//Write Enable 
	spi_write_buf[0] = FLASH_CMD_WRITE_ENABLE;
	spi_write(1, 1);
	//Protect
	spi_write_buf[0] = FLASH_CMD_WRITE_STATUS_REGISTER;
	spi_write_buf[1] = 0x1C;
	spi_write(1, 2);
	do //Write in Progress Check
	{
		spi_write_buf[0] = FLASH_CMD_READ_STATUS_REGISTER;
		spi_write(1, 2);
	} while( spi_read_buf[1] & 0x01);

	spi_close();

	return;
}

void flash_read(char *dstBuf, int dstLen, unsigned int baseAddress)
{
	int i;
	
	spi_open(4000000); //4Mhz

	spi_write_buf[0] = FLASH_CMD_READ_DATA;
	spi_write_buf[1] = baseAddress >> 16;
	spi_write_buf[2] = baseAddress >> 8;
	spi_write_buf[3] = baseAddress;

	spi_write(1, dstLen + 4);

	spi_close();

	for ( i = 0; i < dstLen; i++ )
	{
		dstBuf[i] = spi_read_buf[i+4];
	}

	return;
}

void flash_write_initial_sdramc1_register(void)
{
	//Flash read/write
	char flashTmpBuf[32];
	char flashValidBuf[32];
	unsigned char isFlashDataOK = 0;
	int nop_i;
	int i;

	//next mode : SDRAMC1 mode change //critical make sure write is ok...
	flashValidBuf[ 0]=0x10;flashValidBuf[ 1]=0x41;flashValidBuf[ 2]=0x76;flashValidBuf[ 3]=0xBF;
	flashValidBuf[ 4]=0x05;flashValidBuf[ 5]=0x11;flashValidBuf[ 6]=0x91;flashValidBuf[ 7]=0xCB;
	flashValidBuf[ 8]=0x30;flashValidBuf[ 9]=0x4B;flashValidBuf[10]=0x02;flashValidBuf[11]=0x11;
	flashValidBuf[12]=0x03;flashValidBuf[13]=0x00;flashValidBuf[14]=0x00;flashValidBuf[15]=0x00;
	flashValidBuf[16]=0x00;flashValidBuf[17]=0x00;flashValidBuf[18]=0x00;flashValidBuf[19]=0x00;
	flashValidBuf[20]=0x00;flashValidBuf[21]=0x80;flashValidBuf[22]=0xE0;flashValidBuf[23]=0x2E;
	flashValidBuf[24]=0x00;flashValidBuf[25]=0x00;flashValidBuf[26]=0x00;flashValidBuf[27]=0x00;
	flashValidBuf[28]=0x00;flashValidBuf[29]=0x00;flashValidBuf[30]=0x00;flashValidBuf[31]=0x00;

	isFlashDataOK = 0;
	do
	{
		flash_write(flashValidBuf, 32, 0x080000);
		memset(flashTmpBuf, 0, 32);
		flash_read(flashTmpBuf, 32, 0x080000);
		for ( i = 0; i < 32; i++ )
		{
			if ( flashTmpBuf[i] != flashValidBuf[i] )
				break;
		}
		if ( i == 32 )
		{
			isFlashDataOK = 1;
		}
		else
		{
			isFlashDataOK = 0;
			uart_print("!!!!!!!!!!!!!!!Initial SDRAMC1 Register Problem!!!!!!!!!!!!!!!!!!!\n\r");
		}
	} while (isFlashDataOK == 0);
	//uart_print("SDRAMC1 OK\n\r");

	//Avata mode flag Set
	flashValidBuf[0] = 0xD8;
	do
	{
		flash_write(flashValidBuf, 1, 0x0A0000);
		flashTmpBuf[0] = 0xff;
		flash_read(flashTmpBuf, 1, 0x0A0000);
	} while( flashTmpBuf[0] != flashValidBuf[0] );
	//uart_print("Avata flag set\n\r");

	//while(1);
	//Reset
	//uart_print("Reset\n\r");
 	for ( nop_i = 0; nop_i < 10000000; nop_i++ ) __asm __volatile("l.nop   0");
	HOST_RESET = 0x03;
}


void flash_avata_mode_check(void)
{
	char flashTmpBuf[32];
	int i;
	//Avata Capture Mode Check
	for ( i = 0; i < 3; i++ )
	{
		flash_read(flashTmpBuf, 1, 0x0A0000);
		avata_capture_mode = ( (unsigned char)flashTmpBuf[0] == 0xD8 ) ? 1 : 0;
	}
}

void flash_write_initial_sdramc2_register(void)
{
	char flashTmpBuf[32];
	char flashValidBuf[32];
	unsigned char isFlashDataOK = 0;
	int i;

	//next mode : SDRAMC2 mode chanage //critical make sure write is ok...
	flashValidBuf[ 0]=0x10;flashValidBuf[ 1]=0x41;flashValidBuf[ 2]=0x76;flashValidBuf[ 3]=0xBF;
	flashValidBuf[ 4]=0x05;flashValidBuf[ 5]=0x11;flashValidBuf[ 6]=0x91;flashValidBuf[ 7]=0xCB;
	flashValidBuf[ 8]=0x30;flashValidBuf[ 9]=0x4B;flashValidBuf[10]=0x12;flashValidBuf[11]=0x11;
	flashValidBuf[12]=0x03;flashValidBuf[13]=0x00;flashValidBuf[14]=0x00;flashValidBuf[15]=0x00;
	flashValidBuf[16]=0x00;flashValidBuf[17]=0x00;flashValidBuf[18]=0x00;flashValidBuf[19]=0x00;
	flashValidBuf[20]=0x00;flashValidBuf[21]=0x80;flashValidBuf[22]=0xE0;flashValidBuf[23]=0x2E;
	flashValidBuf[24]=0x00;flashValidBuf[25]=0x00;flashValidBuf[26]=0x00;flashValidBuf[27]=0x00;
	flashValidBuf[28]=0x00;flashValidBuf[29]=0x00;flashValidBuf[30]=0x00;flashValidBuf[31]=0x00;

	isFlashDataOK = 0;
	do
	{
		flash_write(flashValidBuf, 32, 0x080000);
		memset(flashTmpBuf, 0, 32);
		flash_read(flashTmpBuf, 32, 0x080000);
		for ( i = 0; i < 32; i++ )
		{
			if ( flashTmpBuf[i] != flashValidBuf[i] )
				break;
		}
		if ( i == 32 )
		{
			isFlashDataOK = 1;
		}
		else
		{
			isFlashDataOK = 0;
			uart_print("!!!!!!!!!!!!!!!Initial SDRAMC2 Register Problem!!!!!!!!!!!!!!!!!!!\n\r");
		}
	} while (isFlashDataOK == 0);
	//uart_print("SDRAMC2 OK\n\r");

	//Avata mode flag Clear
	flashValidBuf[0] = 0x00;
	do
	{
		flash_write(flashValidBuf, 1, 0x0A0000);
		flashTmpBuf[0] = 0xff;
		flash_read(flashTmpBuf, 1, 0x0A0000);
	} while( flashTmpBuf[0] != flashValidBuf[0] );
	//uart_print("Avata flag cleared\n\r");

	//if ( avata_capture_mode )
	//	uart_print("======================avata_capture_mode\n\r");
}

void flash_unprotect(void)
{
	unsigned char regValue;
	regValue = flash_read_register();
	regValue &= ~( BP2 | BP1 | BP0 );
	flash_write_register(regValue); 
}

void flash_protect(void)
{
	unsigned char regValue;
	regValue = flash_read_register();
	regValue |= ( BP2 | BP1 | BP0 );
	flash_write_register(regValue); 
}

void flash_erase_one_sector(int addr)
{
	flash_write_enable(); 

	spi_write_buf[0] = FLASH_CMD_SECTOR_ERASE;
	spi_write_buf[1] = (unsigned char)( addr >> 16);
	spi_write_buf[2] = (unsigned char)( addr >>  8);
	spi_write_buf[3] = (unsigned char)( addr >>  0);
	spi_write(1, 4);

	//uart_print("erase:");
	//uart_printInt(spi_write_buf[1]);
	//uart_print(",");
	//uart_printInt(spi_write_buf[2]);
	//uart_print(",");
	//uart_printInt(spi_write_buf[3]);
	//uart_print(",");
	//uart_printInt(flash_read_register());
	//uart_print("\n\r");
	flash_wip_wait();
}

void flash_write_one_page(int addr, char *dataBuf)
{
	int i;

	flash_write_enable(); 

	spi_write_buf[0] = FLASH_CMD_PAGE_PROGRAM;
	spi_write_buf[1] = addr >> 16;
	spi_write_buf[2] = addr >> 8;
	spi_write_buf[3] = addr;

	for ( i = 0; i < FLASH_PAGE_UNIT; i++ )
	{
		spi_write_buf[i+4] = dataBuf[i];
	}
	spi_write(1, FLASH_PAGE_UNIT + 4);

	//uart_print("pp:");
	//uart_printInt(spi_write_buf[1]);
	//uart_print(",");
	//uart_printInt(spi_write_buf[2]);
	//uart_print(",");
	//uart_printInt(spi_write_buf[3]);
	//uart_print(",");
	//uart_printInt(spi_write_buf[4]);
	//uart_print(",");
	//uart_printInt(flash_read_register());
	//uart_print("\n\r");

	flash_wip_wait();
}

void flash_read_one_page(int addr, char *dataBuf)
{
	int i;

	spi_write_buf[0] = FLASH_CMD_READ_DATA;
	spi_write_buf[1] = addr >> 16;
	spi_write_buf[2] = addr >> 8;
	spi_write_buf[3] = addr;
	spi_write(1, FLASH_PAGE_UNIT + 4);

	for ( i = 0; i < FLASH_PAGE_UNIT; i++ )
	{
		dataBuf[i] = spi_read_buf[i+4];
	}

	flash_wip_wait();

}

void flash_write_enable(void)
{
	spi_write_buf[0] = FLASH_CMD_WRITE_ENABLE;
	spi_write(1, 1);
	flash_wip_wait();
	//uart_print("write_enable:");
	//uart_printInt(flash_read_register());
	//uart_print("\n\r");
}

unsigned char flash_read_register(void)
{
	spi_write_buf[0] = FLASH_CMD_READ_STATUS_REGISTER;
	spi_write(1, 2);
	return spi_read_buf[1];
}

void flash_write_register(unsigned char value)
{
	flash_write_enable(); 
	spi_write_buf[0] = FLASH_CMD_WRITE_STATUS_REGISTER;
	spi_write_buf[1] = value;
	spi_write(1, 2);
	//uart_print("flash_write_register:");
	//uart_printInt(spi_write_buf[1]);
	//uart_print(",");
	//uart_printInt(flash_read_register());
	//uart_print("\n\r");
	flash_wip_wait();
}

void flash_wip_wait(void)
{
	int nop_i;
	unsigned char regValue;
	regValue = flash_read_register();
	while ( regValue & WIP )
	{
		//uart_print("reg:");
		//uart_printInt(regValue);
		//uart_print("\n\r");
 		for ( nop_i = 0; nop_i < 1000; nop_i++ ) 
			__asm __volatile("l.nop   0");
		regValue = flash_read_register();
	}

}







