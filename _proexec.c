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
				*status = execve(buff, argv, environ);
				closedir(dir), free(buff), free(path);
				return (*status);
			}
		}
		temp = temp->next;
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
	int status, i = 0, j, y = 0;
	node_t *temp = NULL;
	char *path = _getenv("PATH"), **tok = _strtok(path, &y);

	i = _strcmp(argv[0], "env"), j = _strcmp(argv[0], "setenv");
	if (argv[0][0] == '/')
	{
		status = execve(argv[0], argv, environ);
		return (status);
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
	return (-1);
}
