#include "../inc/cli.h"


int		main(int argc, char **argv)
{
	t_keks		*keks;
	init(&keks);
	//printf("\n%s--%p----%p\n", keks[STOP].name, keks[STOP].callback, start);
	keks[START].callback();
	keks[SHOW].callback();
	keks[STAT].callback();
	return 0;
}