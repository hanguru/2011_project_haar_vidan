#define _ASSEMBLY
#include "or1200.h"

#define CONTEXT_SAVE \
	l.addi	r1,r1,-CONTEXTLEN;\
	l.sw	(CONTEXT_2)(r1),r2;\
	l.sw	(CONTEXT_3)(r1),r3;\
	l.sw	(CONTEXT_4)(r1),r4;\
	l.sw	(CONTEXT_5)(r1),r5;\
	l.sw	(CONTEXT_6)(r1),r6;\
	l.sw	(CONTEXT_7)(r1),r7;\
	l.sw	(CONTEXT_8)(r1),r8;\
	l.sw	(CONTEXT_9)(r1),r9;\
	l.sw	(CONTEXT_10)(r1),r10;\
	l.sw	(CONTEXT_11)(r1),r11;\
	l.sw	(CONTEXT_12)(r1),r12;\
	l.sw	(CONTEXT_13)(r1),r13;\
	l.sw	(CONTEXT_14)(r1),r14;\
	l.sw	(CONTEXT_15)(r1),r15;\
	l.sw	(CONTEXT_16)(r1),r16;\
	l.sw	(CONTEXT_17)(r1),r17;\
	l.sw	(CONTEXT_18)(r1),r18;\
	l.sw	(CONTEXT_19)(r1),r19;\
	l.sw	(CONTEXT_20)(r1),r20;\
	l.sw	(CONTEXT_21)(r1),r21;\
	l.sw	(CONTEXT_22)(r1),r22;\
	l.sw	(CONTEXT_23)(r1),r23;\
	l.sw	(CONTEXT_24)(r1),r24;\
	l.sw	(CONTEXT_25)(r1),r25;\
	l.sw	(CONTEXT_26)(r1),r26;\
	l.sw	(CONTEXT_27)(r1),r27;\
	l.sw	(CONTEXT_28)(r1),r28;\
	l.sw	(CONTEXT_29)(r1),r29;\
	l.sw	(CONTEXT_30)(r1),r30;\
	l.sw	(CONTEXT_31)(r1),r31;\
	l.mfspr	r3,r0,SPR_EPCR0;\
	l.sw	(CONTEXT_PC)(r1),r3;\
	l.mfspr	r3,r0,SPR_ESR0;\
	l.sw	(CONTEXT_SR)(r1),r3;\
	l.mfspr	r3,r0,SPR_EEAR0;\
	l.sw	(CONTEXT_EA)(r1),r3;

#define CONTEXT_RESTORE\
	l.lwz	r3,(CONTEXT_PC)(r1);\
	l.mtspr	r0,r3,SPR_EPCR0;\
	l.lwz	r3,(CONTEXT_SR)(r1);\
	l.mtspr	r0,r3,SPR_ESR0;\
	l.lwz	r3,(CONTEXT_EA)(r1);\
	l.mtspr	r0,r3,SPR_EEAR0;\
	l.lwz	r2,(CONTEXT_2)(r1);\
	l.lwz	r3,(CONTEXT_3)(r1);\
	l.lwz	r4,(CONTEXT_4)(r1);\
	l.lwz	r5,(CONTEXT_5)(r1);\
	l.lwz	r6,(CONTEXT_6)(r1);\
	l.lwz	r7,(CONTEXT_7)(r1);\
	l.lwz	r8,(CONTEXT_8)(r1);\
	l.lwz	r9,(CONTEXT_9)(r1);\
	l.lwz	r10,(CONTEXT_10)(r1);\
	l.lwz	r11,(CONTEXT_11)(r1);\
	l.lwz	r12,(CONTEXT_12)(r1);\
	l.lwz	r13,(CONTEXT_13)(r1);\
	l.lwz	r14,(CONTEXT_14)(r1);\
	l.lwz	r15,(CONTEXT_15)(r1);\
	l.lwz	r16,(CONTEXT_16)(r1);\
	l.lwz	r17,(CONTEXT_17)(r1);\
	l.lwz	r18,(CONTEXT_18)(r1);\
	l.lwz	r19,(CONTEXT_19)(r1);\
	l.lwz	r20,(CONTEXT_20)(r1);\
	l.lwz	r21,(CONTEXT_21)(r1);\
	l.lwz	r22,(CONTEXT_22)(r1);\
	l.lwz	r23,(CONTEXT_23)(r1);\
	l.lwz	r24,(CONTEXT_24)(r1);\
	l.lwz	r25,(CONTEXT_25)(r1);\
	l.lwz	r26,(CONTEXT_26)(r1);\
	l.lwz	r27,(CONTEXT_27)(r1);\
	l.lwz	r28,(CONTEXT_28)(r1);\
	l.lwz	r29,(CONTEXT_29)(r1);\
	l.lwz	r30,(CONTEXT_30)(r1);\
	l.lwz	r31,(CONTEXT_31)(r1);\
	l.addi	r1,r1,CONTEXTLEN;

.section .internalrom, "ax"
/**************************************
 * External Interrupt Service Routine *
 **************************************/
.globl _ExtISR;
_ExtISR:
	l.lwz	r3,0(r1)
	l.addi	r1,r1,4

	CONTEXT_SAVE

	l.movhi	r3,hi(_C_LABEL(OSTCBCur))	/* TCBCur->TCBStkPtr = SP */
	l.ori	r3,r3,lo(_C_LABEL(OSTCBCur))
	l.lwz	r4,0(r3)
	l.sw	0(r4),r1

	l.movhi	r3,hi(_C_LABEL(OSIntEnter))
	l.ori	r3,r3,lo(_C_LABEL(OSIntEnter))
	l.jalr	r3
	l.nop	0

   // Call Interrupt Handler
	l.movhi	r3,hi(_C_LABEL(IntHandler))
	l.ori	r3,r3,lo(_C_LABEL(IntHandler))
	l.jalr	r3
	l.nop	0
	l.movhi	r3,hi(_C_LABEL(OSIntExit))
	l.ori	r3,r3,lo(_C_LABEL(OSIntExit))
	l.jalr	r3
	l.nop	0

	CONTEXT_RESTORE
#ifdef OR1200
	l.csync
#endif
	l.rfe
	l.nop	0


