#include "shell.h"
/**
 * check_case - function that check diferents cases
 * @args: arguments parameter
 * @line: string parameter
 */
void check_case(char **args, char *line)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
	{
		free(line);
		free(args[0]);
		free(args);
		_free_list(environ_s);
		_free_list(path_s);
		if (args[1] != NULL)
		{
			if (_isdigit(args[1][0]))
			{
				i = _atoi(args[1]);
				exit(i);
			}
		}
		exit(0);
	}
	else if (_strcmp(args[0], "env") == 0)
		_print_list(environ_s);
	else if (_strcmp(args[0], "setenv") == 0)
	{
		for (i = 0; args[i]; i++)
			;
		if (i != 3)
			perror("sh");
		else
			_setenv(args[1], args[2]);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		for (i = 0; args[i]; i++)
			;
		if (i != 2)
			perror("sh");
		else
			_unsetenv(args[1]);
	}
}
