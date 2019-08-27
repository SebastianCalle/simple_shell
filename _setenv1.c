#include "shell.h"

/**
 * _setenv1 - define the value of enviroments variables
 * @name: name parameter
 * @value: value parameter
 * @env_s: environment linked list
 * Return: 0 if si suscces
 */
int _setenv1(char *name, char *value, node_t **env_s)
{
	int idx;
	char *str, *s1 = name, *s2 = "=", *s3 = value;

	str = malloc(_strlen(name) + _strlen(value) + 2);
	if (str == NULL)
	{
		write(STDERR_FILENO, "Cannot allocate memory\n", 24);
		return (-1);
	}

	str[0] = '\0';

	str = _strcat(str, s1);
	str = _strcat(str, s2);
	str = _strcat(str, s3);

	idx = _find_node(env_s, name);
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
