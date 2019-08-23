#include "shell.h"

int _proexec(char **argv)
{
	//char *argv[] = {"rm", "PATH.c~", NULL};
	char *buff, *path = _getenv("PATH"), *tok = strtok(path, ":"), *slash = "/";
	struct dirent *fil;
	DIR *dir;
	int status;

	if (argv[0][0] == '/')
	{
		status = execve(argv[0], argv, environ);
		return (status);
	}
	else if (_strcmp(argv[0], "env") == 0)
		return (0);
	while (tok)
	{
		dir = opendir(tok);
		if (dir == NULL)
			return (-1);
	        while ((fil= readdir(dir)))
		{
			if ((_strcmp(fil->d_name, argv[0])) == 0)
			{
			        buff = malloc(_strlen(fil->d_name) + _strlen(argv[0]) + 3);
				if (buff == NULL)
					return (-1);
				buff = _strcat(tok, slash);
				buff = _strcat(buff, fil->d_name);
				argv[0] = buff;
				status = execve(argv[0], argv, environ);
				closedir(dir);
				free(buff);
				free(path);
				return (status);
			}
		}
	      	tok = strtok(NULL, ":");
	}

	return (-1);
}
