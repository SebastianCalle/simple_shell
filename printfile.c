#include "shell.h"

int printfile(char *filename)
{
	int fd, rd;
	char buff[SIZE];

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);

	while ((rd = read(fd, buff, SIZE)) != 0)
		write(1, buff, rd);

	return (0);
}
/*
int main(int argc, char **argv)
{
	if (argc > 3)
		return (1);

	printfile(argv[1]);

	return (0);
}
*/
