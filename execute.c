#include "shell.h"
/**
 * execute - function that execute the commands
 * @args: commands to execute
 * Return: 1 if is succes
 */
int execute(char **args)
{
	pid_t pid;
	int status = 1;

	pid = fork();
	if (pid == 0)
	{
		if ((_proexec(args)) == -1)
			perror("sh");
		free(args[0]);
		exit(99);
	}
	else if (pid < 0)
	{
		perror("sh");
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}

	return (1);
}
