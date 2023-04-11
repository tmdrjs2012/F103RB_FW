/*
 * main.c
 *
 *  Created on: Aug 27, 2022
 *      Author: encanto
 */

#ifndef SRC_MAIN_C_
#define SRC_MAIN_C_

#include "main.h"

//static void threadMain(void const *argument);
//static void threadMain2(void const *argument);

int main(void)
{	hwInit();
	appInit();
	/*
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

	osKernelStart();
	*/
	appMain();
	return 0;
	//appMain();
}

/*
static void threadMain(void const *argument)
{
	UNUSED(argument);
	//appMain();
	while(1)
	{

	}

}
*/
#endif /* SRC_MAIN_C_ */
