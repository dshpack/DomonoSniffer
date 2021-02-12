#ifndef CLI_H
# define CLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SNF_RESULT_T			int
#define COMMANDS_CALL_PARAMS	int
#define SPACE_CH 				32
#define SEPARATOR				" "

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

void commands_manager(char *command);
static SNF_RESULT_T _start(COMMANDS_CALL_PARAMS sub_command);
static SNF_RESULT_T _stop(COMMANDS_CALL_PARAMS sub_command);
static SNF_RESULT_T _show(COMMANDS_CALL_PARAMS sub_command);
static SNF_RESULT_T _stat(COMMANDS_CALL_PARAMS sub_command);
static SNF_RESULT_T _help();
static SNF_RESULT_T _exit();

#endif