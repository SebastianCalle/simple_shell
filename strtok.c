#include "shell.h"
/**
 * _strtok - split the string in tokens
 * @str: string to split
 * @delim: character delimitator
 * Return: linked list
 */
char **_strtok(char *buffer)
{
	char **args = NULL;
	int a = 0, cl = 0, j, k, in;
	int index = 0, i = 0;

	a = count_arg(buffer);
	args = malloc(sizeof(char *) * (a + 1));
	if (args == NULL)
		printf("no sirvio");
	args[a] = NULL;
	for (j = 0; j < a; j++)
	{
		cl = count_letters(buffer, &index, &i);
		args[j] = malloc(sizeof(char) * (cl + 1));
		k = 0;
		in = index;
		while(k < cl)
		{
			args[j][k] = buffer[in];
			k++;
			in++;
		}
		args[j][k] = '\0';
	}
	return (args);
}
/*
int main(void)
{
	char *str = "Hola  mundo	hola      ";
	char **arg;

	arg = _strtok(str);
	


	return (0);
	
}
*/
