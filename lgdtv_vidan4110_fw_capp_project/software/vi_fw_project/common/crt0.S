#include "spr_defs.h"
#include "map.h"
#include "map_hif.h"
//#include "mc.h"

/* ======================================================= [ macros ] === */


#define CLEAR_GPR(gpr) \
   l.or    gpr, r0, r0
    
#define ENTRY(symbol)    \
   .global symbol ; \
symbol:

#define GLOBAL(symbol)    \
   .global symbol ; \
symbol:

#define LOAD_SYMBOL_2_GPR(gpr,symbol)  \
   .global symbol ;               \
   l.movhi gpr, hi(symbol) ;      \
   l.ori   gpr, gpr, lo(symbol)

#define UNHANDLED_EXCEPTION            \
   l.addi  r1, r1, -128;          \
   l.sw    4(r1), r3;             \
   l.sw    8(r1), r4;             \
   l.mfspr r3,r0,SPR_PC;          \
   l.mfspr r4,r0,SPR_EPCR_BASE;   \
   /*l.j default_exception_handler; \*/
   l.j _start; \
   l.nop;


/* =================================================== [ exceptions ] === */
   .section .vectors, "ax"


/* ---[ 0x100: RESET exception ]----------------------------------------- */
   .org 0x100 
_reset_exception:
   // +++ luslas_080620 : upper bound +++++++++++++++++++++
   l.movhi r1, 0x0200 // Data RAM address
   l.ori   r1, r1, 0x0
   l.movhi r7, 0x0300 // Data ROM address
   l.ori   r7, r7, 0x0
   l.movhi r5, 0 // counter
   l.movhi r6, 0 // maximum counter (0x10000 = 256KB)
   l.ori   r6, r6, 0x0400 // maximum counter (0x0400 = 4KB)

_PROGRAM_COPY:
   l.lwz   r3, 0(r7)
   l.sw    0(r1), r3

   l.addi  r7, r7, 4
   l.addi  r1, r1, 4

   l.addi  r5, r5, 1
   l.sfeq  r5, r6

   l.bnf _PROGRAM_COPY
   // +++ luslas_080620 : lower bound +++++++++++++++++++++


   l.movhi  r2,hi(_start)
   l.ori    r2,r2,lo(_start)
   l.jr     r2 
   l.nop    0
   

/* ---[ 0x200: BUS exception ]------------------------------------------- */
   .org 0x200
_bus_exception:
   UNHANDLED_EXCEPTION

/* ---[ 0x300: Data Page Fault exception ]------------------------------- */
   .org 0x300
_data_page_fault_exception:
   UNHANDLED_EXCEPTION
   
/* ---[ 0x400: Insn Page Fault exception ]------------------------------- */
   .org 0x400
_insn_page_fault_exception:
   UNHANDLED_EXCEPTION

/* ---[ 0x500: Timer exception ]----------------------------------------- */
   .org 0x500 
_timer_exception:
   l.addi   r1,r1,-4
   l.sw     0(r1),r3
   l.movhi  r3,hi(_Timerint)
   l.ori    r3,r3,lo(_Timerint)
   l.jr     r3
   l.nop    0

/* ---[ 0x600: Aligment exception ]-------------------------------------- */
   .org 0x600
_alignment_exception:
   UNHANDLED_EXCEPTION
   
/* ---[ 0x700: Illegal insn exception ]---------------------------------- */
   .org 0x700
_illegal_exception:
   UNHANDLED_EXCEPTION

/* ---[ 0x800: External interrupt exception ]---------------------------- */
   .org 0x800 
_external_interrupt_exception:
   l.addi   r1,r1,-4
   l.sw     0(r1),r3
   l.movhi  r3,hi(_Extint)
   l.ori    r3,r3,lo(_Extint)
   l.jr     r3
   l.nop    0

/* ---[ 0x900: DTLB miss exception ]------------------------------------- */
   .org 0x900
_dtlb_miss_exception:
   UNHANDLED_EXCEPTION
   
/* ---[ 0xa00: ITLB miss exception ]------------------------------------- */
   .org 0xa00
_itlb_miss_exception:
   UNHANDLED_EXCEPTION
   
      
/* ---[ 0xb00: Range exception ]----------------------------------------- */
   .org 0xb00
_range_exception:
   UNHANDLED_EXCEPTION
   

/* ---[ 0xc00: Syscall exception ]--------------------------------------- */
   .org 0xc00
_syscall_exception:
   l.addi   r1,r1,-4
   l.sw     0(r1),r3
   l.movhi  r3,hi(_Syscall)
   l.ori    r3,r3,lo(_Syscall)
   l.jr     r3
   l.nop    0
   

/* ---[ 0xd00: Trap exception ]------------------------------------------ */
   .org 0xd00
_trap_exception:
   UNHANDLED_EXCEPTION
   

/* ---[ 0xe00: Trap exception ]------------------------------------------ */
   .org 0xe00
_trap2_exception:
   UNHANDLED_EXCEPTION
   
   
/* ---[ 0xf00: Reserved exceptions ]------------------------------------- */
   .org 0xf00
_reserved0_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1000
_reserved1_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1100
_reserved2_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1200
_reserved3_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1300
_reserved4_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1400
_reserved5_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1500
_reserved6_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1600
_reserved7_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1700
_reserved8_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1800
_reserved9_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1900
_reserved10_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1a00
_reserved11_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1b00
_reserved12_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1c00
_reserved13_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1d00
_reserved14_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1e00
_reserved15_exception:
   UNHANDLED_EXCEPTION
   
   .org 0x1f00
_reserved16_exception:
   UNHANDLED_EXCEPTION

   /****************************************************************/
   /*                  Vector redefine                             */
   /*                                                              */
   /*Start from 0x01000000 to 0x01000080                           */
   /*                                                              */
   /****************************************************************/
   .section .vectors2, "ax"
   /*Timer Interrupt*/
   .org 0x0
_Reset:
   l.movhi  r2,hi(_start) 
   l.ori    r2,r2,lo(_start)
   l.jr     r2
   l.nop    0

   /*Timer Interrupt*/
   .org 0x20
_Timerint:
   l.movhi  r3,hi(_OSTickISR)
   l.ori    r3,r3,lo(_OSTickISR)
   l.jr     r3
   l.nop    0
   
   /*External Interrupt*/
   .org 0x40
_Extint:
   l.movhi  r3,hi(_ExtISR)
   l.ori    r3,r3,lo(_ExtISR)
   l.jr     r3
   l.nop    0
   
   /*System Call*/
   .org 0x60
_Syscall:
   l.movhi  r3,hi(_OSCtxSw)
   l.ori    r3,r3,lo(_OSCtxSw)
   l.jr     r3
   l.nop    0

/********** End of Vector Redefine ****/




/* ========================================================= [ entry ] === */
   .text
ENTRY(_start)
   //internal rom copy
   // +++ luslas_080620 : upper bound +++++++++++++++++++++
   l.movhi r1, 0x0200 // Data RAM address
   l.ori   r1, r1, 0x0
   l.movhi r7, 0xf10c // Data ROM address
   l.ori   r7, r7, 0xd000
   l.movhi r5, 0 // counter
   l.movhi r6, 0 // maximum counter (0x10000 = 256KB)
   l.ori   r6, r6, 0x2000 // maximum counter (0x2000 = 32KB)

_PROGRAM_COPY2:
   l.lwz   r3, 0(r7)
   l.sw    0(r1), r3

   l.addi  r7, r7, 4
   l.addi  r1, r1, 4

   l.addi  r5, r5, 1
   l.sfeq  r5, r6

   l.bnf _PROGRAM_COPY2
   // +++ luslas_080620 : lower bound +++++++++++++++++++++

   //internal ram copy
   // +++ luslas_080620 : upper bound +++++++++++++++++++++
   l.movhi r1, 0x0200 // Data RAM address
   l.ori   r1, r1, 0x8000
   l.movhi r7, 0xf10d // Data ROM address
   l.ori   r7, r7, 0x5000
   l.movhi r5, 0 // counter
   l.movhi r6, 0 // maximum counter (0x10000 = 256KB)
   l.ori   r6, r6, 0x0400 // maximum counter (0x0400 = 4KB)

_PROGRAM_COPY3:
   l.lwz   r3, 0(r7)
   l.sw    0(r1), r3

   l.addi  r7, r7, 4
   l.addi  r1, r1, 4

   l.addi  r5, r5, 1
   l.sfeq  r5, r6

   l.bnf _PROGRAM_COPY3
   // +++ luslas_080620 : lower bound +++++++++++++++++++++

   /* Initialize stack */
   LOAD_SYMBOL_2_GPR(r1, _stack)
   //l.addi  r2, r0, -3
   l.addi  r2, r0, -4
   l.and   r1, r1, r2
   

   // Clear BSS
   LOAD_SYMBOL_2_GPR(r28, ___bss_start)
   LOAD_SYMBOL_2_GPR(r30, __end)
1:
   l.sw    (0)(r28), r0
   l.addi  r28, r28, 4 //kik+
   l.sfltu r28, r30
   l.bf    1b
   l.nop

   /* Jump to main program entry point (argc = argv = 0) */
   CLEAR_GPR(r3)
   CLEAR_GPR(r4)
   l.jal   _main
   l.nop
   
   /* If program exits, call exit routine */
   l.addi  r3, r11, 0
   l.jal   __exit
   l.nop

   
/* ====================================== [ default exception handler ] === */

GLOBAL(default_exception_handler)
   l.sw    0x00(r1), r2
   l.sw    0x0c(r1), r5
   l.sw    0x10(r1), r6
   l.sw    0x14(r1), r7
   l.sw    0x18(r1), r8
   l.sw    0x1c(r1), r9
   l.sw    0x20(r1), r10
   l.sw    0x24(r1), r11
   l.sw    0x28(r1), r12
   l.sw    0x2c(r1), r13
   l.sw    0x30(r1), r14
   l.sw    0x34(r1), r15
   l.sw    0x38(r1), r16
   l.sw    0x3c(r1), r17
   l.sw    0x40(r1), r18
   l.sw    0x44(r1), r19
   l.sw    0x48(r1), r20
   l.sw    0x4c(r1), r21
   l.sw    0x50(r1), r22
   l.sw    0x54(r1), r23
   l.sw    0x58(r1), r24
   l.sw    0x5c(r1), r25
   l.sw    0x60(r1), r26
   l.sw    0x64(r1), r27
   l.sw    0x68(r1), r28
   l.sw    0x6c(r1), r29
   l.sw    0x70(r1), r30
   l.sw    0x74(r1), r31
   l.nop
   
   l.lwz    r2, 0x00(r1)
   l.lwz    r3, 0x04(r1)
   l.lwz    r4, 0x08(r1)
   l.lwz    r5, 0x0c(r1)
   l.lwz    r6, 0x10(r1)
   l.lwz    r7, 0x14(r1)
   l.lwz    r8, 0x18(r1)
   l.lwz    r9, 0x1c(r1)
   l.lwz    r10, 0x20(r1)
   l.lwz    r11, 0x24(r1)
   l.lwz    r12, 0x28(r1)
   l.lwz    r13, 0x2c(r1)
   l.lwz    r14, 0x30(r1)
   l.lwz    r15, 0x34(r1)
   l.lwz    r16, 0x38(r1)
   l.lwz    r17, 0x3c(r1)
   l.lwz    r18, 0x40(r1)
   l.lwz    r19, 0x44(r1)
   l.lwz    r20, 0x48(r1)
   l.lwz    r21, 0x4c(r1)
   l.lwz    r22, 0x50(r1)
   l.lwz    r23, 0x54(r1)
   l.lwz    r24, 0x58(r1)
   l.lwz    r25, 0x5c(r1)
   l.lwz    r26, 0x60(r1)
   l.lwz    r27, 0x64(r1)
   l.lwz    r28, 0x68(r1)
   l.lwz    r29, 0x6c(r1)
   l.lwz    r30, 0x70(r1)
   l.lwz    r31, 0x74(r1)
   l.addi  r1, r1, 128

   l.rfe
   l.nop

/* The end of image */
   .section .end_mark, "ax" 
   .word -1
