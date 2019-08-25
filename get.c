#include "shell.h"

/**
 * read_line - Function that read a line input
 * Return: the line input
 */
char *read_line(void)
{
	char *line = NULL;

	if (_getline(&line) <= 0)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(98);
	}
	fflush(stdin);
	return (line);
}
