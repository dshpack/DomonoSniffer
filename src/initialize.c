#include "../inc/cli.h"

static t_command snf_commands[] = {
	{
		.id = START,
		.name = "start",
		.callback = _start
	},
	{
		.id = STOP,
		.name = "stop",
		.callback = _stop
	},
	{
		.id = SHOW,
		.name = "show",
		.callback = _show
	},
	{
		.id = STAT,
		.name = "stat",
		.callback = _stat
	},
	{
		.id = HELP,
		.name = "--help",
		.callback = _help
	},
	{
		.id = EXIT,
		.name = "exit",
		.callback = _exit_program
	},
	{
		.id = -1,
		.name = NULL,
		.callback = NULL
	}
};

static SNF_RESULT_T _start(COMMANDS_CALL_PARAMS sub_command)
{
	printf(COLOR_GREEN"START works\n"COLOR_RESET);
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _stop(COMMANDS_CALL_PARAMS sub_command)
{
	printf(COLOR_GREEN"STOP works\n"COLOR_RESET);
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T	 _show(COMMANDS_CALL_PARAMS sub_command)
{
	printf(COLOR_GREEN"SHOW works\n"COLOR_RESET);
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _stat(COMMANDS_CALL_PARAMS sub_command)
{
	printf(COLOR_GREEN"STAT works\n"COLOR_RESET);
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _help()
{
	printf(COLOR_GREEN"HELP works\n"COLOR_RESET);
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _exit_program()
{
	printf(COLOR_GREEN"EXIT works\n"COLOR_RESET);
	exit(EXIT_SUCCESS);
	return SNF_RESULT_SUCCESS;
}

void parse_subcomands(int command, char *line)
{
	char *ptr = NULL;
	snf_commands[command].callback();
	do
	{
		ptr = strtok(NULL, SEPARATOR);
		if (ptr)
			printf(COLOR_GREEN"\tsub command or flag: %s\n", ptr, COLOR_RESET);
		else
			break ;
	}
	while (ptr);
	//printf("Here must be some subcomands or flags and calls for funcs%s\n", line);
}

void commands_manager(char *line)
{
	t_command *iter = snf_commands;

	while (iter->id != -1)
	{
		
		if (strcmp(line, iter->name) == 0)
		{
			parse_subcomands(iter->id, line);
			break ;
		}
		iter++;
	}
	if (iter->id == -1)
		printf(COLOR_RED"You are type a wrong command!\n"COLOR_RESET);
	//printf("sizeof(iter) = %li, sizeof(snf_commands) / sizeof(t_command) = %li\n", sizeof(iter),sizeof(snf_commands) / sizeof(t_command));
	//printf("sizeof(snf_commands) = %li, sizeof(t_command) = %li, %p\n", sizeof(snf_commands), sizeof(t_command), snf_commands + 7);
}

