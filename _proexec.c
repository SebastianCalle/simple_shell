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
				status2 = execve(buff, argv, NULL);
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
 * free_all - Function that frees the malloc
 * @argv: Multidimensional string of arguments
 * @path: Environment path
 * @tok: Tokens of path
 * @line: input line
 * @path_s: path linked list
 * Return: 0 on succes or -1 otherwise
 */
int free_all(char **argv, char *path, char **tok, char *line, node_t *path_s)
{
	struct stat st;
	int i;

	if (stat(argv[0], &st) != 0)
	{ free(path);
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
		free(line);
		free(argv);
		_free_list(path_s);
		return (-1);
	}
	return (0);
}

/**
 * _proexec - function that execute the arguments
 * @argv: arguments parameters
 * @line: input line
 * @path_s: path linked list
 * Return: status or -1 if not succes
 */
int _proexec(char **argv, char *line, node_t **path_s)
{
	pid_t pid;
	int status, i = _strcmp(argv[0], "env"), j, y = 0, k, l, m;
	node_t *temp = NULL;
	char *path = _getenviron("PATH"), **tok = _strtok(path, &y);

	j = _strcmp(argv[0], "setenv"), k = _strcmp(argv[0], "getenv");
	l = _strcmp(argv[0], "cd"), m = _strcmp(argv[0], "unsetenv");
	if (argv[0][0] == '/')
	{
		pid = fork();
		if (pid == 0)
		{
			status = execve(argv[0], argv, NULL);
			return (status);
		}
		if (pid < 0)
			perror("./hsh: 1");
		else
			waitpid(pid, &status, WUNTRACED);
		for (i = 0; tok[i]; i++)
			free(tok[i]);
		free(tok), free(path);
		return (status);
	}
	else if (i == 0 || j == 0 || m == 0 || k == 0 || l == 0)
	{
		for (i = 0; tok[i]; i++)
			free(tok[i]);
		free(tok), free(path);
		return (0);
	}
	for (i = 0; tok[i]; i++)
	{
		if (path[0] == ':' && i == 0)
			_add_node_end(path_s, _getenviron("PWD"));
		_add_node_end(path_s, tok[i]);
	}
	temp = *path_s, temp_function(temp, &status, argv, path);
	free_all(argv, path, tok, line, *path_s);
	return (-1);
}
