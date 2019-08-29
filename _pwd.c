#include "shell.h"

/**
 * _pwd - print working directory
 * @argc: Number of arguments
 * @l: input line
 * @args: Multidimensional array of arguments
 * @env_s: Environment linked list
 * Return: Always 0 (Success) or -1 otherwise
 */
int _pwd(UN int argc, UN char *l, UN char **args, node_t **env_s)
{
	char *ptr;

	ptr = _getenv("PATH", env_s);

	if (ptr == NULL)
	{
		write(STDERR_FILENO, "./hsh: 1: No such enviroment\n", 30);
		return (-1);
	}

	free(ptr);

	return (0);
}
