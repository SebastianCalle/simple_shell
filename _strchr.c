#include "shell.h"

/**
 * _strchr - Function that searchs a character
 * @s: String to be checked
 * @c: Character to be checked
 * Return: An string in the position of the character or NULL if it fails
 */
char *_strchr(char *s, char c)
{
	if (s == NULL)
		return (NULL);

	while (*s++ != c)
		if (*s == '\0')
			return (NULL);

	return (s);
}
