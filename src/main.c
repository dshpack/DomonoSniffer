#include "../inc/cli.h"
/*
void parse_line(char *line)
{
	char *ptr;

	ptr = strtok(line, " ");
	if (ptr)
	{
		if (commands_manager(ptr) != SNF_RESULT_SUCCESS)
			print_message(WRONG_COMMAND, "You are type a wrong command!");
	}
}
*/

void parse_line(char *line)
{
	(void)line;
}

SNF_RESULT_T parse_cmd(int argc, char **argv)
{
	if (commands_manager(argc, argv) != SNF_RESULT_SUCCESS)
	{
		print_message(WRONG_COMMAND, "You are type a wrong command!");
		return SNF_RESULT_ERROR;
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		while (1)
		{
			char buf[256];

			print_message(USER_INPUT, ">>> ");

			scanf("%256[^\n]s", buf);
			getchar();

			/* You need to write UNIT Factory strsplit */
			parse_line(buf);

			parse_cmd(usr_argc, usr_argv);
		}
	}
	else
		return parse_cmd(argc - 1, argv + 1);

	return 0;
}
