/*
 * flash.h
 *
 *  Created on: 2022. 11. 30.
 *      Author: encanto
 */

#ifndef SRC_HW_CORE_FLASH_H_
#define SRC_HW_CORE_FLASH_H_

#include "hw_def.h"


void FlashInit(void);

bool FlashErase(uint32_t addr, uint32_t length);
bool FlashWrite(uint32_t addr, uint8_t *p_data, uint32_t length);

#endif /* SRC_HW_CORE_FLASH_H_ */
