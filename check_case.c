#include "shell.h"
/**
 * check_case2 - function that check other enviroments
 * @args: arguments parameters
 */
void check_case2(char **args)
{
	char *str;
	int i;

	if (_strcmp(args[0], "getenv") == 0)
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
			_puts(str);
			_putchar(10);
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
/**
 * free_all - function that free memory
 * @args: argumentos to free
 * @line: string to free
 */
void free_all2(char **args, char *line)
{
	int i = 0;

	while (args[i])
	{
		if (args[i])
			free(args[i]);
		i++;
	}
	if (args != NULL)
		free(args);
	if (line != NULL)
		free(line);
	_free_list(env_s);
	_free_list(path_s);
}
/**
 * exit_estatus - check if exit have arguments
 * @args: arguments parameter
 * @line: string parameter
 */
void exit_estatus(char **args, char *line)
{
	int i = 0;

	while (args[i] != NULL)
		i++;
	if (i != 2)
		return;
	if (args[1] != NULL)
	{
		if (_isdigit(args[1][0]))
		{
			i = _atoi(args[1]);
			free_all2(args, line);
			exit(i);
		}
		else
			perror("perra");
	}
}
/**
 * check_case - function that check diferents cases
 * @args: arguments parameter
 * @line: string parameter
 */
void check_case(char **args, char *line)
{
	int i;

	if (_strcmp(args[0], "exit") == 0)
	{
		exit_estatus(args, line);
		free_all2(args, line);
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
	check_case2(args);

}
