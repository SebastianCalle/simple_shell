#include "shell.h"

/**
 * _cd - Function that creates the command cd
 * @dir: directory to be checked
 * Return: Always 0 (Success) or -1 otherwise
 */
int _cd(char *dir)
{
	char *pwd = _getenv("PWD"), *opwd = _getenv("OLDPWD");
	char *home = _getenv("HOME");
	char a[100];

	if (_strcmp(dir, "-") == 0)
	{
		chdir(opwd);
		_setenv("OLDPWD", pwd);
		_setenv("PWD", opwd);
		_puts(getcwd(a, 100));
		_putchar(10);
		free(pwd), free(opwd), free(home);
		return (0);
	}
	else if (dir == NULL)
	{
		chdir(home);
		_setenv("OLDPWD", pwd);
		_setenv("PWD", home);
		free(pwd), free(opwd), free(home);
		return (0);
	}
	else if (chdir(dir) == -1)
	{
		perror("./hsh: 1");
		free(pwd), free(opwd), free(home);
		return (-1);
	}

	_setenv("OLDPWD", pwd);
	if (_strcmp(dir, "..") == 0)
		_setenv("PWD", getcwd(a, 100));
	else
		_setenv("PWD", dir);

	free(pwd), free(opwd), free(home);
	return (0);
}
