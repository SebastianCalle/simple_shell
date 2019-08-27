#include "shell.h"

static node_t *env_s;

/**
 * core_shell - linked core of shell
 * @arg: String of the command
 * Return: 0 on succes or -1 otherwise
 */
int (*core_shell(char *arg))(int argc, char *l, char **args, node_t **link)
{
	int i;
	core_t core[] = {
		{"exit", _exit_shell},
		{"env", _print_list},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", _cd},
		{NULL, NULL}
	};

	for (i = 0; core[i].str; i++)
		if (_strcmp(core[i].str, arg) == 0)
			return (core[i].f);

	return (no_found);
}

/**
 * main - Entry point
 * Return: 0 on success and diferrent of 0 otherwise
 */
int main(void)
{
	char *line;
	char **args = NULL;
	int status = 1, j = 0, i, flag = 0, argc = 0;

	_listed_env();
	while (status)
	{
		signal_h();
		_puts("(o-o) ");
		line = read_line(&flag, env_s);
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		j = 0;
		args = _strtok(line, &j);
		for (argc = 0; args[argc]; argc++)
			;
		core_shell(args[0])(argc, line, args, &env_s);
		status = execute(args, line);
		i = 0;
		while (args[i] != NULL)
		{
			if (args[i])
				free(args[i]);
			i++;
		}
		if (args != NULL)
			free(args);
		if (line != NULL)
			free(line);
		if (flag == 1)
			break;
	}
	return (0);
}

/**
 * _listed_env - create a linked list of enviroment
 */
void _listed_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		_add_node_end(&env_s, environ[i]);
	}
}
