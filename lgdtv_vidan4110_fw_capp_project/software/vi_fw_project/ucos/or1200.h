/*
 * Copyright (c) 2005 Jared Momose.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef OR1200_H
#define OR1200_H

/*
 * Special Purpose Registers definitions
 */
#define SPR_VR		0x0000		/* Version */
#define SPR_UPR		0x0001		/* Unit Present */
#define SPR_CPUCFGR	0x0002		/* CPU Configuration */
#define SPR_DMMUCFGR	0x0003		/* Data MMU Configuration */
#define SPR_IMMUCFGR	0x0004		/* Inst MMU Configuration */
#define SPR_DCCFGR	0x0005		/* Data Cache Configuration */
#define SPR_ICCFGR	0x0006		/* Inst Cache Configuration */
#define SPR_DCFGR	0x0007		/* Debug Configuration */
#define SPR_PC		0x0010		/* PC mapped to SPR space */
#define SPR_SR		0x0011		/* Supervision */
#define   SR_SM		0x00000001
#define   SR_TEE	0x00000002
#define   SR_IEE	0x00000004
#define   SR_DCE	0x00000008
#define   SR_ICE	0x00000010
#define   SR_DME	0x00000020
#define   SR_IME	0x00000040
#define   SR_LEE	0x00000080
#define   SR_CE		0x00000100
#define   SR_F		0x00000200
#define   SR_CY		0x00000400
#define   SR_OV		0x00000800
#define   SR_OVE	0x00001000
#define   SR_DSX	0x00002000
#define   SR_EPH	0x00004000
#define   SR_FO		0x00008000
#define   SR_SUMRA	0x00010000
#define   SR_CID(x)	((x)<<28)
#define   SR_CIDMASK	0xf0000000
#define SPR_EPCR0	0x0020		/* Exception PC */
#define SPR_EEAR0	0x0030		/* Exception EA */
#define SPR_ESR0	0x0040		/* Exception SR */
#define SPR_GPR(n)	(0x0400+(n))	/* GPRs mapped to SPR space */
#define SPR_DTLBEIR	0x0802		/* Data TLB Entry Invalidate */
#define SPR_ITLBEIR	0x1002		/* Inst TLB Entry Invalidate */
#define SPR_DTLBW0MR(n)	(0x0a00+(n))	/* Data TLB Match s Way 0 */
#define SPR_ITLBW0MR(n)	(0x1200+(n))	/* Inst TLB Match s Way 0 */
#define   TLBWnMR_V		0x00000001
#define   TLBWnMR_PL1		0x00000002
#define   TLBWnMR_CID(x)	((x)<<2)
#define   TLBWnMR_LRU(x)	((x)<<6)
#define   TLBWnMR_VPNMASK	0xfffff000
#define SPR_DTLBW0TR(n)	(0x0a80+(n))	/* Data TLB Translate s Way 0 */
#define SPR_ITLBW0TR(n)	(0x1280+(n))	/* Inst TLB Translate s Way 0 */
#define   TLBWnTR_CC		0x00000001
#define   TLBWnTR_CI		0x00000002
#define   TLBWnTR_WBC		0x00000004
#define   TLBWnTR_WOM		0x00000008
#define   TLBWnTR_A		0x00000010
#define   TLBWnTR_D		0x00000020
#define   DTLBWnTR_URE		0x00000040
#define   DTLBWnTR_UWE		0x00000080
#define   DTLBWnTR_SRE		0x00000100
#define   DTLBWnTR_SWE		0x00000200
#define   ITLBWnTR_SXE		0x00000040
#define   ITLBWnTR_UXE		0x00000080
#define   TLBWnTR_PPNMASK	0xfffff000
#define SPR_DCCR	0x1800		/* DC Control */
#define SPR_DCBIR	0x1801		/* DC Block Invalidate */
#define SPR_DCBFR	0x1901		/* DC Block Flush */
#define SPR_ICCR	0x2000		/* IC Control */
#define SPR_ICBIR	0x2100		/* IC Block Invalidate */
#define SPR_MACLO	0x2900		/* MAC Low */
#define SPR_MACHI	0x2901		/* MAC High */
#define SPR_DMR1	0x3010		/* Debug Mode 1 */
#define SPR_DMR2	0x3011		/* Debug Mode 2 */
#define SPR_DSR		0x3014		/* Debug Stop */
#define SPR_DRR		0x3015		/* Debug Reason */
#define SPR_PMR		0x4000		/* Power Management */
//#define SPR_PICMR	0x4801		/* PIC Mask */
//#define SPR_PICPR	0x4802		/* PIC Priority */ 
//#define SPR_PICSR	0x4803		/* PIC Status */
#define SPR_PICMR	0x4800		/* PIC Mask */
#define SPR_PICPR	0x4801		/* PIC Priority */ 
#define SPR_PICSR	0x4802		/* PIC Status */
#define SPR_TTMR	0x5000		/* Tick Timer Mode */
#define   TTMR_MMASK		0xc0000000
#define   TTMR_M(x)		((x)<<30)
#define   TTMR_IE		0x20000000
#define   TTMR_IP		0x10000000
#define   TTMR_TPMASK		0x0fffffff
#define SPR_TTCR	0x5001		/* Tick Timer Count */

/*
 * Exception addresses
 */
#define EXC_RST		0x100	/* Reset */
#define EXC_BERR	0x200	/* Bus error */
#define EXC_DPF		0x300	/* Data page fault */
#define EXC_IPF		0x400	/* Instruction page fault */
#define EXC_TT		0x500	/* Tick timer interrupt */
#define EXC_ALI		0x600	/* Alignment */
#define EXC_INST	0x700	/* Illegal instruction */
#define EXC_EXI		0x800	/* External interrupt */
#define EXC_DTMISS	0x900	/* Data TLB miss */
#define EXC_ITMISS	0xa00	/* Instruction TLB miss */
#define EXC_SC		0xc00	/* System call */
#define EXC_BRK		0xd00	/* Breakpoint */
#define EXC_TRAP	0xe00	/* Trap */

/*
 * Context layout
 */
#define CONTEXT_2	0
#define CONTEXT_3	4
#define CONTEXT_4	8
#define CONTEXT_5	12
#define CONTEXT_6	16
#define CONTEXT_7	20
#define CONTEXT_8	24
#define CONTEXT_9	28
#define CONTEXT_10	32
#define CONTEXT_11	36
#define CONTEXT_12	40
#define CONTEXT_13	44
#define CONTEXT_14	48
#define CONTEXT_15	52
#define CONTEXT_16	56
#define CONTEXT_17	60
#define CONTEXT_18	64
#define CONTEXT_19	68
#define CONTEXT_20	72
#define CONTEXT_21	76
#define CONTEXT_22	80
#define CONTEXT_23	84
#define CONTEXT_24	88
#define CONTEXT_25	92
#define CONTEXT_26	96
#define CONTEXT_27	100
#define CONTEXT_28	104
#define CONTEXT_29	108
#define CONTEXT_30	112
#define CONTEXT_31	116
#define CONTEXT_PC	120
#define CONTEXT_SR	124
#define CONTEXT_EA	128
#define CONTEXTLEN	132

//#define IC_LINE		0x10
//#define DC_LINE		0x10
//#define IC_SIZE		0x2000
//#define DC_SIZE		0x2000

#define _C_LABEL(x) \
	_ ## x
#define ENTRY(x) \
	.text; .align 4; .globl _ ## x; .type _ ## x,@function; _ ## x

#ifndef _ASSEMBLY

#define mtspr(reg, val) \
	__asm __volatile("l.mtspr %0,%1,0" : : "r"(reg), "r"(val))
#define mfspr(reg) \
	( { \
		unsigned int val; \
		__asm __volatile("l.mfspr %0,%1,0" : "=r"(val) : "r"(reg)); \
		val; \
	} )

//void *	memcpy(void *dst, const void *src, unsigned int len);
//void *	memset(void *b, int c, unsigned int len);

#endif /* _ASSEMBLY */

#endif /* OR1200_H */
