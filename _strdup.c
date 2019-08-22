#include "shell.h"

char *_strdup(char *str)
{
	int len;
	char *copy;

	len = _strlen(str) + 1;

	copy = malloc(sizeof(char) * len);
	if (copy == NULL)
		return (NULL);

	_memcpy(copy, str, len);

	return (copy);
}
