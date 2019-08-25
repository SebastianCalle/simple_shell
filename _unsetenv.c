#include "shell.h"

/**
 * _unsetenv - deletes the variable name of the environment
 * @name: name to delete
 * Return: 0 if is succes or -1 if not
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
