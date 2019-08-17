#include "shell.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
	char buff[32];
	char *b = buff;
	size_t i = 32;

        write(STDOUT_FILENO, "$ ", 2);
	_getline(&b, i);
	printf("%s\n", buff);

	return (0);
}
