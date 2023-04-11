/*
 * pwm.h
 *
 *  Created on: 2022. 12. 6.
 *      Author: encanto
 */

#ifndef SRC_HW_CORE_PWM_H_
#define SRC_HW_CORE_PWM_H_

#include "hw_def.h"


void PwmInit(uint32_t TimerDef, uint8_t ch);

void PwmWrite(uint8_t ch, uint8_t pwm_data);

#endif /* SRC_HW_CORE_PWM_H_ */
