#include "shell.h"

/**
 * _setenv - define the value of enviroments variables
 * @argc: Number of arguments
 * @args: Multidimensional array of arguments
 * @env_s: Environment linked list
 * Return: 0 if si suscces
 */
int _setenv(int argc, UN char *l, char **args, node_t **env_s)
{
	int idx;
	char *str, *s1 = args[1], *s2 = "=", *s3 = args[2];

	if (argc != 3)
	{
		write(STDERR_FILENO, "./hsh: 1: Number of arguments is wrong\n", 39);
		return (-1);
	}

	str = malloc(_strlen(args[1]) + _strlen(args[2]) + 2);
	if (str == NULL)
	{
		write(STDERR_FILENO, "Cannot allocate memory\n", 24);
		return (-1);
	}

	str[0] = '\0';

	str = _strcat(str, s1);
	str = _strcat(str, s2);
	str = _strcat(str, s3);

	idx = _find_node(env_s, args[1]);
	if (idx != -1)
	{
		_remove_node(env_s, idx);
		_add_node_idx(env_s, str, idx);
	}
	else
		_add_node_end(env_s, str);

	free(str);

	return (0);
}
