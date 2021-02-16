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
	},
	{
		.name = NULL,
		.callback = NULL
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

void parse_subcomands(t_command *command, char *line)
{
	char *ptr = NULL;
	command->callback();
	do
	{
		ptr = strtok(NULL, SEPARATOR);
		if (ptr)
			print_message(SUB_COMMANDS, (const char*)ptr);
		else
			break ;
	}
	while (ptr);
	//printf("Here must be some subcomands or flags and calls for funcs%s\n", line);
}

void commands_manager(char *line)
{
	t_command *iter = snf_commands;

	while (iter->name)
	{
		if (strcmp(line, iter->name) == 0)
		{
			parse_subcomands(iter, line);
			//parse_subcomands(COMMANDS_AMOUNT, line);
			//printf("COMMANDS_AMOUNT = %li\n", COMMANDS_AMOUNT);
			break ;
		}
		iter++;
	}
	if (!iter->name)
		print_message(WRONG_COMMAND, "You are type a wrong command!");
	//printf("sizeof(iter) = %li, sizeof(snf_commands) / sizeof(t_command) = %li\n", sizeof(iter),sizeof(snf_commands) / sizeof(t_command));
	//printf("sizeof(snf_commands) = %li, sizeof(t_command) = %li, %p\n", sizeof(snf_commands), sizeof(t_command), snf_commands + 7);
}

