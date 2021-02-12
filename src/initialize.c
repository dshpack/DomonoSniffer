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
	printf("\nSTART works\n");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _stop(COMMANDS_CALL_PARAMS sub_command)
{
	printf("\nSTOP works\n");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T	 _show(COMMANDS_CALL_PARAMS sub_command)
{
	printf("\nSHOW works\n");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _stat(COMMANDS_CALL_PARAMS sub_command)
{
	printf("\nSTAT works\n");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _help()
{
	printf("\nHELP works\n");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _exit_program()
{
	printf("\nEXIT works\n");
	exit(EXIT_SUCCESS);
	return SNF_RESULT_SUCCESS;
}

void parse_subcomands(int command, char *line)
{
	char *ptr = NULL;
	snf_commands[command].callback();
	while (ptr)
	{
		ptr = strtok(NULL, SEPARATOR);
		if (ptr)
			printf("sub command or flag: %s\n", ptr);
		else
			break ;
	}
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
		printf("\nYou are type a wrong command!\n");
	//printf("sizeof(iter) = %li, sizeof(snf_commands) / sizeof(t_command) = %li\n", sizeof(iter),sizeof(snf_commands) / sizeof(t_command));
	//printf("sizeof(snf_commands) = %li, sizeof(t_command) = %li, %p\n", sizeof(snf_commands), sizeof(t_command), snf_commands + 7);
}

