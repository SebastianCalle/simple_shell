#include "shell.h"

/**
 * _realloc - Function that reallocated a block of memory
 * @ptr: Pointer of memory to be reallocated
 * @size: New size
 * Return: A new pointer reallocated or NULL if it fails
 */
void *_realloc(void *ptr, int size)
{
	char *a;
	int i;

	if (ptr == NULL)
	{
		a = malloc(size);
		if (a == NULL)
		{
			write(STDERR_FILENO, "Cannot allocate memory\n", 24);
			return (NULL);
		}
		return (a);
	}
	else if (size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	a = malloc(size);
	if (a == NULL)
	{
		write(STDERR_FILENO, "Cannot allocate memory\n", 24);
		return (NULL);
	}

	for (i = 0; i < size - 1 && ((char *)ptr)[i]; i++)
		a[i] = ((char *)ptr)[i];

	free(ptr);

	return (a);
}
