/*
 * adc.c
 *
 *  Created on: 2022. 10. 18.
 *      Author: encanto
 */

#ifndef SRC_HW_CORE_ADC_C_
#define SRC_HW_CORE_ADC_C_

//#include <core/adc.h>
#include "adc.h"

ADC_HandleTypeDef newADC1;

void AdcInit(void)
{
	ADC_ChannelConfTypeDef sConfig = {0};

	__HAL_RCC_ADC1_CLK_ENABLE();

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
    */
	newADC1.Instance = ADC1;
	newADC1.Init.ScanConvMode = ADC_SCAN_DISABLE;
	newADC1.Init.ContinuousConvMode = ENABLE;
	newADC1.Init.DiscontinuousConvMode = DISABLE;
	newADC1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	newADC1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	newADC1.Init.NbrOfDiscConversion = 1;
	if (HAL_ADC_Init(&newADC1) != HAL_OK)
	{
		//_Error_Handler(__FILE__, __LINE__);
	}

    /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
    */
	sConfig.Channel = ADC_CHANNEL_1;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
	if (HAL_ADC_ConfigChannel(&newADC1, &sConfig) != HAL_OK)
	{
		//_Error_Handler(__FILE__, __LINE__);
	}
}

uint16_t AdcRead(void)
{
	uint16_t tmp;
	HAL_ADC_Start(&newADC1);
	HAL_ADC_PollForConversion(&newADC1, 100);

	tmp = HAL_ADC_GetValue(&newADC1);
	HAL_ADC_Stop(&newADC1);
	return tmp;
}

#endif /* SRC_HW_CORE_ADC_C_ */
