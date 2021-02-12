#include "../inc/cli.h"

void parse_line(char *line)
{
	char *ptr;
	char *sep = " ";

	ptr = strtok(line, sep);
	if (ptr)
		commands_manager(ptr);
	//else print something
}

int main(int argc, char **argv)
{
	char buf[256];
	if (argc > 1)
	{
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
	//scanf("%256[A-Za-z- ]s", buf);
	//printf("\n%s|end\n", buf);
		printf("|end\n");
	return 0;
}