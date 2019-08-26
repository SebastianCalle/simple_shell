#include "shell.h"

/**
 * read_line - read the line of function getline
 * Return: the line to read
 */
char *read_line(int *flag)
{
	char *line = NULL;
	int f;

	f = _getline(&line);

	if (f <= 0)
	{
		if (f == -2)
		{
			*flag = 1;
			fflush(stdin);
			return (line);
			
		}
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		_free_list(env_s);
		_free_list(path_s);
		free(line);
		exit(98);
	}
	fflush(stdin);
	return (line);
}
