/* ==============================================================================
 |
 | ------------------------------------------------------------------------------
 | Version and Release Control Information:
 | 
 | File Name           : tube.c
 | File Revision       : 1.0
 | Designer            : Cho Myung Je(luslas@mamurian.com)
 | Date                : 2005. 11.
 | 
 | Release Information : Rev1-0
 | 
 | ------------------------------------------------------------------------------
 | Purpose             : 
 | ============================================================================== */

#include "tube.h"
#ifdef __TUBE_IO__

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static void tube_cprintf(const char *fmt, va_list adx)//, const char *prefix, const char *suffix, void *site)
{
	//uint32_t msgid;
	size_t bufsize = LOG_MSGSIZE;
	char buf[LOG_MSGSIZE];
	char *bufp = buf;
	char *body, *msgp, *bufend;
	//int s, on_intr;
	size_t len;
	int i;

	bufend = bufp + bufsize;
	msgp = bufp;
	body = msgp += snprintf(msgp, bufend - msgp, "%s: [ID %u FACILITY_AND_PRIORITY] ");//, mod_containing_pc(site), msgid);
	//msgp += snprintf(msgp, bufend - msgp, prefix);
	msgp += vsnprintf(msgp, bufend - msgp, fmt, adx);
	//msgp += snprintf(msgp, bufend - msgp, suffix);
	len = strlen(body);
	i = 0;
	if (i < 4) {
		for(; i < len; i++) {
			*((volatile char *)TUBE_STRING_PRINT_ADDR) = body[i];
			//printf("%c \n", body[i]);
		}
		return;
	}

	//printf("TUBE_PRINT_OUT \n");
	// for(i = 0; i < (len-3) ; i+=4){
	for(; i < (len-3); i+=4) {
		//    *((volatile int *)TUBE_STRING_PRINT_ADDR) = (((body[i+3]&0xFF)<<24) | ((body[i+2]&0xFF)<<16) |
		//                                                 ((body[i+1]&0xFF)<<8) | ((body[i]&0xFF)));
		*((volatile int *)TUBE_STRING_PRINT_ADDR) = (((body[i+0]&0xFF)<<24) | ((body[i+1]&0xFF)<<16) |
				((body[i+2]&0xFF)<< 8) | ((body[i+3]&0xFF)));
		//printf("%c%c", body[i+3], body[i+2]);
		//printf("%c%c \n", body[i+1], body[i]);
	}

	for(; i < len; i++) {
		*((volatile char *)TUBE_STRING_PRINT_ADDR) = body[i];
		//printf("%c \n", body[i]);
	}

	//*((volatile char *)TUBE_STRING_PRINT_ADDR) = TUBE_PRINT_OUT;
	//printf("TUBE_PRINT_OUT \n");

	return;

}

void tube_printf(const char *fmt, ...)
{
	va_list adx;

	va_start(adx, fmt);
	tube_cprintf(fmt, adx);//, "prefix", "suffix", "");
	va_end(adx);
}

void tube_print(const char *fmt)
{
	size_t len;
	int i;

	len = strlen(fmt);

	for(i = 0; i < (len-3); i+=4) {
		//    *((volatile int *)TUBE_STRING_PRINT_ADDR) = (((fmt[i+3]&0xFF)<<24) | ((fmt[i+2]&0xFF)<<16) |
		//                                                 ((fmt[i+1]&0xFF)<<8) | ((fmt[i]&0xFF)));
		*((volatile int *)TUBE_STRING_PRINT_ADDR) = (((fmt[i+0]&0xFF)<<24) | ((fmt[i+1]&0xFF)<<16) |
				((fmt[i+2]&0xFF)<< 8) | ((fmt[i+3]&0xFF)));
	}

	for(; i < len; i++) {
		*((volatile char *)TUBE_STRING_PRINT_ADDR) = fmt[i];
	}

	//*((volatile char *)TUBE_STRING_PRINT_ADDR) = TUBE_PRINT_OUT;

}

void tube_simulation_end(int num)
{
	*(volatile unsigned int*)TUBE_SIMULATION_END_ADDR = num;
	return;
}

#endif

/* ========================================================================================= */
/*                                            End                                            */
/* ========================================================================================= */

