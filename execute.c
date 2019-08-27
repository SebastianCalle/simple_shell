#include "shell.h"
/**
 * execute - function that execute the commands
 * @args: commands to execute
 * Return: 1 if is succes
 */
int execute(char **args, char *line)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if ((_proexec(args, line)) == -1)
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
