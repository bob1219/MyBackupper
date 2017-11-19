/* Standard Libraries */
#include <stdio.h>
#include <string.h>

/* Headers */
#include "functions.h"
#include "macros.h"

int
CommandProcess
(const char **command)
{
	int	r;
	
	/* Process a command */
	if(!strcmp(*(command + 1), "pl"))r = PrintList(*(command + 2));
	else if(!strcmp(*(command + 1), "as"))r = AdditionSetting(*(command + 2), *(command + 3), *(command + 4));
	else if(!strcmp(*(command + 1), "cs"))r = ClearSetting(*(command + 2));
	else if(!strcmp(*(command + 1), "bu"))r = backup(*(command + 2));
	else
	{
		fprintf(stderr, "Unknown command \"%s\".\n", *(command + 1));
		return FAILURE;
	}
	
	return r;
}
