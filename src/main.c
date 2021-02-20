#include "../inc/cli.h"

void parse_line(char *line)
{
	char *ptr;

	ptr = strtok(line, SEPARATOR);
	if (ptr)
		commands_manager(ptr);
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		char buf[256];
		for (int i = 1; i < argc; i++)
		{
			if (i == 1){
				strcpy(buf, argv[i]);
				strcpy(&(buf[strlen(argv[i])]), " \0");
			}
			else {
				strcpy(strrchr(buf, SPACE_CH) + 1, argv[i]);
				if (i < argc - 1)
					strcpy(strrchr(buf, SPACE_CH) + strlen(argv[i]) + 1, " \0");
			}
		}
		parse_line(buf);
	}
	while (1)
	{
		char buf[256];
		print_message(USER_INPUT, ">>> ");
		scanf("%256[^\n]s", buf);
		getchar();
		parse_line(buf);
	}
	return 0;
}
