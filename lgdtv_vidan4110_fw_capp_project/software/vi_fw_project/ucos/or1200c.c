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

#include <ucos_ii.h>
#include <string.h>

void OSInitHookBegin(void) {
	//extern INT32U TT_VEC, TT_VEC_SIZE;
	//extern INT32U SC_VEC, SC_VEC_SIZE;
	//extern INT32U NULL_VEC, NULL_VEC_SIZE;
	//memcpy((void *) EXC_TT, &TT_VEC, (INT32U) &TT_VEC_SIZE);
	//memcpy((void *) EXC_SC, &SC_VEC, (INT32U) &SC_VEC_SIZE);
	//memcpy((void *) EXC_BERR, &NULL_VEC, (INT32U) &NULL_VEC_SIZE);
}

OS_STK *
OSTaskStkInit(void(*task)(void *pd), void *pdata, OS_STK *ptos, INT16U opt) {
	INT8U *sp;

	/* The stack pointer for 32-bit implementations must be aligned
	 * on a 4 byte boundary.
	 */
	sp = (INT8U *) ((INT32U) ptos & 0xfffffff8);
	sp -= 4;

	/* Push a context onto the stack that reflects the initial state
	 * of a task. Our stack pointer (CONTEXT_1) is not stored on the
	 * stack but rather returned by this function.
	 */
	sp -= CONTEXTLEN;
	memset(sp, 0, CONTEXTLEN);
	*(INT32U *) (sp + CONTEXT_3) = (INT32U) pdata;
	//*(INT32U *)(sp + CONTEXT_SR) = mfspr(SPR_SR)|SR_TEE|SR_IEE; //jykim_080730_default_interrupt_disable--
	*(INT32U *) (sp + CONTEXT_SR) = mfspr(SPR_SR); //jykim_080730_default_interrupt_disable++
	*(INT32U *) (sp + CONTEXT_PC) = (INT32U) task;

	return (OS_STK *) (sp);
}

void OSTaskIdleHook(void) {
	/* Do nothing... */
}

void OSTimeTickHook(void) {
	//Interrupt Src Clear
	mtspr(SPR_TTMR, (mfspr(SPR_TTMR) & ~TTMR_IP));
}

void OSInitHookEnd(void) {
	/* Do nothing... */
}

void OSDebugInit(void) {
	/* Do nothing... */
}

void OSTaskStatHook(void) {
}

void OSTaskCreateHook(OS_TCB *ptcb) {
	/* Do nothing... */
}

void OSTaskDelHook(OS_TCB *ptcb) {
	/* Do nothing... */
}

void OSTCBInitHook(OS_TCB *ptcb) {
	/* Do nothing... */
}
