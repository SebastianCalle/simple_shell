#include "shell.h"

static node_t *env_s;
static node_t *path_s;

/**
 * no_inter - Function thats configurate executable with argument
 * @ac: Number of arguments
 * @av: Multidimensional array of arguments
 * Return: Always 0 Success
 */
int no_inter(int ac, char **av)
{
	int i, j;
	char **argv;

	argv = malloc(ac);
	if (argv == NULL)
		return (-1);

	for (i = 1; av[i]; i++)
	{
		for (j = 0; av[i][j]; j++)
			;
		argv[i - 1] = _strdup(av[i]);
	}

	execve(argv[0], argv, NULL);

	return (0);
}


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
		{"pwd", _pwd},
		{NULL, NULL}
	};

	for (i = 0; core[i].str; i++)
		if (_strcmp(core[i].str, arg) == 0)
			return (core[i].f);

	return (no_found);
}

/**
 * check_line - Function that checks a line
 * @line: line string
 * Return: 0 on success or -1 otherwise
 */
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
 * @ac: Number of arguments
 * @av: Multidimensiona array of arguments
 * Return: 0 on success and diferrent of 0 otherwise
 */
int main(int ac, char **av)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1, j = 0, i = 0, flag = 0, argc = 0, status2 = 1;

	_listed_env(&env_s);
	if (ac == 1)
		for (; status2; j = 0)
		{
			signal_h(), _puts("(o O) ");
			line = read_line(&flag, env_s, path_s);
			if (check_line(line) == 1)
			{
				free(line);
				continue;
			}
			args = _strtok(line, &j);
			for (argc = 0; args[argc]; argc++)
				;
			core_shell(args[0])(argc, line, args, &env_s);
			_exit_shell(line, args, &status);
			status = execute(args, line, &env_s, &path_s), status2 = status;
			if (flag == 1)
			{
				free_all2(args, line);
				break;
			}
			for (i = 0; args[i] != NULL; i++)
				if (args[i])
					free(args[i]);
			if (args != NULL)
				free(args);
			if (line != NULL)
				free(line);
			(status == 0) ? status2 = 1 : status;
		}
	else if (ac > 1 && av != NULL)
		no_inter(ac, av);
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
	args = NULL;
	_free_list(env_s);
	_free_list(path_s);
}
