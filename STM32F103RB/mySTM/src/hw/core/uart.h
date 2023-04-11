/*
 * uart.h
 *
 *  Created on: 2018. 5. 19.
 *      Author: Baram
 */

#ifndef SRC_HW_CORE_UART_H_
#define SRC_HW_CORE_UART_H_

#include "hw_def.h"
#include "qbuffer.h"

#define UART_MAX_CH     2

void     UartInit(void);
bool     UartOpen(uint8_t channel, uint32_t baud);
bool     UartClose(uint8_t channel);
uint32_t UartAvailable(uint8_t channel);
void     UartFlush(uint8_t channel);
void     UartPutch(uint8_t channel, uint8_t ch);
uint8_t  UartGetch(uint8_t channel);
int32_t  UartWrite(uint8_t channel, uint8_t *p_data, uint32_t length);
void 	  UartTransmit(uint8_t channel, uint8_t *p_data);
uint8_t  UartRead(uint8_t channel);
int32_t  UartPrintf(uint8_t channel, const char *fmt, ...);


#endif /* SRC_HW_CORE_UART_H_ */
