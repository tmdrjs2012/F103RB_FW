/*
 * hw.h
 *
 *  Created on: Aug 27, 2022
 *      Author: encanto
 */

#ifndef SRC_HW_HW_H_
#define SRC_HW_HW_H_

#include "hw_def.h"
#include "core/adc.h"
#include "core/flash.h"
#include "core/gpio.h"
#include "core/uart.h"
#include "core/pwm.h"
#include "core/cmd.h"

void hwInit(void);

void delay(uint32_t time_ms);
uint32_t millis(void);

#endif /* SRC_HW_HW_H_ */
