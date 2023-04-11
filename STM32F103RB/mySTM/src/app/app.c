/*
 * app.c
 *
 *  Created on: Aug 27, 2022
 *      Author: encanto
 */

#ifndef SRC_APP_APP_C_
#define SRC_APP_APP_C_

#include "app.h"

//static void threadLed(void const *argument);
static void threadMain(void const *argument);
static void threadMain2(void const *argument);

uint8_t toggleTrigger;
uint16_t adcValue;
uint32_t pwmValue;
float tempValue;
uint16_t tempVal1;

char tmpBuffer[1024] = " ";


//extern UART_HandleTypeDef inituart;

void appInit(void)
{
	/*
	osThreadDef(threadLed, threadLed, _HW_DEF_RTOS_THREAD_PRI_LED, 0,
			_HW_DEF_RTOS_THREAD_MEM_LED);

	if(osThreadCreate(osThread(threadLed), NULL) != NULL)
	{
		// Do Thread
	}
	else
	{
		// Fail
		while(1);
	}
	*/
	UartOpen(_DEF_UART1, 115200);
	UartOpen(_DEF_UART2, 115200);

	CmdInit();
	CmdPrompt();



	/* Create the thread(s) */
	osThreadDef(threadMain, threadMain, _HW_DEF_RTOS_THREAD_PRI_MAIN, 0,
				_HW_DEF_RTOS_THREAD_MEM_MAIN);

	if(osThreadCreate(osThread(threadMain), NULL) != NULL)
	{
		// Do Thread
	}
	else
	{
		// Fail
		while(1);
	}

	/* Create the thread(s) */
	osThreadDef(threadMain2, threadMain2, _HW_DEF_RTOS_THREAD_PRI_LED, 0,
				_HW_DEF_RTOS_THREAD_MEM_LED);

	if(osThreadCreate(osThread(threadMain2), NULL) != NULL)
	{
		// Do Thread
	}
	else
	{
		// Fail
		while(1);
	}

}

void appMain(void)
{
	osKernelStart();

	while(1)
	{
	}
}
/*
static void threadLed(void const *argument)
{
	UNUSED(argument);

	while(1)
	{
		//Usart_Tx_String("LED ON\r\n", 20);
		Gpio_Toggle(GPIOA, 5);
		delay(500);
	}
}
*/

static void threadMain(void const *argument)
{
	UNUSED(argument);
	//appMain();
	while(1)
	{
		/*
		toggleTrigger ^= 1;
		//if(toggleTrigger)	Usart_Tx_String("LED ON");
		//else Usart_Tx_String("LED OFF");

		Gpio_Output(GPIOA, 5, toggleTrigger);


		if(toggleTrigger == 1)
		{
			adcValue = AdcRead();
			tempValue = (3.3*(adcValue*100))/4096;
			tempVal1 = tempValue;
			//sprintf(tmpBuffer, "temperature: %d.%d\r\n", tempVal1, tempVal2);

			//HAL_UART_Transmit(&inituart, tmpBuffer, 25, 200);

			// PC로 부터 명령 받아서 _DEF_UART2 포트로 문자열 출력

		}
		*/

		if (UartAvailable(_DEF_UART1) > 0)
	    {

			uint8_t data;
			int32_t resultVal;

			CmdRead();

	    	// PC로 부터 명령어 받음
	       //data = UartRead(_DEF_UART1);
			/*
	       if (data == '1')
	       {
	    	   //resultVal = UartPrintf(_DEF_UART1, "uart send data: %d\n", data);
	          //UartPrintf(_DEF_UART2, "uart ch2 tx : 0x%X\n", data);
	    	   Gpio_Toggle(GPIOA, 5);
	    	   toggleTrigger = 0;

	       }
	       */
	     }
		/*
		else
		{
			if(toggleTrigger == 0)
			{
				CmdPrompt();
				toggleTrigger ^= 1;
				delay(100);
			}
		}
		*/
	    //delay(100);

	}

}

static void threadMain2(void const *argument)
{
	UNUSED(argument);
	//appMain();
	//int i = 0;

	while(1)
	{
		/*
		for(i=0; i<100; i++)
		{
			if(!toggleTrigger)	PwmWrite(_DEF_PWM1, i);
			else					PwmWrite(_DEF_PWM1, 99-i);
			delay(10);
		}
		*/
		delay(20);
		PwmWrite(_DEF_PWM1, pwmValue);

		if(!toggleTrigger) pwmValue++;
		else				pwmValue--;
		if(pwmValue >= 100)
		{
			toggleTrigger ^= 1;
		}
		else if(pwmValue <= 0)
		{
			toggleTrigger ^= 1;
		}
		//toggleTrigger ^= 1;
		//Gpio_Toggle(GPIOA, 0);
		//delay(500);
		/*
		if(tempValue < 20)
		{
			Gpio_Toggle(GPIOA, 0);
			delay(500);
		}
		else
		{
			Gpio_Output(GPIOA, 0, 0);
		}
		*/
	}
}

#endif /* SRC_APP_APP_C_ */
