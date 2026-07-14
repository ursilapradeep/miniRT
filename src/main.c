#include "rt.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s scene.rt\n", argv[0]);
		return (1);
	}
	return (0);
}
