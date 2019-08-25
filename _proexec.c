#include "shell.h"

/**
 * _checkexec - Function that checks te arguments or proexec
 * @argv: Multidimensional array to be checked
 * Return: 0 on success or -1 if it fails
 */
int _checkexec(char **argv)
{
	int i, j, k, l, m, status;

	i = _strcmp(argv[0], "env"), j = _strcmp(argv[0], "setenv");
	k = _strcmp(argv[0], "getenv"), l = _strcmp(argv[0], "cd");
	m = _strcmp(argv[0], "unsetenv");

	if (argv[0][0] == '/')
	{
		status = execve(argv[0], argv, environ);
		return (status);
	}
	else if (i == 0 || j == 0 || k == 0 || m == 0 || l == 0)
		return (0);
	return (-1);
}

/**
 * _proexec - Function that handles the standard input
 * @argv: Multidimensional array of the standard input
 * Return: 0 on success and -1 on failure
 */
int _proexec(char **argv)
{
	struct dirent *fil = NULL;
	DIR *dir = NULL;
	int st, i, len, y = 0;
	node_t *temp = NULL;
	char *b, *p = _getenviron("PATH"), **tok = _strtok(p, &y), *s = "/";

	st = _checkexec(argv);
	if (st == 0)
		return (0);
	for (i = 0; tok[i]; i++)
	{
		if (p[0] == ':' && i == 0)
			_add_node_end(&path_s, _getenviron("PWD"));
		_add_node_end(&path_s, tok[i]);
	}
	temp = path_s;
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
				b = malloc(len);
				if (b == NULL)
					return (-1);
				for (i = 0; i < len; i++)
					b[i] = 0;
				b = _strcat(b, temp->s), b = _strcat(b, s);
				b = _strcat(b, fil->d_name), st = execve(b, argv, environ);
				closedir(dir), free(b), free(p);
				return (st);
			}
		}
		temp = temp->next;
	}
	return (-1);
}
