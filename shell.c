#include "shell.h"

int main(void)
{
	char *line;
	char **args;
	int status = 1, j = 0, fl;

	while (status)
	{
		fl = 0;
		line = _getline(&fl);
		args = _strtok(line, &j);
		status = execute(args);

		j = 0;
		free(line);
		free(*args);
		free(args);

	}
	return(0);
}
