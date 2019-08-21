#include "shell.h"


int check_case(char **args, char *line)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		free(line);
		free(args[0]);
		free(args);
		exit(0);
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		
		printfile(args[0]);
		return(1);
	}
	return(0);
}
