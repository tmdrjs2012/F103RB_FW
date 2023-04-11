/*
 * hw_def.h
 *
 *  Created on: Aug 27, 2022
 *      Author: encanto
 */

#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_

#include "def.h"
#include "bsp.h"
#include "bsp/stm32f1xx_it.h"

#define _HW_DEF_RTOS_MEM_SIZE(x)			((x)/4)

#define _HW_DEF_RTOS_THREAD_PRI_MAIN		osPriorityNormal
#define _HW_DEF_RTOS_THREAD_PRI_LED		osPriorityNormal

#define _HW_DEF_RTOS_THREAD_MEM_MAIN		_HW_DEF_RTOS_MEM_SIZE( 4*128 )
#define _HW_DEF_RTOS_THREAD_MEM_LED		_HW_DEF_RTOS_MEM_SIZE( 4*128 )

#define _USE_HW_RTOS

#endif /* SRC_HW_HW_DEF_H_ */
