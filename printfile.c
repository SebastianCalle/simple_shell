#include "shell.h"
/**
 * printfile - function that print the file
 * @filename: name of the file to print
 * Return: 0 if is suscces
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
