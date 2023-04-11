/*
 * cmd.c
 *
 *  Created on: 2022. 12. 3.
 *      Author: encanto
 */

#ifndef SRC_HW_CORE_CMD_C_
#define SRC_HW_CORE_CMD_C_

#include "cmd.h"

#define ARRAY_NUM(x)	(sizeof(x) / sizeof(x[0]))

static void do_temp(int, char **);
static void do_set(int, char **);
static void do_run(int, char **);
static void do_tune(int, char **);
static void do_help(int, char **);

static void CmdCompare(char* command);


struct cmd_t Mycmd[] =
{
		{"temp", "Read current temperature", do_temp},
		{"set", "Set target temperature", do_set},
		{"run", "Run control system", do_run},
		{"tune", "Setting Tuning", do_tune},
		{"help", "Display CLI command usage", do_help},
};


static const int num_commands = ARRAY_NUM(Mycmd);
static int cmd_sorted = 0;
static int cmd_count[ARRAY_NUM(Mycmd)];


void CmdInit(void)
{
	do_help(0,0);
}

static void sort_table(void)
{
    int     i, j, tmp;

    for (i=0; i<num_commands; i++)
    	cmd_count[i] = i;

    for (i=num_commands-1; i; i--)
        for (j=0; j<i; j++)
        {
            if (strcmp(Mycmd[cmd_count[j]].tag,
            		Mycmd[cmd_count[j+1]].tag) > 0)
            {
                tmp = cmd_count[j];
                cmd_count[j] = cmd_count[j+1];
                cmd_count[j+1] = tmp;
            }
        }
}

void CmdPrompt(void)
{
    char cmd[20];
    //char *argv;
    //int  argc;

    sprintf(cmd, "\n[%s]$ ", USER_PROMPT);
    UartTransmit(_DEF_UART1, cmd);
    //cmd = wait_command();
    //printf("=> %s\n", cmd);
    //parse_command(cmd, &argc, &argv);
    //print_args(argc, (char **)argv);
}

void CmdRead(void)
{
	char data;
	uint8_t prompt_flag;
	static uint8_t idx;
	static char tempBuf[10];

	data = (char)UartRead(_DEF_UART1);

	if(data != '\n')
	{
		tempBuf[idx++] += data;
	}
	else
	{
		prompt_flag = 0;
		CmdCompare(tempBuf);

		if(!prompt_flag)
		{
			CmdPrompt();
			prompt_flag ^=1;
		}

		idx = 0;
		memset(tempBuf, 0x00, sizeof(tempBuf));
	}
}

static void CmdCompare(char* command)
{
	if(strcmp(command,"temp") == 0)
	{
		UartTransmit(_DEF_UART1, "temp\n");
		do_temp(0,0);
	}
	else if(strcmp(command,"set") == 0)
	{
		UartTransmit(_DEF_UART1, "set\n");
		do_set(0,0);
	}
	else if(strcmp(command,"run") == 0)
	{
		UartTransmit(_DEF_UART1, "run\n");
		do_run(0,0);
	}
	else if(strcmp(command,"tune") == 0)
	{
		UartTransmit(_DEF_UART1, "tune\n");
		do_tune(0,0);
	}
	else if(strcmp(command,"help") == 0)
	{
		UartTransmit(_DEF_UART1, "help\n");
		do_help(0,0);
	}
}

static void do_temp(int argc, char **argv)
{
	UartTransmit(_DEF_UART1, "Read current temperature\n");
	//puts("Read current temperature\n");
}

static void do_set(int argc, char **argv)
{
	UartTransmit(_DEF_UART1, "Set target temperature\n");
	//puts("Set target temperature\n");
}

static void do_run(int argc, char **argv)
{
	UartTransmit(_DEF_UART1, "Run control system\n");
	//puts("Run control system\n");
}

static void do_tune(int argc, char **argv)
{
	UartTransmit(_DEF_UART1, "Setting Tuning\n");
	//puts("Setting Tuning\n");
}

static void do_help(int argc, char **argv)
{
	char tmpBuffer[100];
	int i;

	UartTransmit(_DEF_UART1, "========  Controller Command List  ========\n\n");
	for (i=0; i<num_commands; i++)
    {
		//memset(tmpBuffer, 0x00, sizeof(tmpBuffer));
    	//sprintf(tmpBuffer, "%-10s : %s\n",Mycmd[i].tag
    	//		,Mycmd[i].desc);
		//sprintf(tmpBuffer, "%-10s : ",Mycmd[i].tag);

    	//UartTransmit(_DEF_UART1, tmpBuffer);
		UartTransmit(_DEF_UART1, Mycmd[i].tag);
		UartTransmit(_DEF_UART1, "\t");
		UartTransmit(_DEF_UART1, Mycmd[i].desc);
		UartTransmit(_DEF_UART1, "\n");

       //printf("%-10s : %s\n", Mycmd[cmd_count[i]].tag,
       //                        Mycmd[cmd_count[i]].desc);
    }
	UartTransmit(_DEF_UART1, "\n");
	UartTransmit(_DEF_UART1, "========================================\n");

}


#endif /* SRC_HW_CORE_CMD_C_ */

