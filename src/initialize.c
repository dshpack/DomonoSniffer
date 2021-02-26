#include "../inc/cli.h"

static SNF_RESULT_T _start(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "START works\n");
	parse_subcomands(argc, argv);
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _stop(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "STOP works\n");
	parse_subcomands(argc, argv);
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T	 _show(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "SHOW works\n");
	parse_subcomands(argc, argv);
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _stat(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "STAT works\n");
	parse_subcomands(argc, argv);
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _help(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "HELP works\n");
	return SNF_RESULT_SUCCESS;
}

static SNF_RESULT_T _exit_program(int argc, char **argv)
{
	print_message(COMMAND_WORKED, "EXIT works\n");
	exit(EXIT_SUCCESS);
	return SNF_RESULT_SUCCESS;
}

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

void parse_subcomands(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{
		print_message(SUB_COMMANDS, (const char*)argv[i]);
		printf("\n");
	}
}

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

