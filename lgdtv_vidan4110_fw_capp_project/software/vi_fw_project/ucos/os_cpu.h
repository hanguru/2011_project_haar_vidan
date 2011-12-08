#ifndef OS_CPU_H
#define OS_CPU_H

#include <or1200.h>

/*
 * Data types
 */
typedef unsigned char BOOLEAN;
typedef unsigned char INT8U;
typedef char INT8S;
typedef unsigned short int INT16U;
typedef short int INT16S;
typedef unsigned long INT32U;
typedef long INT32S;
typedef volatile unsigned char VBOOLEAN;
typedef unsigned int OS_STK;
typedef unsigned int OS_CPU_SR;

#define OS_ENTER_CRITICAL() \
	cpu_sr = mfspr(SPR_SR); \
	mtspr(SPR_SR, cpu_sr & ~(SR_TEE|SR_IEE));
#define OS_EXIT_CRITICAL() \
	mtspr(SPR_SR, cpu_sr);
#ifdef OR1200
#define OS_TASK_SW() \
	__asm __volatile("l.sys %0\nl.nop 0\n" : : "K"(0))
#endif
#ifdef BA22
#define OS_TASK_SW() \
	__asm __volatile("l.sys\nl.nop 0\n" : : "K"(0))
#endif
/*
 * Miscelaneous configuration options
 */
#define OS_CRITICAL_METHOD	3
#define OS_STK_GROWTH		1

#endif /* OS_CPU_H */
