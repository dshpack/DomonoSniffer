#include "../inc/cli.h"

static t_command snf_commands[] = {
	{
		.name = "start",
		.callback = _start
	},
	{
		.name = "stop",
		.callback = _stop
	},
	{
		.name = "show",
		.callback = _show
	},
	{
		.name = "stat",
		.callback = _stat
	},
	{
		.name = "--help",
		.callback = _help
	},
	{
		.name = "exit",
		.callback = _exit_program
	}
};

static SNF_RESULT_T _start(COMMANDS_CALL_PARAMS sub_command)
{
	print_message(COMMAND_WORKED, "START works");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _stop(COMMANDS_CALL_PARAMS sub_command)
{
	print_message(COMMAND_WORKED, "STOP works");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T	 _show(COMMANDS_CALL_PARAMS sub_command)
{
	print_message(COMMAND_WORKED, "SHOW works");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _stat(COMMANDS_CALL_PARAMS sub_command)
{
	print_message(COMMAND_WORKED, "STAT works");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _help()
{
	print_message(COMMAND_WORKED, "HELP works");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _exit_program()
{
	print_message(COMMAND_WORKED, "EXIT works");
	exit(EXIT_SUCCESS);
	return SNF_RESULT_SUCCESS;
}

void parse_subcomands(int COMMAND, char *line)
{
	char *ptr = NULL;
	snf_commands[COMMAND].callback();
	do
	{
		ptr = strtok(NULL, SEPARATOR);
		if (ptr)
			print_message(SUB_COMMANDS, (const char*)ptr);
		else
			break ;
	}
	while (ptr);
}

void commands_manager(char *line)
{
	for (int i = 0; i < COMMANDS_AMOUNT; i++)
	{
		if (strcmp(line, snf_commands[i].name) == 0)
		{
			parse_subcomands(i, line);
			break ;
		}
		if (i == COMMANDS_AMOUNT - 1)
			print_message(WRONG_COMMAND, "You are type a wrong command!");
	}
}

