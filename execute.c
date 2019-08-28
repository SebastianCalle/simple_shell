#include "shell.h"
/**
 * execute - function that execute the commands
 * @args: commands to execute
 * @line: input line
 * @path_s: path linked list
 * Return: 1 if is succes
 */
int execute(char **args, char *line, node_t **env_s, node_t **path_s)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if ((_proexec(args, line, env_s, path_s)) == -1)
			perror("sh");
		exit(99);
	}
	else if (pid < 0)
	{
		perror("sh");
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (1);
}
