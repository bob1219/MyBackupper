/* Standard Library */
#include <stdio.h>

/* Header */
#include "functions.h"

int
CommandProcess
(const char **command)
{
	int	r;
	
	/* Process a command */
	if(*(command + 1) == "pl")r = PrintList(*(command + 2));
	else if(*(command + 1) == "as")r = AdditionSetting(*(command + 2), *(command + 3), *(command + 4));
	else if(*(command + 1) == "cs")r = ClearSetting();
	else if(*(command + 1) == "bu")r = backup(*(command + 1));
	else
	{
		fprintf(stderr, "Unknown command \"%s\".\n", *(command + 1));
		return FAILURE;
	}
	
	return r;
}
