#include "shell.h"
/**
 * execute - function that execute the commands
 * @args: commands to execute
 * Return: 1 if is succes
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if ((_proexec(args)) == -1)
			write(STDERR_FILENO, "./hsh: 1: No such file or directory\n", 36);
		free(args[0]);
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
