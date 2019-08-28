#include "shell.h"

/**
 * _unsetenv - deletes the variable name of the environment
 * @argc: Number of arguments
 * @l: input line
 * @args: Multidimensional array of arguments
 * @env_s: Environment linked list
 * Return: 0 if is succes or -1 if not
 */
int _unsetenv(int argc, UN char *l, char **args, node_t **env_s)
{
	int idx;

	if (argc != 2)
	{
		write(STDERR_FILENO, "./hsh: 1: Number of arguments is wrong\n", 39);
		return (-1);
	}

	idx = _find_node(env_s, args[1]);
	if (idx == -1 || args == NULL)
	{
		write(STDERR_FILENO, "./hsh: 1: Invalid argument\n", 28);
		return (-1);
	}


	_remove_node(env_s, idx);

	return (0);
}
