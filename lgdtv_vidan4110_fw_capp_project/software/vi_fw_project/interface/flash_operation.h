#ifndef _FLASH_OPERATION_H_
#define _FLASH_OPERATION_H_

void flash_write(char *srcBuf, int srcLen, unsigned int baseAddress);
void flash_read(char *dstBuf, int dstLen, unsigned int baseAddress);

void flash_write_initial_sdramc1_register(void);
void flash_write_initial_sdramc2_register(void);
void flash_avata_mode_check(void);

void flash_unprotect(void);
void flash_protect(void);
void flash_wip_wait(void);
void flash_write_enable(void);
unsigned char flash_read_register(void);
void flash_write_register(unsigned char value);
void flash_erase_one_sector(int addr);
void flash_write_one_page(int addr, char *dataBuf);
void flash_read_one_page(int addr, char *dataBuf);


#endif 


