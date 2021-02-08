#include "../inc/cli.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void				start()
{
	printf("\nSTART works\n");
}

void				stop()
{
	printf("\nSTOP works\n");
	exit(0);
}

void				show()
{
	printf("\nSHOW works\n");
}

void				stat()
{
	printf("\nSTAT works\n");
}

void		*init(t_keks** keks)
{
	t_keks		*tmp = (t_keks*)malloc(sizeof(t_keks) * 5);
	
	char				k_name[4][6] = { 	
										"start", 
										"stop", 
										"show",
										"stat"
									};
	void		(*funk[])() = { start, stop, show, stat };
	for (int i = 0; i < 4; i++)
	{
		strcpy(tmp[i].name, k_name[i]);
		tmp[i].callback = funk[i];
	}
	
	printf("\nInitialized!\n");
	*keks = tmp;
}

