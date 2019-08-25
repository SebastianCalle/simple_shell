#include "shell.h"

/**
 * _strcat - appends the string
 * @dest: destine append
 * @src: source append
 * Return: destine pointer
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
