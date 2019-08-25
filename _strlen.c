#include "shell.h"
/**
 * _strlen - function that count the lenght of string
 * @s: string to count
 * Return: the size of string
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
