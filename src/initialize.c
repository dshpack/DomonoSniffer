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

static SNF_RESULT_T _start(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "START works");

	if (argc != 1)
	{
		print_message(COMMAND_WORKED, "I need 1 arg");
		return SNF_RESULT_ERROR;
	}

	print_message(USER_INPUT, "Got %s", argv[0]);

	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _stop(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "STOP works");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T	 _show(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "SHOW works");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _stat(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "STAT works");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _help(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "HELP works");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _exit_program(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "EXIT works");
	exit(EXIT_SUCCESS);
	return SNF_RESULT_SUCCESS;
}
/*
void parse_subcomands(int COMMAND, char *line)
{
	char *ptr = NULL;
	snf_commands[COMMAND].callback();
	do
	{
		ptr = strtok(NULL, " ");
		if (ptr)
			print_message(SUB_COMMANDS, (const char*)ptr);
		else
			break ;
	}
	while (ptr);
}
*/
SNF_RESULT_T commands_manager(int argc, char **argv)
{
	char *cmd = *argv;

	for (int i = 0; i < COMMANDS_AMOUNT; i++)
	{
		if (strcmp(cmd, snf_commands[i].name) == 0)
		{
			snf_commands[i].callback(argc - 1, argv + 1);
			return SNF_RESULT_SUCCESS;
		}
		
	}
	
	return SNF_RESULT_ERROR;
}

