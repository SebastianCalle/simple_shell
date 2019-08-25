#include "shell.h"

/**
 * _strcat - Function that concatenates two strings
 * @dest: Destiny string
 * @src: Source string
 * Return: A concatenate string or NULL if ir fails
 */
char *_strcat(char *dest, char *src)
{
	int i, j, k, l;

	if (dest == NULL || src == NULL)
		return (NULL);

	i = _strlen(dest);
	j = _strlen(src);

	for (k = i, l = 0; k < i + j; k++, l++)
		dest[k] = src[l];

	dest[k] = '\0';

	return (dest);
}
