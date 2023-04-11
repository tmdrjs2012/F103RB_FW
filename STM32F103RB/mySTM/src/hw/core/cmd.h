/*
 * cmd.h
 *
 *  Created on: 2022. 12. 3.
 *      Author: encanto
 */

#ifndef SRC_HW_CORE_CMD_H_
#define SRC_HW_CORE_CMD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uart.h"

#define USER_PROMPT       "SaRo_STM32"

struct cmd_t
{
	char *tag;
	char *desc;
	void (*cmd_func)(int , char **);
};

void CmdInit(void);
void CmdPrompt(void);
void CmdRead(void);

#endif /* SRC_HW_CORE_CMD_H_ */
