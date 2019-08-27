#include "shell.h"

/**
 * read_line - read the line of function getline
 * Return: the line to read
 */
char *read_line(void)
{
	char *line = NULL;

	if (_getline(&line) <= 0)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		//_free_list(env_s);
		//_free_list(path_s);
		free(line);
		exit(98);
	}
	fflush(stdin);
	return (line);
}
