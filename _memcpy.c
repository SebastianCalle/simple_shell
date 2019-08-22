#include "shell.h"

void *_memcpy(char *dest, char *src, int n)
{
	char *d = dest, *s = src;

	while (n--)
		*d++ = *s++;

	return (dest);
}
