#ifndef CLI_H
# define CLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log_manager.h"

#define SNF_RESULT_T int
#define COMMANDS_CALL_PARAMS int
#define SPACE_CH 32
#define COMMANDS_AMOUNT (sizeof(snf_commands) / sizeof(t_command))

enum e_snf_result
{
	SNF_RESULT_SUCCESS = 0,
	SNF_RESULT_ERROR,
};

enum e_command_call
{
	START = 0,
	STOP,
	SHOW,
	STAT,
	HELP,
	EXIT
};

enum e_command_params
{
	SUB_COMMAND = 0,
	FLAG
};

typedef struct command
{
	const char *name;
	SNF_RESULT_T (*callback)();
} t_command;

SNF_RESULT_T commands_manager(int argc, char **argv);

#endif
