#include "shell.h"
/**
 * _strtok - split the string in tokens
 * @str: string to split
 * @delim: character delimitator
 * Return: linked list
 */
char **_strtok(char *buffer, int *n)
{
	char **args = NULL;
	int a = 0, cl = 0, k, in, j;
	int index = 0, i = 0;

	a = count_arg(buffer);
	args = malloc(sizeof(char *) * (a + 1));
	if (args == NULL)
		return (NULL);
	args[a] = NULL;
	for (j = *n; j < a; j++)
	{
		cl = count_letters(buffer, &index, &i);
		args[j] = malloc(sizeof(char) * (cl + 1));
		if (args[j] == NULL)
			return (NULL);
		k = 0;
		in = index;
		while(k < cl)
		{
			if (buffer[in] == '\n')
				break;
			args[j][k] = buffer[in];
			k++;
			in++;
		}
		args[j][k] = '\0';
	}
	*n = j;
	return (args);
}
