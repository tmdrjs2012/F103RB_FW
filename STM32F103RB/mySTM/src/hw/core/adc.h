/*
 * adc.h
 *
 *  Created on: 2022. 10. 18.
 *      Author: encanto
 */

#ifndef SRC_HW_CORE_ADC_H_
#define SRC_HW_CORE_ADC_H_

#include "hw_def.h"

void AdcInit(void);
uint16_t AdcRead(void);

#endif /* SRC_HW_CORE_ADC_H_ */
