#include "shell.h"

int _getline(char **b, unsigned int n)
{
        char *buff = *b;
	static int status, c, i = 0;

	while (n > 0 && (c = _getchar()) != EOF && c != '\n')
	{
		*(buff + i) = c;
		i++;
	}

	*(buff + i) = '\0';

	return (i);
}
