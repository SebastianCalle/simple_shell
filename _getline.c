 
#include "shell.h"

char *_getline(void)
{
        char buff[SIZE];
	char *b = buff;
	static int c, i = 0;

	while ((c = _getchar()) != EOF && c != '\n')
	{
		*(b + i) = c;
		i++;
	}

	*(b + i) = '\0';

	return (b);
}
