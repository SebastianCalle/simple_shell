#include "shell.h"

int env(void)
{
        char *filename = "env";
        int fd, i, j;

        if (environ == NULL)
                return (-1);

        fd = open(filename, O_CREAT | O_WRONLY | O_EXCL, 0666);
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
/*
int main (void)
{
	env();

	return (0);
}
*/
