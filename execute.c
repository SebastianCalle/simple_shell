#include "shell.h"
/**
 * execute - function that execute the commands
 * @args: commands to execute
 * @line: input line
 * @path_s: path linked list
 * Return: 1 if is succes
 */
int execute(char **args, char *line, node_t **path_s)
{
	pid_t pid;
	int status, status2;

	pid = fork();
	if (pid == 0)
	{
		if ((_proexec(args, line, path_s)) == -1)
		{
			perror("sh");
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
