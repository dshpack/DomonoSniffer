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
		.callback = _exit
	},
	{
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

static SNF_RESULT_T _exit()
{
	printf("\nEXIT works\n");
	//exit(0);
	return SNF_RESULT_SUCCESS;
}

void parse_subcomands(size_t command, char *line)
{
	char *ptr;
	snf_commands[(int)command].callback();
	while (line)
	{
		ptr = strtok(NULL, SEPARATOR);
		if (ptr)
			printf("sub command or flag %s\n", ptr);
	}
	//printf("Here must be some subcomands or flags and calls for funcs%s\n", line);
}

void commands_manager(char *line)
{
	t_command *iter = snf_commands;
	while (sizeof(iter) < sizeof(snf_commands) / sizeof(t_command))
	{
		if (strcmp(line, iter->name) == 0)
		{
			parse_subcomands(sizeof(iter), line);
			break ;
		}
		iter++;
	}	
}

