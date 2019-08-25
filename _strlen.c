#include "shell.h"

/**
 * _strlen - Function that calculates the length of string
 * @s: String to be checked
 * Return: The length of string or -1 if it fails
 */
int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (-1);
	for (; s[i]; i++)
		;

	return (i);
}
