#include "shell.h"

int _setenv(char *name, char *value)
{
	int idx;
	char *str, *s1 = name, *s2 = "=", *s3 = value;

	str = malloc(_strlen(name) + _strlen(value) + 2);
	if (str == NULL)
		return(-1);

	str[0] = '\0';

	str = _strcat(str, s1);
	str = _strcat(str, s2);
	str = _strcat(str, s3);

	if ((idx = _find_node(&environ_s, name)) != -1)
	{
		_remove_node(&environ_s, idx);
		_add_node_idx(&environ_s, str, idx);
	}
	else
		_add_node_end(&environ_s, str);

	free(str);

	return (0);
}
