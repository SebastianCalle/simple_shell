#include "shell.h"

/**
 * free_all2 - function that free memory
 * @args: argumentos to free
 * @line: string to free
 * @env_s: Environment linked list
 */
void free_all2(char **args, char *line, node_t *env_s)
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
 * @env_s: Environment linked list
 */
void exit_estatus(char **args, char *line, node_t *env_s)
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
			free_all2(args, line, env_s);
			exit(i);
		}
		else
			perror("perra");
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
int _exit_shell(UN int argc, char *l, char **args, node_t **env_s)
{
	exit_estatus(args, l, *env_s);
	free_all2(args, l, *env_s);
	exit(0);
}
