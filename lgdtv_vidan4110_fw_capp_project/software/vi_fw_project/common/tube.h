/* ==============================================================================
 |
 | ------------------------------------------------------------------------------
 | Version and Release Control Information:
 | 
 | File Name           : tube.h
 | File Revision       : 1.0
 | Designer            : Cho Myung Je(luslas@mamurian.com)
 | Date                : 2005. 11.
 | 
 | Release Information : Rev1-0
 | 
 | ------------------------------------------------------------------------------
 | Purpose             : 
 | ============================================================================== */
#ifdef SIMULATION_FIRMWARE
#define __TUBE_IO__
#endif

#ifdef __TUBE_IO__
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define TUBE_BASE_ADDR            0x10000000

#define TUBE_ADDR_WIDTH           16 // Address width of TUBE
// It should be more than 7.

#define TUBE_NUM_BASE_ADDR        (TUBE_BASE_ADDR + (0x0 << (TUBE_ADDR_WIDTH-2)))
#define TUBE_STRING_BASE_ADDR     (TUBE_BASE_ADDR + (0x1 << (TUBE_ADDR_WIDTH-2)))
#define TUBE_SIMULATION_END_ADDR  (TUBE_BASE_ADDR + (0x3 << (TUBE_ADDR_WIDTH-2)))

// #define TUBE_NUM_PRINT_0_ADDR_BASE    (TUBE_NUM_BASE_ADDR + 0x00000000)
// #define TUBE_NUM_PRINT_1_ADDR_BASE    (TUBE_NUM_BASE_ADDR + 0x00100000)
// #define TUBE_NUM_PRINT_2_ADDR_BASE    (TUBE_NUM_BASE_ADDR + 0x00200000)
// #define TUBE_NUM_PRINT_3_ADDR_BASE    (TUBE_NUM_BASE_ADDR + 0x00300000)
// #define TUBE_NUM_PRINT_4_ADDR_BASE    (TUBE_NUM_BASE_ADDR + 0x00400000)
// #define TUBE_NUM_PRINT_5_ADDR_BASE    (TUBE_NUM_BASE_ADDR + 0x00500000)
// #define TUBE_NUM_PRINT_6_ADDR_BASE    (TUBE_NUM_BASE_ADDR + 0x00600000)
// #define TUBE_NUM_PRINT_7_ADDR_BASE    (TUBE_NUM_BASE_ADDR + 0x00700000)
#define TUBE_NUM_PRINT_ADDR           (TUBE_NUM_BASE_ADDR)
#define TUBE_STRING_PRINT_ADDR        (TUBE_STRING_BASE_ADDR)

#define TUBE_PRINT_OUT    0xFF
#define LOG_MSGSIZE       144

#define TUBE_0_PRINT_WORD(_a_)          *(volatile unsigned int *)(TUBE_NUM_PRINT_ADDR) = _a_
#define TUBE_0_PRINT_HWORD(_a_)         *(volatile unsigned short *)(TUBE_NUM_PRINT_ADDR) = _a_
#define TUBE_0_PRINT_BYTE(_a_)          *(volatile unsigned char *)(TUBE_NUM_PRINT_ADDR) = _a_

//#define TUBE_0_PRINT_WORD(_a_ , _b_)    *(volatile unsigned int *)(TUBE_NUM_PRINT_0_ADDR_BASE + _a_) = _b_
//#define TUBE_1_PRINT_WORD(_a_ , _b_)    *(volatile unsigned int *)(TUBE_NUM_PRINT_1_ADDR_BASE + _a_) = _b_
//#define TUBE_2_PRINT_WORD(_a_ , _b_)    *(volatile unsigned int *)(TUBE_NUM_PRINT_2_ADDR_BASE + _a_) = _b_
//#define TUBE_3_PRINT_WORD(_a_ , _b_)    *(volatile unsigned int *)(TUBE_NUM_PRINT_3_ADDR_BASE + _a_) = _b_
//#define TUBE_4_PRINT_WORD(_a_ , _b_)    *(volatile unsigned int *)(TUBE_NUM_PRINT_4_ADDR_BASE + _a_) = _b_
//#define TUBE_5_PRINT_WORD(_a_ , _b_)    *(volatile unsigned int *)(TUBE_NUM_PRINT_5_ADDR_BASE + _a_) = _b_
//#define TUBE_6_PRINT_WORD(_a_ , _b_)    *(volatile unsigned int *)(TUBE_NUM_PRINT_6_ADDR_BASE + _a_) = _b_
//#define TUBE_7_PRINT_WORD(_a_ , _b_)    *(volatile unsigned int *)(TUBE_NUM_PRINT_7_ADDR_BASE + _a_) = _b_
//
//#define TUBE_0_PRINT_HWORD(_a_ , _b_)   *(volatile unsigned short *)(TUBE_NUM_PRINT_0_ADDR_BASE + _a_) = _b_
//#define TUBE_1_PRINT_HWORD(_a_ , _b_)   *(volatile unsigned short *)(TUBE_NUM_PRINT_1_ADDR_BASE + _a_) = _b_
//#define TUBE_2_PRINT_HWORD(_a_ , _b_)   *(volatile unsigned short *)(TUBE_NUM_PRINT_2_ADDR_BASE + _a_) = _b_
//#define TUBE_3_PRINT_HWORD(_a_ , _b_)   *(volatile unsigned short *)(TUBE_NUM_PRINT_3_ADDR_BASE + _a_) = _b_
//#define TUBE_4_PRINT_HWORD(_a_ , _b_)   *(volatile unsigned short *)(TUBE_NUM_PRINT_4_ADDR_BASE + _a_) = _b_
//#define TUBE_5_PRINT_HWORD(_a_ , _b_)   *(volatile unsigned short *)(TUBE_NUM_PRINT_5_ADDR_BASE + _a_) = _b_
//#define TUBE_6_PRINT_HWORD(_a_ , _b_)   *(volatile unsigned short *)(TUBE_NUM_PRINT_6_ADDR_BASE + _a_) = _b_
//#define TUBE_7_PRINT_HWORD(_a_ , _b_)   *(volatile unsigned short *)(TUBE_NUM_PRINT_7_ADDR_BASE + _a_) = _b_
//
//#define TUBE_0_PRINT_BYTE(_a_ , _b_)    *(volatile unsigned char *)(TUBE_NUM_PRINT_0_ADDR_BASE + _a_) = _b_
//#define TUBE_1_PRINT_BYTE(_a_ , _b_)    *(volatile unsigned char *)(TUBE_NUM_PRINT_1_ADDR_BASE + _a_) = _b_
//#define TUBE_2_PRINT_BYTE(_a_ , _b_)    *(volatile unsigned char *)(TUBE_NUM_PRINT_2_ADDR_BASE + _a_) = _b_
//#define TUBE_3_PRINT_BYTE(_a_ , _b_)    *(volatile unsigned char *)(TUBE_NUM_PRINT_3_ADDR_BASE + _a_) = _b_
//#define TUBE_4_PRINT_BYTE(_a_ , _b_)    *(volatile unsigned char *)(TUBE_NUM_PRINT_4_ADDR_BASE + _a_) = _b_
//#define TUBE_5_PRINT_BYTE(_a_ , _b_)    *(volatile unsigned char *)(TUBE_NUM_PRINT_5_ADDR_BASE + _a_) = _b_
//#define TUBE_6_PRINT_BYTE(_a_ , _b_)    *(volatile unsigned char *)(TUBE_NUM_PRINT_6_ADDR_BASE + _a_) = _b_
//#define TUBE_7_PRINT_BYTE(_a_ , _b_)    *(volatile unsigned char *)(TUBE_NUM_PRINT_7_ADDR_BASE + _a_) = _b_


void tube_printf(const char *fmt, ...);

void tube_print(const char *fmt);

void tube_simulation_end(int num);
#else //ifdef __TUBE_IO__
#define TUBE_0_PRINT_WORD(_a_)      /*nop*/
#define TUBE_1_PRINT_WORD(_a_)      /*nop*/
#define TUBE_2_PRINT_WORD(_a_)      /*nop*/
#define TUBE_3_PRINT_WORD(_a_)      /*nop*/
#define TUBE_4_PRINT_WORD(_a_)      /*nop*/
#define TUBE_5_PRINT_WORD(_a_)      /*nop*/
#define TUBE_6_PRINT_WORD(_a_)      /*nop*/
#define TUBE_7_PRINT_WORD(_a_)      /*nop*/

#define TUBE_0_PRINT_HWORD(_a_)     /*nop*/
#define TUBE_1_PRINT_HWORD(_a_)     /*nop*/
#define TUBE_2_PRINT_HWORD(_a_)     /*nop*/
#define TUBE_3_PRINT_HWORD(_a_)     /*nop*/
#define TUBE_4_PRINT_HWORD(_a_)     /*nop*/
#define TUBE_5_PRINT_HWORD(_a_)     /*nop*/
#define TUBE_6_PRINT_HWORD(_a_)     /*nop*/
#define TUBE_7_PRINT_HWORD(_a_)     /*nop*/

#define TUBE_0_PRINT_BYTE(_a_)      /*nop*/
#define TUBE_1_PRINT_BYTE(_a_)      /*nop*/
#define TUBE_2_PRINT_BYTE(_a_)      /*nop*/
#define TUBE_3_PRINT_BYTE(_a_)      /*nop*/
#define TUBE_4_PRINT_BYTE(_a_)      /*nop*/
#define TUBE_5_PRINT_BYTE(_a_)      /*nop*/
#define TUBE_6_PRINT_BYTE(_a_)      /*nop*/
#define TUBE_7_PRINT_BYTE(_a_)      /*nop*/

#define tube_printf(_b_, ...)       /*nop*/
#define tube_print(_b_)             /*nop*/
#define tube_simulation_end(_a_)    /*nop*/

#endif

/* ========================================================================================= */
/*                                            End                                            */
/* ========================================================================================= */

