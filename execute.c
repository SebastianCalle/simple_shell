#include "shell.c"

int execute(char **args)
{
	pid_t pid;
	int status, i;

	pid = fork();
	if (pid == 0) {
		if ((i = _proexec(args)) == -1) {
			perror("sh");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		perror("sh");
	} else {
		while (!WIFEXITED(status) && !WIFSIGNALED(status)){
			waitpid(pid, &status, WUNTRACED);
		}
	}

	return (1);
}
