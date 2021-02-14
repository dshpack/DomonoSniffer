#include "../inc/cli.h"

void parse_line(char *line)
{
	char *ptr;

	ptr = strtok(line, SEPARATOR);
	if (ptr)
		commands_manager(ptr);
	//else print something
}

int main(int argc, char **argv)
{
	//printf("\033[1;31mbold red text\033[0m\n");
	//system("color F0");
	if (argc > 1)
	{
		char buf[256];
		for (int i = 1; i < argc; i++)
		{
			if (i == 1){
				//printf("\nif\n");
				strcpy(buf, argv[i]);
				strcpy(&(buf[strlen(argv[i])]), " \0");
			}
			else {
				//printf("\nelse\n");
				strcpy(strrchr(buf, SPACE_CH) + 1, argv[i]);
				if (i < argc - 1)
					strcpy(strrchr(buf, SPACE_CH) + strlen(argv[i]) + 1, " \0");
			}
			
		}
		parse_line(buf);
		//printf("\n%s|end\n", buf);
	}
	while (1)
	//for (int i = 0; i < 2; i++)
	{char c;
		char buf[256];
		printf(COLOR_YELLOW">>> "COLOR_RESET);
		//scanf(" %[^\n]s", buf);
		scanf("%256[A-Za-z- ]s", buf);
		getchar();

		parse_line(buf);
	}
	//printf("\n%s|end\n", buf);
	//printf("|end\n");
	return 0;
}
