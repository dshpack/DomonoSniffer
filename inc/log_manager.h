#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

enum e_log_color
{
	C_RESET = 0,
	C_RED = 31,
	C_GREEN,
	C_YELLOW
};

enum e_log_type
{
	WRONG_COMMAND = C_RED,
	COMMAND_WORKED = C_GREEN,
	SUB_COMMANDS = C_GREEN,
	USER_INPUT = C_YELLOW
};

#define print_message(TYPE, ...) do		\
{										\
	printf("\033[%im", TYPE);			\
	printf(__VA_ARGS__);				\
	printf("\033[%im", C_RESET);		\
} while (0)

#endif
