#include "shell.h"

/**
 * execute - function that execute the commands
 * @args: commands to execute
 * @line: input line
 * @path_s: env linked list
 * @env_s: path linked list
 * Return: 1 if is succes
 */
int execute(char **args, char *line, node_t **env_s, node_t **path_s)
{
	pid_t pid;
	int status, status2, i;
	char str[1024];

	for (i = 0; args[0][i]; i++)
		;
	_strcpy(str, args[0]);

	pid = fork();
	if (pid == 0)
	{
		if ((_proexec(args, line, env_s, path_s)) == -1)
		{
			write(STDERR_FILENO, "./hsh: 1: ", 10);
			write(STDERR_FILENO, str, i);
			write(STDERR_FILENO, ": not found\n", 12);
		}
		exit(127);
	}
	else if (pid < 0)
	{
		perror("sh");
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			status2 = WEXITSTATUS(status);
		}
	}

	return (status2);
}
