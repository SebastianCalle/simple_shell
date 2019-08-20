#include "shell.h"

//void prompt(void)
//{
//
//	write(1, "$ ", 2);
//}
int main(void)
{
	char *line;
	char **args;
	int status = 1, j = 0, i;


	while (status)
	{
		write(1, "$ ", 2);
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
		if (line != NULL)
			free(line);
		if (args != NULL)
			free(args);

//		prompt();
	}
	return(0);
}
