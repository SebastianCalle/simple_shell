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
			perror("hsh:");
	}
}

/**
 * _exit_shell - function that exits the program
 * @argc: Number of arguments
 * @l: input line
 * @args: Multidimensional array of arguments
 * @env_s: Environment linked list
 * Return: 0 if is succes or -1 if not
 */
int _exit_shell(UN int argc, char *l, char **args, UN node_t **env_s)
{
	exit_estatus(args, l);
	free_all2(args, l);
	exit(0);
}
