#include "shell.h"

/**
 * _realloc - function that reallocate memory
 * @ptr: pointer to do realloc
 * @size: size of new allocation
 * Return: the new pointer
 */
void *_realloc(void *ptr, int size, int oldsize)
{
	char *a;
	int i;

	if (oldsize < size)
		return (ptr);
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
