#include "../inc/cli.h"

SNF_RESULT_T parse_cmd(int argc, char **argv)
{
	if (commands_manager(argc, argv) != SNF_RESULT_SUCCESS)
	{
		print_message(WRONG_COMMAND, "You are type a wrong command!\n");
		return SNF_RESULT_ERROR;
	}
}

int calculate_usr_argc(char *line)
{
	int words = 0;
	char *ptr = line;

	while ((ptr = strchr(ptr, SPACE_CH)) != NULL)
	{
		ptr++;
		if (*ptr != ' ' && *ptr != '\0')
			words++;
	}
	return words;
}

void parse_line(char *line, char **usr_argv, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			usr_argv[i] = strtok(line, " ");
		else
			usr_argv[i] = strtok(NULL, " ");
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		int usr_argc = 0;
		char buf[256];

		print_message(USER_INPUT, ">>> ");

		scanf("%256[^\n]s", buf);
		getchar();

		/* You need to write UNIT Factory strsplit */
		usr_argc = calculate_usr_argc(buf) + 1;
		if (usr_argc == 0)
		{
			print_message(WRONG_COMMAND, "You are type a wrong command!");
			exit(EXIT_SUCCESS);
		}
		char *usr_argv[usr_argc];
		parse_line(buf, usr_argv, usr_argc);
		printf("words cout = %i\n", usr_argc);
		//for (int i = 0; i < usr_argc; i++)
		//	printf("word %i = %s\n", i, usr_argv[i]);
		parse_cmd(usr_argc, usr_argv);
	}
	else
		return parse_cmd(argc - 1, argv + 1);
	return 0;
}
