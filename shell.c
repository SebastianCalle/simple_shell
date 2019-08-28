#include "shell.h"

static node_t *env_s;
static node_t *path_s;
/**
 * core_shell - linked core of shell
 * @arg: String of the command
 * Return: 0 on succes or -1 otherwise
 */
int (*core_shell(char *arg))(int argc, char *l, char **args, node_t **link)
{

	int i;
	core_t core[] = {
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
int check_line(char *line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] > 32 && line[i] < 126)
			return (0);
		i++;
	}
	return (1);
}

/**
 * main - Entry point
 * Return: 0 on success and diferrent of 0 otherwise
 */
int main(void)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1, j = 0, i, flag = 0, argc = 0, status2 = 1;

	_listed_env(&env_s);
	while (status2)
	{
		signal_h();
		_puts("(o O) ");
		line = read_line(&flag, env_s, path_s);
		if (check_line(line) == 1)
		{
			free(line);
			continue;
		}
		j = 0;
		args = _strtok(line, &j);
		for (argc = 0; args[argc]; argc++)
			;
		core_shell(args[0])(argc, line, args, &env_s);
		_exit_shell(line, args, &status);
		status = execute(args, line, &env_s, &path_s);
		status2 = status;
		i = 0;
		if (flag == 1)
		{
			free_all2(args, line);
			break;
		}
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
		if (status == 0)
			status2 = 1;
	}
	return (0);
}

/**
 * free_all2 - function that free memory
 * @args: argumentos to free
 * @line: string to free
 */
void free_all2(char **args, char *line)
{
	int i = 0;

	while (args[i])
	{
		if (args[i])
			free(args[i]);
		i++;
	}
	if (args != NULL)
		free(args);
	if (line != NULL)
		free(line);
	_free_list(env_s);
	_free_list(path_s);
}
