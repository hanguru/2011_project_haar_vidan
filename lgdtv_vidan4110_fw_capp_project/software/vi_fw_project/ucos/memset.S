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

.section .internalrom, "ax"

_memset:
	l.sfltui r5,4
	l.bf	Ltail
	l.addi	r11,r3,0
Lhead:
	l.andi	r6,r3,3
	l.sfeq	r6,r0
	l.bf	Ldup
	l.nop	0		/* delay slot */
	l.sb	0(r3),r4
	l.addi	r3,r3,1
#ifdef OR1200
	l.j	Lhead
#endif
	l.addi	r5,r5,-1	/* delay slot */
#ifdef BA22
	l.j	Lhead
#endif
Ldup:
	l.andi	r4,r4,255
	l.slli	r6,r4,8
	l.or	r4,r4,r6
	l.slli	r6,r4,16
	l.or	r4,r4,r6
Lbody:
	l.sfltui r5,4
	l.bf	Ltail
	l.nop	0		/* delay slot */
	l.sw	0(r3),r4
	l.addi	r3,r3,4
#ifdef OR1200
	l.j	Lbody
#endif
	l.addi	r5,r5,-4	/* delay slot */
#ifdef BA22
	l.j	Lbody
#endif
Ltail:
	l.sfeq	r5,r0
	l.bf	Lend
	l.nop	0		/* delay slot */
	l.sb	0(r3),r4
	l.addi	r3,r3,1
#ifdef OR1200
	l.j	Ltail
#endif
	l.addi	r5,r5,-1	/* delay slot */
#ifdef BA22
	l.j	Ltail
#endif
Lend:
	l.jr	r9
	l.nop	0

