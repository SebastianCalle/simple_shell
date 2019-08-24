#include "shell.h"

int _strlen(char *s)
{
	int i = 0;

	if (s == NULL)
		return (-1);
	for (; s[i]; i++)
		;

	return (i);
}
