#include "shell.h"

void *_realloc(void *ptr, int size)
{
	char *a;
	int i;

        if (ptr == NULL)
	{
		a = malloc(size);
		if (a == NULL)
			return (NULL);
		return (a);
	}
	else if (size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	a = malloc(size);
	if (a == NULL)
		return (NULL);

	for (i = 0; i < size - 1 && ((char *)ptr)[i]; i++)
		a[i] = ((char *)ptr)[i];

	free(ptr);

	return (a);
}