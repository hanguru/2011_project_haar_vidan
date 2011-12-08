#include "tube.h"
#include "task_manage.h" //jykim_080725_ucos_porintg++
void stkChk(const char *fmt) {
	OS_STK_DATA stk_data;
	INT8U err;

	err = OSTaskStkChk(OS_PRIO_SELF, &stk_data);
	if (err == OS_NO_ERR) {
		tube_print(fmt);
		tube_print(" OSTaskStkChk\n");
		TUBE_0_PRINT_WORD(stk_data.OSFree);
		TUBE_0_PRINT_WORD(stk_data.OSUsed);
	} else {
		tube_print(fmt);
		tube_print(" OSTaskStkChk err\n");
		TUBE_0_PRINT_WORD(err);
	}

	return;

}
