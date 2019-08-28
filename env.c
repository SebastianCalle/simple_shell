#include "shell.h"
/**
 * env - create the file enviroment
 * Return: 1 if suscces
 */
int env(void)
{
	char *filename = "env";
	int fd, i, j;

	if (environ == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd == -1)
		return (-1);

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			;

		write(fd, environ[i], j);
		write(fd, "\n", 1);
	}

	close(fd);

	return (1);
}
