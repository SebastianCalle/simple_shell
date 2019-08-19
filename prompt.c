#include "shell.c"
#define BUFFER 1024

char *_getline(int *fl)
{
	int f = 1;
	ssize_t i = 0;
	int bufsize = BUFFER;
	char *buf = malloc(sizeof(char) * bufsize);

	if (*fl == 1)
	{
		free(buf);
		return(NULL);
	}
	if (!buf)
		return (NULL);
	while (f)
	{
		i = read(STDIN_FILENO, buf, BUFFER);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		if (i >= bufsize)
		{
			bufsize += BUFFER;
			buf = realloc(buf, bufsize);
			if (!buf)
			{
				fprintf(stderr, "s: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		if (i < BUFFER)
			f = 0;
	}
	buf[i-1] = '\0';
	return (buf);
}
