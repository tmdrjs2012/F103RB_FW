/*
 * pwm.c
 *
 *  Created on: 2022. 12. 6.
 *      Author: encanto
 */

#ifndef SRC_HW_CORE_PWM_C_
#define SRC_HW_CORE_PWM_C_

#include "hw_def.h"
#include "pwm.h"

TIM_HandleTypeDef TimHandle;
TIM_OC_InitTypeDef sConfig;
TIM_ClockConfigTypeDef sClockSourceConfig = {0};
TIM_MasterConfigTypeDef sMasterConfig = {0};

uint32_t uhPrescalerValue = 0;

static void PWM_MspPostInit(TIM_HandleTypeDef* htim);

void PwmInit(uint32_t TimerDef, uint8_t ch)
{
	//__TIM1_CLK_ENABLE();

	uhPrescalerValue = (uint32_t)((SystemCoreClock /1) / (1000 * 100)) - 1;

	if(TimerDef==TIM1)
	  {
	  /* USER CODE BEGIN TIM1_MspInit 0 */

	  /* USER CODE END TIM1_MspInit 0 */
	    /* Peripheral clock enable */
	    __HAL_RCC_TIM1_CLK_ENABLE();
	  /* USER CODE BEGIN TIM1_MspInit 1 */

	  /* USER CODE END TIM1_MspInit 1 */
	  }
	  else if(TimerDef==TIM2)
	  {
	  /* USER CODE BEGIN TIM2_MspInit 0 */

	  /* USER CODE END TIM2_MspInit 0 */
	    /* Peripheral clock enable */
	    __HAL_RCC_TIM2_CLK_ENABLE();
	  /* USER CODE BEGIN TIM2_MspInit 1 */

	  /* USER CODE END TIM2_MspInit 1 */
	  }
	  else if(TimerDef==TIM3)
	  {
	  /* USER CODE BEGIN TIM3_MspInit 0 */

	  /* USER CODE END TIM3_MspInit 0 */
	    /* Peripheral clock enable */
	    __HAL_RCC_TIM3_CLK_ENABLE();
	  /* USER CODE BEGIN TIM3_MspInit 1 */

	  /* USER CODE END TIM3_MspInit 1 */
	  }
	  else if(TimerDef==TIM4)
	  {
	  /* USER CODE BEGIN TIM4_MspInit 0 */

	  /* USER CODE END TIM4_MspInit 0 */
	    /* Peripheral clock enable */
	    __HAL_RCC_TIM4_CLK_ENABLE();
	  /* USER CODE BEGIN TIM4_MspInit 1 */

	  /* USER CODE END TIM4_MspInit 1 */
	  }





	//uhPrescalerValue = (uint32_t)((SystemCoreClock /1) / (50000 * 255)) - 1;
	//uhPrescalerValue = (uint32_t)((SystemCoreClock /1) / (3* 4095)) - 1;

	TimHandle.Instance = TimerDef;

	TimHandle.Init.Prescaler = uhPrescalerValue;			//
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	TimHandle.Init.Period = 100-1;				//
	TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	//TimHandle.Init.RepetitionCounter = 0;
	if (HAL_TIM_Base_Init(&TimHandle) != HAL_OK)
	{
		//Error_Handler();
	}

	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&TimHandle, &sClockSourceConfig) != HAL_OK)
	{
		//Error_Handler();
	}
	if (HAL_TIM_PWM_Init(&TimHandle) != HAL_OK)
	{
		//Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&TimHandle, &sMasterConfig) != HAL_OK)
	{
		//Error_Handler();
	}

	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_DISABLE;
	//sConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	//sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	//sConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfig.Pulse = 0;

	/*
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF1_TIM1;
	GPIO_InitStruct.Pin = GPIO_PIN_9;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfig.OCFastMode = TIM_OCFAST_DISABLE;
	sConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;

	sConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfig.Pulse = 0;
	*/
	HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, ch);
	PWM_MspPostInit(&TimHandle);
	HAL_TIM_PWM_Start(&TimHandle, ch);
}

static void PWM_MspPostInit(TIM_HandleTypeDef* htim)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if(htim->Instance==TIM2)
	{
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		/**TIM2 GPIO Configuration
    	PA0-WKUP     ------> TIM2_CH1
    	PA1     ------> TIM2_CH2
    	PB10     ------> TIM2_CH3
    	PB11     ------> TIM2_CH4
		 */
		GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		//GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
		//GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		//GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		//HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

       __HAL_AFIO_REMAP_TIM2_PARTIAL_2();
	}
	else if(htim->Instance==TIM3)
	{
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		/**TIM3 GPIO Configuration
    	PA6     ------> TIM3_CH1
    	PA7     ------> TIM3_CH2
    	PB0     ------> TIM3_CH3
    	PB1     ------> TIM3_CH4
		 */
		GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	}
	else if(htim->Instance==TIM4)
	{
		__HAL_RCC_GPIOB_CLK_ENABLE();
		/**TIM4 GPIO Configuration
    	PB6     ------> TIM4_CH1
    	PB7     ------> TIM4_CH2
    	PB8     ------> TIM4_CH3
    	PB9     ------> TIM4_CH4
		 */
		GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	}
}

void PwmWrite(uint8_t ch, uint8_t pwm_data)
{
	//sConfig.Pulse = pwm_data;
	if(ch == _DEF_PWM1)
	{
		TimHandle.Instance->CCR1 = pwm_data;
	}
	else if(ch == _DEF_PWM2)
	{
		TimHandle.Instance->CCR2 = pwm_data;
	}
	else if(ch == _DEF_PWM3)
	{
		TimHandle.Instance->CCR3 = pwm_data;
	}
	else
	{
		TimHandle.Instance->CCR4 = pwm_data;
	}
	//HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, ch);
	//HAL_TIM_PWM_Start(&TimHandle, ch);
}

#endif /* SRC_HW_CORE_PWM_C_ */

