/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>

/* Headers */
#include "functions.h"
#include "macros.h"

int
main
(int argc,
char **argv)
{
	int	r;
	
	if(argc == 1)
	{
		fprintf(stderr, "Argument is missing.\n");
		return EXIT_FAILURE;
	}
	
	/* Process a command */
	r = CommandProcess((const char**)argv);
	if(r == SUCCESS)
	{
		printf("succeeded.\n");
		return EXIT_SUCCESS;
	}
	else if(r == FAILURE)
	{
		fprintf(stderr, "failed.\n");
		return EXIT_FAILURE;
	}
	else abort();
}
