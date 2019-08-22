#include "shell.h"

int _strlen(char *s)
{
	int i;

	if (s == NULL)
		return (-1);
	for (i = 0; s[i]; i++)
		;

	return (i);
}
