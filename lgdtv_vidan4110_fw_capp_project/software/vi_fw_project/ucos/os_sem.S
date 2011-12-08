	.file	"os_sem.c"
	.stabs	"/home/hanguru/2011_project_original/lgdtv_vidan4110_fw_capp_project/software/vi_fw_project/",100,0,2,.Ltext0
	.stabs	"ucos/os_sem.c",100,0,2,.Ltext0
.section .internalrom, "ax"
.Ltext0:
	.stabs	"gcc2_compiled.",60,0,0,0
	.stabs	"int:t(0,1)=r(0,1);-2147483648;2147483647;",128,0,0,0
	.stabs	"char:t(0,2)=r(0,2);0;127;",128,0,0,0
	.stabs	"long int:t(0,3)=r(0,3);-2147483648;2147483647;",128,0,0,0
	.stabs	"unsigned int:t(0,4)=r(0,4);0;037777777777;",128,0,0,0
	.stabs	"long unsigned int:t(0,5)=r(0,5);0;037777777777;",128,0,0,0
	.stabs	"long long int:t(0,6)=@s64;r(0,6);01000000000000000000000;0777777777777777777777;",128,0,0,0
	.stabs	"long long unsigned int:t(0,7)=@s64;r(0,7);0;01777777777777777777777;",128,0,0,0
	.stabs	"short int:t(0,8)=@s16;r(0,8);-32768;32767;",128,0,0,0
	.stabs	"short unsigned int:t(0,9)=@s16;r(0,9);0;65535;",128,0,0,0
	.stabs	"signed char:t(0,10)=@s8;r(0,10);-128;127;",128,0,0,0
	.stabs	"unsigned char:t(0,11)=@s8;r(0,11);0;255;",128,0,0,0
	.stabs	"float:t(0,12)=r(0,1);4;0;",128,0,0,0
	.stabs	"double:t(0,13)=r(0,1);8;0;",128,0,0,0
	.stabs	"long double:t(0,14)=r(0,1);8;0;",128,0,0,0
	.stabs	"void:t(0,15)=(0,15)",128,0,0,0
	.stabs	"ucos/ucos_ii.h",130,0,0,0
	.stabs	"ucos/os_cpu.h",130,0,0,0
	.stabs	"BOOLEAN:t(2,1)=(0,11)",128,0,9,0
	.stabs	"INT8U:t(2,2)=(0,11)",128,0,10,0
	.stabs	"INT8S:t(2,3)=(0,2)",128,0,11,0
	.stabs	"INT16U:t(2,4)=(0,9)",128,0,12,0
	.stabs	"INT16S:t(2,5)=(0,8)",128,0,13,0
	.stabs	"INT32U:t(2,6)=(0,5)",128,0,14,0
	.stabs	"INT32S:t(2,7)=(0,3)",128,0,15,0
	.stabs	"VBOOLEAN:t(2,8)=(2,9)=B(0,11)",128,0,16,0
	.stabs	"OS_STK:t(2,10)=(0,4)",128,0,17,0
	.stabs	"OS_CPU_SR:t(2,11)=(0,4)",128,0,18,0
	.stabn	162,0,0,0
	.stabs	"ucos/os_cfg.h",130,0,0,0
	.stabs	"OS_FLAGS:t(3,1)=(2,4)",128,0,112,0
	.stabn	162,0,0,0
	.stabs	"os_event:T(1,1)=s44OSEventType:(2,2),0,8;OSEventGrp:(2,2),8,8;OSEventCnt:(2,4),16,16;OSEventPtr:(1,2)=*(0,15),32,32;OSEventTbl:(1,3)=ar(1,4)=r(1,4);0;037777777777;;0;0;(2,2),64,8;OSEventName:(1,5)=ar(1,4);0;31;(0,2),72,256;;",128,0,0,0
	.stabs	"OS_EVENT:t(1,6)=(1,1)",128,0,257,0
	.stabs	"os_sem_data:T(1,7)=s4OSCnt:(2,4),0,16;OSEventTbl:(1,3),16,8;OSEventGrp:(2,2),24,8;;",128,0,0,0
	.stabs	"OS_SEM_DATA:t(1,8)=(1,7)",128,0,387,0
	.stabs	"os_stk_data:T(1,9)=s8OSFree:(2,6),0,32;OSUsed:(2,6),32,32;;",128,0,0,0
	.stabs	"OS_STK_DATA:t(1,10)=(1,9)",128,0,400,0
	.stabs	"os_tcb:T(1,11)=s96OSTCBStkPtr:(1,12)=*(2,10),0,32;OSTCBExtPtr:(1,2),32,32;OSTCBStkBottom:(1,12),64,32;OSTCBStkSize:(2,6),96,32;OSTCBOpt:(2,4),128,16;OSTCBId:(2,4),144,16;OSTCBNext:(1,13)=*(1,11),160,32;OSTCBPrev:(1,13),192,32;OSTCBEventPtr:(1,14)=*(1,6),224,32;OSTCBDly:(2,4),256,16;OSTCBStat:(2,2),272,8;OSTCBPendTO:(2,1),280,8;OSTCBPrio:(2,2),288,8;OSTCBX:(2,2),296,8;OSTCBY:(2,2),304,8;OSTCBBitX:(2,2),312,8;OSTCBBitY:(2,2),320,8;OSTCBDelReq:(2,2),328,8;OSTCBCtxSwCtr:(2,6),352,32;OSTCBCyclesTot:(2,6),384,32;OSTCBCyclesStart:(2,6),416,32;OSTCBStkBase:(1,12),448,32;OSTCBStkUsed:(2,6),480,32;OSTCBTaskName:(1,5),512,256;;",128,0,0,0
	.stabs	"OS_TCB:t(1,15)=(1,11)",128,0,464,0
	.stabn	162,0,0,0
.proc _OSSemAccept
	.stabs	"OSSemAccept:F(2,4)",36,0,41,_OSSemAccept
	.stabs	"pevent:P(1,14)",64,0,40,3
	.global _OSSemAccept
	.type	_OSSemAccept, @function
_OSSemAccept:
	.stabd	46,0,0
	.stabn	68,0,41,.LM0-.LFBB1
.LM0:
.LFBB1:
	.stabn	68,0,49,.LM1-.LFBB1
.LM1:
	b.beqi  	r3,0,.L2
	.stabn	68,0,53,.LM2-.LFBB1
.LM2:
	b.lbz   	r7,0(r3)
	b.bnei  	r7,3,.L2
.LBB2:
	.stabn	68,0,56,.LM3-.LFBB1
.LM3:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE2:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,57,.LM4-.LFBB1
.LM4:
	b.lhz   	r6,2(r3)
	.stabn	68,0,58,.LM5-.LFBB1
.LM5:
	b.beqi  	r6,0,.L5
	.stabn	68,0,59,.LM6-.LFBB1
.LM6:
	b.addi  	r7,r6,-1
	b.sh    	2(r3),r7	   # movhi store
.L5:
	.stabn	68,0,61,.LM7-.LFBB1
.LM7:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	.stabn	68,0,62,.LM8-.LFBB1
.LM8:
	b.mov  	r3,r6	     # movsi
	b.j    	.L7
.L2:
	b.movi 	r3,0	     # movsi imm P
.L7:
	.stabn	68,0,63,.LM9-.LFBB1
.LM9:
	b.jr    	r9
	.size	_OSSemAccept, .-_OSSemAccept
	.stabs	"cnt:r(2,4)",64,0,42,6
	.stabn	192,0,0,.LFBB1-.LFBB1
	.stabs	"val:r(0,4)",64,0,56,5
	.stabn	192,0,0,.LBB2-.LFBB1
	.stabn	224,0,0,.LBE2-.LFBB1
	.stabn	224,0,0,.Lscope1-.LFBB1
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
.proc _OSSemQuery
	.stabs	"OSSemQuery:F(2,2)",36,0,375,_OSSemQuery
	.stabs	"pevent:P(1,14)",64,0,374,23
	.stabs	"p_sem_data:P(0,16)=*(1,8)",64,0,374,4
	.global _OSSemQuery
	.type	_OSSemQuery, @function
_OSSemQuery:
	.stabd	46,0,0
	.stabn	68,0,375,.LM10-.LFBB2
.LM10:
.LFBB2:
	b.mov  	r23,r3	     # movsi
	.stabn	68,0,384,.LM11-.LFBB2
.LM11:
	b.movi 	r3,4	     # movsi imm P
	b.beqi  	r23,0,.L12
	.stabn	68,0,388,.LM12-.LFBB2
.LM12:
	b.lbz   	r7,0(r23)
	b.movi 	r3,1	     # movsi imm P
	b.bnei  	r7,3,.L12
.LBB3:
	.stabn	68,0,391,.LM13-.LFBB2
.LM13:
	b.ori  	r5,r0,17	  # movsi imm J
	l.mfspr r5,r5,0
.LBE3:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,392,.LM14-.LFBB2
.LM14:
	b.lbz   	r7,1(r23)
	b.sb    	3(r4),r7	   # movqi store
	.stabn	68,0,396,.LM15-.LFBB2
.LM15:
	b.lbz   	r7,8(r23)
	b.sb    	2(r4),r7	   # movqi store
	.stabn	68,0,426,.LM16-.LFBB2
.LM16:
	b.lhz   	r7,2(r23)
	b.sh    	0(r4),r7	   # movhi store
	.stabn	68,0,427,.LM17-.LFBB2
.LM17:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	b.movi 	r3,0	     # movsi imm P
.L12:
	.stabn	68,0,429,.LM18-.LFBB2
.LM18:
	b.jr    	r9
	.size	_OSSemQuery, .-_OSSemQuery
	.stabs	"val:r(0,4)",64,0,391,5
	.stabn	192,0,0,.LBB3-.LFBB2
	.stabn	224,0,0,.LBE3-.LFBB2
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
.proc _OSSemSet
	.stabs	"OSSemSet:F(0,15)",36,0,458,_OSSemSet
	.stabs	"pevent:P(1,14)",64,0,457,3
	.stabs	"cnt:P(2,4)",64,0,457,4
	.stabs	"err:P(0,17)=*(2,2)",64,0,457,5
	.global _OSSemSet
	.type	_OSSemSet, @function
_OSSemSet:
	.stabd	46,0,0
	.stabn	68,0,458,.LM19-.LFBB3
.LM19:
.LFBB3:
	.stabn	68,0,465,.LM20-.LFBB3
.LM20:
	b.bnei  	r3,0,.L17
	.stabn	68,0,466,.LM21-.LFBB3
.LM21:
	b.movi  	r7,4	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L26
.L17:
	.stabn	68,0,470,.LM22-.LFBB3
.LM22:
	b.lbz   	r7,0(r3)
	b.beqi  	r7,3,.L20
	.stabn	68,0,471,.LM23-.LFBB3
.LM23:
	b.movi  	r7,1	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L26
.L20:
.LBB4:
	.stabn	68,0,474,.LM24-.LFBB3
.LM24:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r23,r7,0
.LBE4:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r23,-7
	l.mtspr r6,r7,0
	.stabn	68,0,475,.LM25-.LFBB3
.LM25:
	b.lhz   	r7,2(r3)
	b.beqi  	r7,0,.L22
	.stabn	68,0,476,.LM26-.LFBB3
.LM26:
	b.sh    	2(r3),r4	   # movhi store
	b.j    	.L24
.L22:
	.stabn	68,0,478,.LM27-.LFBB3
.LM27:
	b.lbz   	r7,1(r3)
	b.bnei  	r7,0,.L24
	.stabn	68,0,479,.LM28-.LFBB3
.LM28:
	b.sh    	2(r3),r4	   # movhi store
.L24:
	.stabn	68,0,482,.LM29-.LFBB3
.LM29:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r23,0
	.stabn	68,0,483,.LM30-.LFBB3
.LM30:
	b.sb    	0(r5),r0	   # movqi store
.L26:
	.stabn	68,0,484,.LM31-.LFBB3
.LM31:
	b.jr    	r9
	.size	_OSSemSet, .-_OSSemSet
	.stabs	"val:r(0,4)",64,0,474,23
	.stabn	192,0,0,.LBB4-.LFBB3
	.stabn	224,0,0,.LBE4-.LFBB3
.Lscope3:
	.stabs	"",36,0,0,.Lscope3-.LFBB3
	.stabd	78,0,0
.proc _OSSemPost
	.stabs	"OSSemPost:F(2,2)",36,0,325,_OSSemPost
	.stabs	"pevent:P(1,14)",64,0,324,3
	.global _OSSemPost
	.type	_OSSemPost, @function
_OSSemPost:
	.stabd	46,0,0
	.stabn	68,0,325,.LM32-.LFBB4
.LM32:
.LFBB4:
	b.entri 	2,0
	.stabn	68,0,332,.LM33-.LFBB4
.LM33:
	b.movi 	r6,4	     # movsi imm P
	b.beqi  	r3,0,.L30
	.stabn	68,0,336,.LM34-.LFBB4
.LM34:
	b.lbz   	r7,0(r3)
	b.movi 	r6,1	     # movsi imm P
	b.bnei  	r7,3,.L30
.LBB5:
	.stabn	68,0,339,.LM35-.LFBB4
.LM35:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r10,r7,0
.LBE5:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r10,-7
	l.mtspr r6,r7,0
	.stabn	68,0,340,.LM36-.LFBB4
.LM36:
	b.lbz   	r7,1(r3)
	b.beqi  	r7,0,.L33
	.stabn	68,0,341,.LM37-.LFBB4
.LM37:
	b.movi 	r4,0	     # movsi imm P
	b.movi 	r5,1	     # movsi imm P
	b.jal  	_OS_EventTaskRdy
	.stabn	68,0,342,.LM38-.LFBB4
.LM38:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	.stabn	68,0,343,.LM39-.LFBB4
.LM39:
	b.jal  	_OS_Sched
	b.movi 	r6,0	     # movsi imm P
	b.j    	.L30
.L33:
	.stabn	68,0,346,.LM40-.LFBB4
.LM40:
	b.lhz   	r7,2(r3)
	b.ori  	r6,r0,65535	  # movsi imm i
	b.beq   	r7,r6,.L35
	.stabn	68,0,347,.LM41-.LFBB4
.LM41:
	b.addi  	r7,r7,1
	b.sh    	2(r3),r7	   # movhi store
	.stabn	68,0,348,.LM42-.LFBB4
.LM42:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	b.movi 	r6,0	     # movsi imm P
	b.j    	.L30
.L35:
	.stabn	68,0,351,.LM43-.LFBB4
.LM43:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r10,0
	b.ori  	r6,r0,50	  # movsi imm J
.L30:
	.stabn	68,0,353,.LM44-.LFBB4
.LM44:
	b.mov  	r3,r6	     # movsi
	b.reti  	2,0
	.size	_OSSemPost, .-_OSSemPost
	.stabs	"val:r(0,4)",64,0,339,10
	.stabn	192,0,0,.LBB5-.LFBB4
	.stabn	224,0,0,.LBE5-.LFBB4
.Lscope4:
	.stabs	"",36,0,0,.Lscope4-.LFBB4
	.stabd	78,0,0
.proc _OSSemDel
	.stabs	"OSSemDel:F(1,14)",36,0,154,_OSSemDel
	.stabs	"pevent:P(1,14)",64,0,153,10
	.stabs	"opt:P(2,2)",64,0,153,4
	.stabs	"err:P(0,17)",64,0,153,11
	.global _OSSemDel
	.type	_OSSemDel, @function
_OSSemDel:
	.stabd	46,0,0
	.stabn	68,0,154,.LM45-.LFBB5
.LM45:
.LFBB5:
	b.entri 	5,0
	b.mov  	r10,r3	     # movsi
	b.mov  	r11,r5	     # movsi
	.stabn	68,0,161,.LM46-.LFBB5
.LM46:
	bw.lbz   	r7,(_OSIntNesting)(r0)
	b.beqi  	r7,0,.L39
	.stabn	68,0,162,.LM47-.LFBB5
.LM47:
	b.addi  	r7,r0,-116	 # movqi imm N
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L41
.L39:
	.stabn	68,0,166,.LM48-.LFBB5
.LM48:
	b.bnei  	r3,0,.L42
	.stabn	68,0,167,.LM49-.LFBB5
.LM49:
	b.movi  	r7,4	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L41
.L42:
	.stabn	68,0,171,.LM50-.LFBB5
.LM50:
	b.lbz   	r7,0(r3)
	b.beqi  	r7,3,.L44
	.stabn	68,0,172,.LM51-.LFBB5
.LM51:
	b.movi  	r7,1	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L41
.L44:
.LBB6:
	.stabn	68,0,175,.LM52-.LFBB5
.LM52:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r12,r7,0
.LBE6:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r12,-7
	l.mtspr r6,r7,0
	b.lbz   	r7,1(r3)
	b.sfeqi 	r7,0
	b.movi  	r7,1	    # movqi imm P
	b.cmov  	r7,r0,r7
	b.extbz 	r13,r7
	.stabn	68,0,181,.LM53-.LFBB5
.LM53:
	b.beqi  	r4,0,.L48
	b.bnei  	r4,1,.L47
	.stabn	68,0,202,.LM54-.LFBB5
.LM54:
	b.bnei  	r13,0,.L57
	b.j    	.L51
.L48:
	.stabn	68,0,183,.LM55-.LFBB5
.LM55:
	b.bnei  	r13,0,.L52
	.stabn	68,0,185,.LM56-.LFBB5
.LM56:
	b.ori   	r7,r0,63	 # movqi imm J
	b.sb    	9(r3),r7	   # movqi store
	.stabn	68,0,186,.LM57-.LFBB5
.LM57:
	b.sb    	10(r3),r0	   # movqi store
	.stabn	68,0,188,.LM58-.LFBB5
.LM58:
	b.sb    	0(r3),r0	   # movqi store
	.stabn	68,0,189,.LM59-.LFBB5
.LM59:
	bw.lwz   	r7,(_OSEventFreeList)(r0)	    # movsi load
	b.sw    	4(r3),r7	   # movsi store
	.stabn	68,0,190,.LM60-.LFBB5
.LM60:
	b.sh    	2(r3),r0	   # movhi store
	.stabn	68,0,191,.LM61-.LFBB5
.LM61:
	bw.sw    	(_OSEventFreeList)(r0),r3	   # movsi store
	.stabn	68,0,192,.LM62-.LFBB5
.LM62:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r12,0
	.stabn	68,0,193,.LM63-.LFBB5
.LM63:
	b.sb    	0(r5),r0	   # movqi store
	b.movi 	r10,0	     # movsi imm P
	b.j    	.L41
.L52:
	.stabn	68,0,196,.LM64-.LFBB5
.LM64:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r12,0
	.stabn	68,0,197,.LM65-.LFBB5
.LM65:
	b.ori   	r7,r0,8	 # movqi imm J
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L41
.L57:
	.stabn	68,0,203,.LM66-.LFBB5
.LM66:
	b.mov  	r3,r10	     # movsi
	b.movi 	r4,0	     # movsi imm P
	b.movi 	r5,1	     # movsi imm P
	b.jal  	_OS_EventTaskRdy
	.stabn	68,0,202,.LM67-.LFBB5
.LM67:
	b.lbz   	r7,1(r10)
	b.bnei  	r7,0,.L57
.L51:
	.stabn	68,0,206,.LM68-.LFBB5
.LM68:
	b.ori   	r7,r0,63	 # movqi imm J
	b.sb    	9(r10),r7	   # movqi store
	.stabn	68,0,207,.LM69-.LFBB5
.LM69:
	b.sb    	10(r10),r0	   # movqi store
	.stabn	68,0,209,.LM70-.LFBB5
.LM70:
	b.sb    	0(r10),r0	   # movqi store
	.stabn	68,0,210,.LM71-.LFBB5
.LM71:
	bw.lwz   	r7,(_OSEventFreeList)(r0)	    # movsi load
	b.sw    	4(r10),r7	   # movsi store
	.stabn	68,0,211,.LM72-.LFBB5
.LM72:
	b.sh    	2(r10),r0	   # movhi store
	.stabn	68,0,212,.LM73-.LFBB5
.LM73:
	bw.sw    	(_OSEventFreeList)(r0),r10	   # movsi store
	.stabn	68,0,213,.LM74-.LFBB5
.LM74:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r12,0
	.stabn	68,0,214,.LM75-.LFBB5
.LM75:
	b.beqi  	r13,0,.L54
	.stabn	68,0,215,.LM76-.LFBB5
.LM76:
	b.jal  	_OS_Sched
.L54:
	.stabn	68,0,217,.LM77-.LFBB5
.LM77:
	b.sb    	0(r11),r0	   # movqi store
	b.movi 	r10,0	     # movsi imm P
	b.j    	.L41
.L47:
	.stabn	68,0,221,.LM78-.LFBB5
.LM78:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r12,0
	.stabn	68,0,222,.LM79-.LFBB5
.LM79:
	b.movi  	r7,7	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
.L41:
	.stabn	68,0,225,.LM80-.LFBB5
.LM80:
	b.mov  	r3,r10	     # movsi
	b.reti  	5,0
	.size	_OSSemDel, .-_OSSemDel
	.stabs	"val:r(0,4)",64,0,175,12
	.stabn	192,0,0,.LBB6-.LFBB5
	.stabn	224,0,0,.LBE6-.LFBB5
.Lscope5:
	.stabs	"",36,0,0,.Lscope5-.LFBB5
	.stabd	78,0,0
.proc _OSSemPend
	.stabs	"OSSemPend:F(0,15)",36,0,260,_OSSemPend
	.stabs	"pevent:P(1,14)",64,0,259,10
	.stabs	"timeout:P(2,4)",64,0,259,4
	.stabs	"err:P(0,17)",64,0,259,11
	.global _OSSemPend
	.type	_OSSemPend, @function
_OSSemPend:
	.stabd	46,0,0
	.stabn	68,0,260,.LM81-.LFBB6
.LM81:
.LFBB6:
	b.entri 	4,0
	b.mov  	r10,r3	     # movsi
	b.mov  	r11,r5	     # movsi
	.stabn	68,0,266,.LM82-.LFBB6
.LM82:
	bw.lbz   	r7,(_OSIntNesting)(r0)
	b.beqi  	r7,0,.L60
	.stabn	68,0,267,.LM83-.LFBB6
.LM83:
	b.movi  	r7,2	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L71
.L60:
	.stabn	68,0,271,.LM84-.LFBB6
.LM84:
	b.bnei  	r3,0,.L63
	.stabn	68,0,272,.LM85-.LFBB6
.LM85:
	b.movi  	r7,4	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L71
.L63:
	.stabn	68,0,276,.LM86-.LFBB6
.LM86:
	b.lbz   	r7,0(r3)
	b.beqi  	r7,3,.L65
	.stabn	68,0,277,.LM87-.LFBB6
.LM87:
	b.movi  	r7,1	    # movqi imm P
	b.sb    	0(r5),r7	   # movqi store
	b.j    	.L71
.L65:
.LBB7:
	.stabn	68,0,280,.LM88-.LFBB6
.LM88:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r12,r7,0
.LBE7:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r12,-7
	l.mtspr r6,r7,0
	.stabn	68,0,281,.LM89-.LFBB6
.LM89:
	b.lhz   	r7,2(r3)
	b.beqi  	r7,0,.L67
	.stabn	68,0,282,.LM90-.LFBB6
.LM90:
	b.addi  	r7,r7,-1
	b.sh    	2(r3),r7	   # movhi store
	.stabn	68,0,283,.LM91-.LFBB6
.LM91:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r12,0
	.stabn	68,0,284,.LM92-.LFBB6
.LM92:
	b.sb    	0(r5),r0	   # movqi store
	b.j    	.L71
.L67:
	.stabn	68,0,288,.LM93-.LFBB6
.LM93:
	bw.lwz   	r6,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r5,34(r6)
	b.ori   	r7,r5,1
	b.sb    	34(r6),r7	   # movqi store
	.stabn	68,0,289,.LM94-.LFBB6
.LM94:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.sb    	35(r7),r0	   # movqi store
	.stabn	68,0,290,.LM95-.LFBB6
.LM95:
	bw.lwz   	r7,(_OSTCBCur)(r0)	    # movsi load
	b.sh    	32(r7),r4	   # movhi store
	.stabn	68,0,291,.LM96-.LFBB6
.LM96:
	b.jal  	_OS_EventTaskWait
	.stabn	68,0,292,.LM97-.LFBB6
.LM97:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r12,0
	.stabn	68,0,293,.LM98-.LFBB6
.LM98:
	b.jal  	_OS_Sched
.LBB8:
	.stabn	68,0,294,.LM99-.LFBB6
.LM99:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r12,r7,0
.LBE8:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r12,-7
	l.mtspr r6,r7,0
	.stabn	68,0,295,.LM100-.LFBB6
.LM100:
	bw.lwz   	r6,(_OSTCBCur)(r0)	    # movsi load
	b.lbz   	r7,35(r6)
	b.bnei  	r7,1,.L69
	.stabn	68,0,296,.LM101-.LFBB6
.LM101:
	b.mov  	r3,r10	     # movsi
	b.jal  	_OS_EventTO
	.stabn	68,0,297,.LM102-.LFBB6
.LM102:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r12,0
	.stabn	68,0,298,.LM103-.LFBB6
.LM103:
	b.ori   	r7,r0,10	 # movqi imm J
	b.sb    	0(r11),r7	   # movqi store
	b.j    	.L71
.L69:
	.stabn	68,0,301,.LM104-.LFBB6
.LM104:
	b.sw    	28(r6),r0	   # movsi store
	.stabn	68,0,302,.LM105-.LFBB6
.LM105:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r12,0
	.stabn	68,0,303,.LM106-.LFBB6
.LM106:
	b.sb    	0(r11),r0	   # movqi store
.L71:
	.stabn	68,0,304,.LM107-.LFBB6
.LM107:
	b.reti  	4,0
	.size	_OSSemPend, .-_OSSemPend
	.stabs	"val:r(0,4)",64,0,280,12
	.stabn	192,0,0,.LBB7-.LFBB6
	.stabn	224,0,0,.LBE7-.LFBB6
	.stabs	"val:r(0,4)",64,0,294,12
	.stabn	192,0,0,.LBB8-.LFBB6
	.stabn	224,0,0,.LBE8-.LFBB6
.Lscope6:
	.stabs	"",36,0,0,.Lscope6-.LFBB6
	.stabd	78,0,0
.proc _OSSemCreate
	.stabs	"OSSemCreate:F(1,14)",36,0,85,_OSSemCreate
	.stabs	"cnt:P(2,4)",64,0,84,3
	.global _OSSemCreate
	.type	_OSSemCreate, @function
_OSSemCreate:
	.stabd	46,0,0
	.stabn	68,0,85,.LM108-.LFBB7
.LM108:
.LFBB7:
	b.entri 	2,0
	.stabn	68,0,92,.LM109-.LFBB7
.LM109:
	bw.lbz   	r7,(_OSIntNesting)(r0)
	b.movi 	r10,0	     # movsi imm P
	b.bnei  	r7,0,.L75
.LBB9:
	.stabn	68,0,95,.LM110-.LFBB7
.LM110:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mfspr r5,r7,0
.LBE9:
	b.ori  	r6,r0,17	  # movsi imm J
	b.andi  	r7,r5,-7
	l.mtspr r6,r7,0
	.stabn	68,0,96,.LM111-.LFBB7
.LM111:
	bw.lwz   	r10,(_OSEventFreeList)(r0)	    # movsi load
	.stabn	68,0,97,.LM112-.LFBB7
.LM112:
	b.beqi  	r10,0,.L76
	.stabn	68,0,98,.LM113-.LFBB7
.LM113:
	b.lwz   	r7,4(r10)	    # movsi load
	bw.sw    	(_OSEventFreeList)(r0),r7	   # movsi store
.L76:
	.stabn	68,0,100,.LM114-.LFBB7
.LM114:
	b.ori  	r7,r0,17	  # movsi imm J
	l.mtspr r7,r5,0
	.stabn	68,0,101,.LM115-.LFBB7
.LM115:
	b.beqi  	r10,0,.L75
	.stabn	68,0,102,.LM116-.LFBB7
.LM116:
	b.movi  	r7,3	    # movqi imm P
	b.sb    	0(r10),r7	   # movqi store
	.stabn	68,0,103,.LM117-.LFBB7
.LM117:
	b.sh    	2(r10),r3	   # movhi store
	.stabn	68,0,104,.LM118-.LFBB7
.LM118:
	b.sw    	4(r10),r0	   # movsi store
	.stabn	68,0,106,.LM119-.LFBB7
.LM119:
	b.ori   	r7,r0,63	 # movqi imm J
	b.sb    	9(r10),r7	   # movqi store
	.stabn	68,0,107,.LM120-.LFBB7
.LM120:
	b.sb    	10(r10),r0	   # movqi store
	.stabn	68,0,109,.LM121-.LFBB7
.LM121:
	b.mov  	r3,r10	     # movsi
	b.jal  	_OS_EventWaitListInit
.L75:
	.stabn	68,0,112,.LM122-.LFBB7
.LM122:
	b.mov  	r3,r10	     # movsi
	b.reti  	2,0
	.size	_OSSemCreate, .-_OSSemCreate
	.stabs	"pevent:r(1,14)",64,0,86,10
	.stabn	192,0,0,.LFBB7-.LFBB7
	.stabs	"val:r(0,4)",64,0,95,5
	.stabn	192,0,0,.LBB9-.LFBB7
	.stabn	224,0,0,.LBE9-.LFBB7
	.stabn	224,0,0,.Lscope7-.LFBB7
.Lscope7:
	.stabs	"",36,0,0,.Lscope7-.LFBB7
	.stabd	78,0,0
	.stabs	"",100,0,0,.Letext0
.Letext0:
	.ident	"GCC: (GNU) 4.2.1"
