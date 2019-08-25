#include "shell.h"

/**
 * _strdup - Function that duplicates a string
 * @str: Pointer string to be duplicate
 * Return: Return the duplicated string or NULL if it fails
 */
char *_strdup(char *str)
{
	int len;
	char *copy;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1;

	copy = malloc(sizeof(char) * len);
	if (copy == NULL)
		return (NULL);

	_memcpy(copy, str, len);

	return (copy);
}
