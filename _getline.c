#include "shell.h"

/**
 * _getline - read line from stdin
 * @buff: buff to modificate
 * Return: the len of string to read
 */
int _getline(char **buff)
{
	static char b[SIZE];
	char *ptr = NULL;
	int len, i, flag = 0;
	char c;

	for (i = 0; (c = _getchar()) != '\n'; i++)
	{
		if (c == EOF && i > 0)
		{
			flag = 1;
			break;

		}
		if (c == EOF && i == 0)
		{
			return (-1);
		}
		b[i] = c;
	}
	b[i] = '\n';
	b[i + 1] = '\0';

	len = _strlen(b);
	ptr = _realloc(*buff, SIZE);
	if (ptr == NULL)
	{
		return (-1);
	}
	for (i = 0; i < SIZE; i++)
		ptr[i] = 0, (*buff) = 0;
	*buff = ptr;
	_strcpy(*buff, b);
	if (flag == 1)
		return (-2);
	return (len);
}
