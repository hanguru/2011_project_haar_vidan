#ifndef _INTERRUPT_HANDLER_H_
#define _INTERRUPT_HANDLER_H_

#include "task_manage.h"
//#include "or_map.h"
#include "map_hif.h"

/**********************************************/
/* Interrupt Source                           */
/* Now defined Int NUM : 20                   */
/* Int Num define : or1200_defines.v(pic_int) */
/**********************************************/

/*
 * Timer Interrupt Enable
 *
 * tick : Clock Cycle Counter num to cause interrupt(28bit)
 *
 */
void OpenRiscEnableTimerInt(INT32U tick);

/*
 * Timer Interrupt Disable
 */
void OpenRiscDisableTimerInt(void);

/*
 * Restart timer counter
 *
 * if timer counter is paused by OpenRiscTimerPause(),
 * this function restars Timer Counter(TTCR).
 *
 */
void OpenRiscTimerRestart(void);

/*
 * Pause Timer counter temporarily.
 */
void OpenRiscTimerPause(void);

/*
 * External Interrupt Enable
 */
void OpenRiscEnableInt(void);

/*
 * External Interrupt Disable
 */
void OpenRiscDisableInt(void);

/*
 * Unmask Exnternal Interrupt Bit
 *
 * type : bit to be unmasked
 *
 */
void IntEnable(INT32U type);

/*
 * Mask Extenal Interrupt Bit
 *
 * type : bit to be masked
 *
 */
void IntDisable(INT32U type);

#endif

