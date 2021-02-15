#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

enum e_log_color
{
	C_RESET = 0,
	C_RED = 31,
	C_GREEN,
	C_YELLOW
};
//didn`t invent normal names yet
enum e_log_type
{
	WRONG_COMMAND = 0,
	COMMAND_WORKED,
	SUB_COMMANDS,
	USER_INPUT
};

void print_message(int TYPE, const char *message);

#endif
