#include "shell.h"

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
		{
			free_all2(args, line);
			exit(0);
		}
	}
}

/**
 * _exit_shell - function that exits the program
 * @l: input line
 * @args: Multidimensional array of arguments
 * @status: status of program
 * Return: 0 if is succes or -1 if not
 */
int _exit_shell(char *l, char **args, int *status)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		exit_estatus(args, l);
		free_all2(args, l);
		if (*status == 1)
			exit(0);
		exit(*status);
	}
	return (0);
}
