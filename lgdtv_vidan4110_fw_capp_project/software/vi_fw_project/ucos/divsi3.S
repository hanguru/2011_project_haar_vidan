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

#define _ASSEMBLY
#include "or1200.h"


#define NORMALIZE(rnum,rden,rnnum,rnden)\
	l.sfges	rnum,r0;\
	l.bf	1f;\
	l.addi	rnnum,r0,0;\
	l.sub	rnum,r0,rnum;\
	l.addi	rnnum,r0,1;\
1:	l.sfges	rden,r0;\
	l.bf	2f;\
	l.addi	rnden,r0,0;\
	l.sub	rden,r0,rden;\
	l.addi	rnden,r0,1;\
2:

#define UNNORMALIZE(rres,rneg)\
	l.sfeq	rneg,r0;\
	l.bf	1f;\
	l.nop	0;\
	l.sub	rres,r0,rres;\
1:

#ifdef OR1200
#define SHIFTNUM(rnum,rden,rbit,rtmp)\
	l.addi	rbit,r0,1;\
	l.movhi	rtmp,0x8000;\
1:	l.sfgeu	rden,rtmp;\
	l.bf	2f;\
	l.nop	0;\
	l.sfgeu	rden,rnum;\
	l.bf	2f;\
	l.nop	0;\
	l.slli	rden,rden,1;\
	l.j	1b;\
	l.slli	rbit,rbit,1;\
2:
#endif

#ifdef BA22
#define SHIFTNUM(rnum,rden,rbit,rtmp)\
	l.addi	rbit,r0,1;\
	l.movhi	rtmp,0x8000;\
1:	l.sfgeu	rden,rtmp;\
	l.bf	2f;\
	l.nop	0;\
	l.sfgeu	rden,rnum;\
	l.bf	2f;\
	l.nop	0;\
	l.slli	rden,rden,1;\
	l.slli	rbit,rbit,1;\
	l.j	1b;\
2:
#endif



#define DIVIDE(rnum,rden,rbit,rres)\
	l.addi	rres,r0,0;\
1:	l.sfgtu	rden,rnum;\
	l.bf	2f;\
	l.nop	0;\
	l.sub	rnum,rnum,rden;\
	l.add	rres,rres,rbit;\
2:	l.srli	rden,rden,1;\
	l.srli	rbit,rbit,1;\
	l.sfne	rbit,r0;\
	l.bf	1b;\
	l.nop	0

#define DIVBYZERO(rden)\
	l.sfeq	rden,r0;\
	l.bf	_C_LABEL(__divbyzero);\
	l.nop	0

.section .internalrom, "ax"

.globl _modsi3;
_modsi3:
	DIVBYZERO(r4)
	NORMALIZE(r3,r4,r5,r6)
	SHIFTNUM(r3,r4,r6,r7)
	DIVIDE(r3,r4,r6,r11)
	l.add	r11,r0,r3
	UNNORMALIZE(r11,r5)
	l.jr	r9
	l.nop	0

.globl _divsi3;
_divsi3:
	DIVBYZERO(r4)
	NORMALIZE(r3,r4,r5,r6)
	l.xor	r5,r5,r6
	SHIFTNUM(r3,r4,r6,r7)
	DIVIDE(r3,r4,r6,r11)
	UNNORMALIZE(r11,r5)
	l.jr	r9
	l.nop	0

.globl _umodsi3;
_umodsi3:
	DIVBYZERO(r4)
	SHIFTNUM(r3,r4,r6,r7)
	DIVIDE(r3,r4,r6,r11)
	l.add	r11,r0,r3
	l.jr	r9
	l.nop	0

.globl _udivsi3;
_udivsi3:
	DIVBYZERO(r4)
	SHIFTNUM(r3,r4,r6,r7)
	DIVIDE(r3,r4,r6,r11)
	l.jr	r9
	l.nop	0

	/*
	 * This vector is called when a divide by zero exception
	 * occures. Appropriate action must be taken by the operating
	 * system to accomodate this exceptions. This default handler
	 * will simply set the result to zero.
	 */
.globl ___divbyzero;
___divbyzero:
	l.addi	r11,r0,0
	l.jr	r9
	l.nop	0

