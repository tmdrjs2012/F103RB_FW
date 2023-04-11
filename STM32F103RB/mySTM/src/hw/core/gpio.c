/*
 * gpio.c
 *
 *  Created on: Sep 4, 2022
 *      Author: encanto
 */

#ifndef SRC_HW_CORE_GPIO_C_
#define SRC_HW_CORE_GPIO_C_

#include "hw_def.h"
#include "gpio.h"

#define GPIO_A0_EN		1

void GpioInit(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

#ifndef GPIO_A0_EN
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
#endif


	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

	GPIO_InitStruct.Pin = GPIO_PIN_5;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

uint8_t Gpio_Input(GPIO_TypeDef *GPIOx, uint16_t Pin_Num)
{
	return HAL_GPIO_ReadPin(GPIOx, 1<<Pin_Num);
}

void Gpio_Output(GPIO_TypeDef *GPIOx, uint16_t Pin_Num, gpio_lv_t State)
{
	HAL_GPIO_WritePin(GPIOx, 1<<Pin_Num, State);
}

void Gpio_Toggle(GPIO_TypeDef *GPIOx, uint16_t Pin_Num)
{
	HAL_GPIO_TogglePin(GPIOx, 1<<Pin_Num);
}

#endif /* SRC_HW_CORE_GPIO_C_ */

