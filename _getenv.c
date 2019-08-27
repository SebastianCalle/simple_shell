#include "shell.h"

/**
 * _getenv - function searches the environment list
 * @env: variable to find
 * Return: the buffer
 */
char *_getenv(char *env, node_t **env_s)
{
	node_t *temp = *env_s;
	char *buff;
	int i, j, k = 0;

	while (temp)
	{
		if (temp->s[0] == env[0])
		{
			for (i = 0; temp->s[i] != '='; i++)
			{
				if (temp->s[i] != env[i])
					break;
				if (temp->s[i + 1] == '=')
					k = 1;
			}
		}
		i++;
		if (k == 1)
			break;
		else if (temp->next == NULL)
			return (NULL);
		temp = temp->next;
	}
	if (k != 1)
		return (NULL);

	for (j = i; temp->s[i]; i++)
		;

	buff = malloc(sizeof(char) * (i + 1));
	if (buff == NULL)
	{
		write(STDERR_FILENO, "Cannot allocate memory\n", 24);
		return (NULL);
	}

	for (k = 0; j <= i; j++, k++)
		buff[k] = temp->s[j];

	return (buff);
}
