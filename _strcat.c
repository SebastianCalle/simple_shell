#include "shell.h"

char *_strcat(char *dest, char *src)
{
	int i, j, k, l;

	i = _strlen(dest);
	j = _strlen(src);

	for (k = i, l = 0; k < i + j; k++, l++)
		dest[k] = src[l];

	dest[k] = '\0';

	return (dest);
}
