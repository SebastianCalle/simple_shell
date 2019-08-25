#include "shell.h"

/**
 * _memcpy - copies n characters from memory src to dest
 * @dest: string to destine
 * @src: string source
 * @n: bytes to copy
 * Return: pointer to new string
 */
void *_memcpy(char *dest, char *src, int n)
{
	char *d = dest, *s = src;

	while (n--)
		*d++ = *s++;

	return (dest);
}
