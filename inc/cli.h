#ifndef CLI_H
# define CLI_H

#include <stdio.h>

enum				e_call
{
	START = 0,
	STOP,
	SHOW,
	STAT
};

typedef struct		keks
{
		char		name[6];
		void		(*callback)();
}					t_keks;

void				*init(t_keks** keks);
void				start();
void				stop();
void				show();
void				stat();

#endif