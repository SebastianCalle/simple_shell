#include "shell.h"

/**
 * _unsetenv - Function that unsets an environment variable
 * @name: Name of the environment variable
 * Return: 0 on success or -1 if it fails
 */
int _unsetenv(char *name)
{
	int idx;

	if (name == NULL)
		return (-1);

	idx = _find_node(&env_s, name);
	if (idx == -1 || name == NULL)
		return (-1);

	_remove_node(&env_s, idx);

	return (0);
}
