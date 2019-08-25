#include "shell.h"

char *read_line(void)
{
	char *line = NULL;
	size_t i;

	if (getline(&line, &i, stdin) <= 0)
	{
	if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(98);
	}
	fflush(stdin);
	return (line);
}
