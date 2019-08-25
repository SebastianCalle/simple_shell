#include "shell.h"

node_t *env_s;
node_t *path_s;
/**
 * main - Entry point
 * Return: 0 on success and diferrent of 0 otherwise
 */
int main(void)
{
	char *line;
	char **args;
	int status = 1, j = 0, i;

	_listed_env();
	while (status)
	{
		signal_h();
		_puts("(o-o) ");
		line = read_line();
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		j = 0;
		args = _strtok(line, &j);
		check_case(args, line);
		status = execute(args);
		i = 0;
		while (args[i] != NULL)
		{
			if (args[i])
				free(args[i]);
			i++;
		}
		if (args != NULL)
			free(args);
		if (line != NULL)
			free(line);
	}
	return (0);
}
