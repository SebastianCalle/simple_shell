 
#include "shell.h"

char *_geiitline(void)
{
        char buff[SIZE];
	char *b = buff;
	static int c;
	int i = 0;

	while ((c = _getchar()) != EOF && c != '\n')
	{
		*(b + i) = c;
		i++;
	}

	*(b + i) = '\0';

	return (b);
}
