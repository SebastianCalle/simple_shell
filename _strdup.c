#include "shell.h"

char *_strdup(char *str)
{
	int len;
	char *copy;

	len = _strlen(str);

	copy = malloc(sizeof(char) * len);
	if (copy == NULL)
		return (NULL);

	_strcpy(copy, str, len);

	return (copy);
}
