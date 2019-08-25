#include "shell.h"

/**
 * _memcpy - Function that copies n bytes of memory
 * @dest: Destiny string
 * @src: Source string
 * @n: Number of bytes
 * Return: a pointer to string
 */
void *_memcpy(char *dest, char *src, int n)
{
	char *d = dest, *s = src;

	while (n--)
		*d++ = *s++;

	return (dest);
}
