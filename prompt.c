#include "shell.h"
#define BUFFER 1024

void _gettttline(char *buf)
{
	int f = 1;
	ssize_t i = 0;
	int bufsize = BUFFER;
	buf = malloc(sizeof(char) * bufsize);

	if (!buf)
	{
		perror("Allocation error\n");
		exit(99);
	}
	while (f)
	{
		i = read(STDIN_FILENO, buf, BUFFER);
		if (i == -1)
		{
			free(buf);
			perror("Read lecture error\n");
			exit(95);
		}
		if (i >= bufsize)
		{
			bufsize += BUFFER;
			buf = realloc(buf, bufsize);
			if (!buf)
			{
				perror("Allocation error\n");
				exit(99);
			}
		}
		if (i < BUFFER)
			f = 0;
	}
	buf[i-1] = '\0';
}
