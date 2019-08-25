#include "shell.h"
/**
 * _strchr - searches for the first ocrrurence of character
 * @s: string to search
 * @c: character to find
 * Return: the pointer to the first ocurrence
 */
char *_strchr(char *s, char c)
{
	while (*s++ != c)
		if (*s == '\0')
			return (NULL);

	return (s);
}
