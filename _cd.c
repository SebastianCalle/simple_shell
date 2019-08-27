#include "shell.h"

/**
 * _cd - Function that creates the command cd
 * @argc: Number of arguments
 * @args: Multidimensional array of arguments
 * @env_s: Environment linked list
 * Return: Always 0 (Success) or -1 otherwise
 */
int _cd(int argc, UN char *l, char **args, node_t **env_s)
{
	char *pwd = _getenv("PWD", env_s), *opwd = _getenv("OLDPWD", env_s);
	char *home = _getenv("HOME", env_s);
	char a[100];

	if (argc > 2)
	{
		write(STDERR_FILENO, "./hsh: 1: Number of arguments is wrong\n", 39);
		return (-1);
	}
	if (args[1] == NULL)
	{
		chdir(home);
		_setenv1("OLDPWD", pwd, env_s), _setenv1("PWD", home, env_s);
		free(pwd), free(opwd), free(home);
		return (0);
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		chdir(opwd);
		_setenv1("OLDPWD", pwd, env_s), _setenv1("PWD", opwd, env_s);
		_puts(getcwd(a, 100)), _putchar(10);
		free(pwd), free(opwd), free(home);
		return (0);
	}
	else if (chdir(args[1]) == -1)
	{
		write(STDERR_FILENO, "./hsh: 1: No such file or directory\n", 36);
		free(pwd), free(opwd), free(home);
		return (-1);
	}
	_setenv1("OLDPWD", pwd, env_s);
	if (_strcmp(args[1], "..") == 0)
		_setenv1("PWD", getcwd(a, 100), env_s);
	else
		_setenv1("PWD", args[1], env_s);

	free(pwd), free(opwd), free(home);
	return (0);
}
