#include "shell.c"

char *read_line(void)
{
	char *line = NULL;
	size_t buf = 0;

	write(1, "$ ", 2);
	if (getline(&line, &buf, stdin) <= 0)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		exit(98);
	}
	return (line);
}
