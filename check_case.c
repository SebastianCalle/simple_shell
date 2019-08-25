#include "shell.h"
/**
 * check_case - function that check diferents cases
 * @args: arguments parameter
 * @line: string parameter
 */
void check_case(char **args, char *line)
{
	char *str;
	int i;

	if (strcmp(args[0], "exit") == 0)
	{
		free(line);
		free(args[0]);
		free(args);
		_free_list(env_s);
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
		_print_list(env_s);
	else if (_strcmp(args[0], "setenv") == 0)
	{
		for (i = 0; args[i]; i++)
			;
		if (i != 3)
		        write(STDERR_FILENO, "./hsh: 1: Number of arguments is wrong\n", 39);
		else
			_setenv(args[1], args[2]);
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		for (i = 0; args[i]; i++)
			;
		if (i != 2)
			write(STDERR_FILENO, "./hsh: 1: Number of arguments is wrong\n", 39);
		else
			_unsetenv(args[1]);
	}
	else if (_strcmp(args[0], "getenv") == 0)
	{
		for (i = 0; args[i]; i++)
			;
		if (i != 2)
			write(STDERR_FILENO, "./hsh: 1: Number of arguments is wrong\n", 39);
		else
		{
			str = _getenv(args[1]);
			if (str == NULL)
			{
				perror("./hsh: 1");
				return;
			}
			_puts(str), _putchar(10);;
			free(str);
		}
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		for (i = 0; args[i]; i++)
			;
		if (i > 2)
			write(STDERR_FILENO, "./hsh: 1: Number of arguments is wrong\n", 39);
		else
			_cd(args[1]);
	}
}
