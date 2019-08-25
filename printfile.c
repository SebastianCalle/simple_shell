#include "shell.h"

/**
 * printfile - Function that print an file
 * @filename: Name of the file
 * Return: 0 on Success or -1 if fails
 */
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
