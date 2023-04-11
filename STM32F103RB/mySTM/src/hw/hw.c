/*
 * hw.c
 *
 *  Created on: Aug 27, 2022
 *      Author: encanto
 */

#ifndef SRC_HW_HW_C_
#define SRC_HW_HW_C_

#include "hw.h"

void hwInit(void)
{
	bspInit();

	GpioInit();
	AdcInit();
	FlashInit();

	PwmInit(TIM2, _DEF_PWM1);

	UartInit();
}

void delay(uint32_t time_ms)
{
#ifdef _USE_HW_RTOS
	if(xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
	{
		osDelay(time_ms);
	}
	else
	{
		HAL_Delay(time_ms);
	}
	//HAL_Delay(time_ms);
#endif
}

uint32_t millis(void)
{
	return HAL_GetTick();
}

#endif /* SRC_HW_HW_C_ */
