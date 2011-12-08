#include "map_hif.h"
#include "spi_operation.h"
#include "flash_operation.h"
#include "firmware_upload.h"
#include "uart.h"

int romPageCnt[5] = {0};

int firmwareSdramWrite( unsigned int relativeAddr, char *databuf)
{
	int i;
	int tempValue;


	for ( i = 0; i < MAX_ROM_PACKET_SIZE / 4; i++ )
	{
		tempValue =   (((int)databuf[i*4 + 0] << 24) & 0xff000000 )
					| (((int)databuf[i*4 + 1] << 16) & 0x00ff0000 )
					| (((int)databuf[i*4 + 2] <<  8) & 0x0000ff00 )
					| (((int)databuf[i*4 + 3] <<  0) & 0x000000ff );

		*(volatile int*)((unsigned int)FIRMWARE_UPLOAD_SDRAM_BASE + relativeAddr + i*4)
			= tempValue;
	}
			
	return FIRMWARE_OPERATION_SUCCESS;
}

int firmwareSetLength( unsigned char romNum, unsigned short pageCnt)
{
	romPageCnt[romNum] = pageCnt;

	return FIRMWARE_OPERATION_SUCCESS;
}

int firmwareUpload(unsigned char uploadNumBit)
{
	char buf[FLASH_PAGE_UNIT];
	
	int i = 0, j = 0, k = 0;
	int tmpValue;
	unsigned int romBaseAddr = 0x0;

	FW_UPLOAD = 0x00;

	spi_open(4000000); //4mhz

	//Unprotect
	flash_unprotect();

	for ( i = 0; i < 5; i++ )
	{
		if ( uploadNumBit & ( 1 << i) )
		{
			switch(i)
			{
				case 0:
					romBaseAddr = ROM0_BASE_ADDR;
					break;
				case 1:
					romBaseAddr = ROM1_BASE_ADDR;
					break;
				case 2:
					romBaseAddr = ROM2_BASE_ADDR;
					break;
				case 3:
					romBaseAddr = ROM3_BASE_ADDR;
					break;
				case 4:
					romBaseAddr = ROM4_BASE_ADDR;
					break;
				default:
					uart_print("weired\n\r");
			}

			uart_print("Rom");
			uart_printInt(i);
			uart_print("\n\r");
				
			//Page Cnt
			for ( j = 0; j < romPageCnt[i]; j++ )
			{
				//uart_print("page");
				//uart_printInt(j);
				//uart_print("\n\r");
				//One Sector
				if ( j % 16 == 0 )
				{
					//Sector Erase
					flash_erase_one_sector(romBaseAddr + j*FLASH_PAGE_UNIT);
				}

				for ( k = 0; k < FLASH_PAGE_UNIT / 4; k++ )
				{
					tmpValue
						= *(volatile int*)(FIRMWARE_UPLOAD_SDRAM_BASE + romBaseAddr + j*FLASH_PAGE_UNIT  + k*4);
					buf[k*4 + 0] = (tmpValue >> 0);
					buf[k*4 + 1] = (tmpValue >> 8);
					buf[k*4 + 2] = (tmpValue >> 16);
					buf[k*4 + 3] = (tmpValue >> 24);
				}
				//Page Program
				flash_write_one_page(romBaseAddr+j*FLASH_PAGE_UNIT, buf); 
			}
		}
	}

	//Protect
	flash_protect();
	uart_print("flash_upload done\n\r");
	//Write Process End>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	uart_print("Validation Check\n\r");
	//Validation Check
	for ( i = 0; i < 5; i++ )
	{
		if ( uploadNumBit & ( 1 << i) )
		{
			switch(i)
			{
				case 0:
					romBaseAddr = ROM0_BASE_ADDR;
					break;
				case 1:
					romBaseAddr = ROM1_BASE_ADDR;
					break;
				case 2:
					romBaseAddr = ROM2_BASE_ADDR;
					break;
				case 3:
					romBaseAddr = ROM3_BASE_ADDR;
					break;
				case 4:
					romBaseAddr = ROM4_BASE_ADDR;
					break;
				default:
					uart_print("weired\n\r");
			}

			uart_print("Valid Rom");
			uart_printInt(i);
			uart_print("\n\r");

			//Page Cnt
			for ( j = 0; j < romPageCnt[i]; j++ )
			{
				//uart_print("page");
				//uart_printInt(j);
				//uart_print("\n\r");
				//read one page
				flash_read_one_page(romBaseAddr+j*FLASH_PAGE_UNIT, buf); 

				for ( k = 0; k < FLASH_PAGE_UNIT / 4; k++ )
				{
					tmpValue = (((int)buf[k*4 + 0] <<  0) & 0x000000ff)
							|  (((int)buf[k*4 + 1] <<  8) & 0x0000ff00)
							|  (((int)buf[k*4 + 2] << 16) & 0x00ff0000)
							|  (((int)buf[k*4 + 3] << 24) & 0xff000000);

					if ( tmpValue != *(volatile int*)(FIRMWARE_UPLOAD_SDRAM_BASE + romBaseAddr + j*FLASH_PAGE_UNIT  + k*4))
					{
						uart_print("Error\n\r");
						FW_UPLOAD |= FW_UPLOAD_VALID_ERROR_BIT;
					}
				}
			}
		}
	}
	uart_print("Validation Check Done\n\r");

	spi_close();

	FW_UPLOAD |= FW_UPLOAD_DONE_BIT;

	if ( FW_UPLOAD & FW_UPLOAD_VALID_ERROR_BIT )
		return FIRMWARE_OPERATION_FAIL;
	else
		return FIRMWARE_OPERATION_SUCCESS;
}

int firmwareVersionCheck(char *responseBuf)
{
	int i = 0;
	char buf[FLASH_PAGE_UNIT];
	uart_print("FW Version Check\n\r");

	//Version SDRAM Clear
	for ( i = 0; i < FLASH_PAGE_UNIT / 4; i++ )
	{
		*(volatile int*)((unsigned int)FIRMWARE_UPLOAD_SDRAM_BASE + ROM4_BASE_ADDR + i*4) = 0x00000000;
	}

	flash_read_one_page(ROM4_BASE_ADDR, buf); 
	for ( i = 0; i < 60; i++ )
	{
		responseBuf[8*(i>>2)+3-i] = buf[i];
	}

	return FIRMWARE_OPERATION_SUCCESS;
}

