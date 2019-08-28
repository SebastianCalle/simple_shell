#include "shell.h"

/**
 * read_line - read the line of function getline
 * @flag: flag of function
 * @env_s: environment linked list
 * Return: the line to read
 */
char *read_line(int *flag, node_t *env_s, node_t *path_s)
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
		_free_list(env_s);
		_free_list(path_s);
		free(line);
		exit(98);
	}
	fflush(stdin);
	return (line);
}
