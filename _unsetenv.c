#include "shell.h"

int _unsetenv(char *name)
{
	int idx;

	if ((idx = _find_node(&environ_s, name)) == -1 || name == NULL)
		return (-1);

	_remove_node(&environ_s, idx);

	return (0);
}
