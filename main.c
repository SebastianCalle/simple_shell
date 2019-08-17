#include "shell.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
	char *buff;
        unsigned int i;

        write(STDOUT_FILENO, "$ ", 2);
	buff = _getline();
        for (i = 0; buff[i]; i++)
		write(STDOUT_FILENO, &buff[i], 1);

        _putchar(10);

	return (0);
}
