#include "shell.h"


void check_case(char **args, char *line)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		free(line);
		free(args[0]);
		free(args);
		exit(0);
	}
}

