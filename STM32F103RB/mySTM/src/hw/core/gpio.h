/*
 * gpio.h
 *
 *  Created on: Sep 4, 2022
 *      Author: encanto
 */

#ifndef SRC_HW_CORE_GPIO_H_
#define SRC_HW_CORE_GPIO_H_

#include "hw_def.h"

typedef enum{
	LOW_LV = 0,
	HIGH_LV = 1
}gpio_lv_t;

void GpioInit(void);
uint8_t Gpio_Input(GPIO_TypeDef *GPIOx, uint16_t Pin_Num);
void Gpio_Output(GPIO_TypeDef *GPIOx, uint16_t Pin_Num, gpio_lv_t State);
void Gpio_Toggle(GPIO_TypeDef *GPIOx, uint16_t Pin_Num);


#endif /* SRC_HW_CORE_GPIO_H_ */
