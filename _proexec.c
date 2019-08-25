#include "shell.h"
/**
 * temp_function - function that execute the nodes
 * @temp: node temporal
 * @status: status of program
 * @argv: arguments to execute
 * @path: path of directory
 * Return: status of program
 */
int temp_function(node_t *temp, int *status, char **argv, char *path)
{
	int status2 = *status;
	DIR *dir = NULL;
	struct dirent *fil = NULL;
	int len, i;
	char *buff = NULL, *slash = "/";

	while (temp)
	{
		dir = opendir(temp->s);
		if (dir == NULL)
			return (-1);
		while ((fil = readdir(dir)))
		{
			if ((_strcmp(fil->d_name, argv[0])) == 0)
			{
				len = _strlen(fil->d_name) + _strlen(temp->s) + 3;
				buff = malloc(len);
				if (buff == NULL)
					return (-1);
				for (i = 0; i < len; i++)
					buff[i] = 0;
				buff = _strcat(buff, temp->s), buff = _strcat(buff, slash);
				buff = _strcat(buff, fil->d_name);
				status2 = execve(buff, argv, environ);
				closedir(dir), free(buff), free(path);
				return (status2);
			}
		}
		temp = temp->next;
		free(dir);
	}
	return (0);

}
/**
 * _proexec - function that execute the arguments
 * @argv: arguments parameters
 * Return: status or -1 if not succes
 */
int _proexec(char **argv)
{
	pid_t pid;
	int status, i = 0, j, y = 0;
	node_t *temp = NULL;
	char *path = _getenv("PATH"), **tok = _strtok(path, &y);
	struct stat st;

	i = _strcmp(argv[0], "env"), j = _strcmp(argv[0], "setenv");
	if (argv[0][0] == '/')
	{
		pid = fork();
		if (pid == 0)
		{
			status = execve(argv[0], argv, environ);
			return (status);
		}
		if (pid < 0)
			perror("sh:");
		else
			waitpid(pid, &status, WUNTRACED);
	}
	else if (i == 0 || j == 0 || _strcmp(argv[0], "unsetenv") == 0)
		return (0);
	for (i = 0; tok[i]; i++)
	{
		if (path[0] == ':' && i == 0)
			_add_node_end(&path_s, _getenv("PWD"));
		_add_node_end(&path_s, tok[i]);
	}
	temp = path_s;
	temp_function(temp, &status, argv, path);
	if (stat(argv[0], &st) != 0)
	{
		free(path);
		for (i = 0; tok[i]; i++)
		{
			if (tok[i])
				free(tok[i]);
		}
		for (i = 0; argv[i]; i++)
		{
			if (argv[i])
				free(argv[i]);
		}
		free(tok);
		free(argv);
		_free_list(environ_s);
		_free_list(path_s);
		return (-1);
	}

	return (-1);
}
