#include "shell.h"

int main(void)
{
	char *line;
	char **args;
	int status = 1, j = 0, i, c = 0;

	env();
	while (status)
	{
		line = read_line();
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		j = 0;
		args = _strtok(line, &j);
		c = check_case(args, line);
		if(c == 1)
			continue;
		status = execute(args);
		i = 0;
		while (args[i] != NULL)
		{
			if (args[i])
				free(args[i]);
			i++;
		}
		if (line != NULL)
			free(line);
		if (args != NULL)
			free(args);

	}
	return(0);
}
