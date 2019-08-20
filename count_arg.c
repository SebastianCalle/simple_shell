#include "shell.h"
/**
 * check_del - verify if char is a delimiter
 * @c: first character
 * @b: character before
 * Return: 1 if match 0 if not
 */
int check_del(char c, char b)
{
	int i;
	const char *del = " \t\r\a\0";

	for (i = 0; del[i]; i++)
	{
		if (del[i] == b)
			return (0);
		if (del[i] == c)
			return (1);
	}
	return (0);
}
/**
 * count_letters - count the size of each argument
 * @str: string argument * @index: index of string
 * Return: the size of each argument
 */
int count_letters(char *str, int *index, int *l)
{
	int c = 0, flag = 0, j, i;
	const char *del = " \t\r\a\0\n";

	i = *l;
cont:
	while (str[i])
	{
		if (flag == 0)
		{
			if (str[i] > 32 && str[i] < 126)
			{
				*index = i;
				flag = 1;
				if (i > 0)
					c++;
			}
		}
		j = 0;
		while (del[j])
		{
			if (i > 0)
			{
				if (str[i - 1] == del[j])
				{
					i++;
					*l = i;
					goto cont;
				}

			}
			if (str[i] == del[j])
			{
				i++;
				*l = i;
				return (c);
			}
			j++;
		}
		c++;
		i++;
		*l = i;
	}
	return (c);
}
/**
 * count_arg - count number of arguments
 * @str: strint to count
 * Return: number of arguments
 */
int count_arg(char *str)
{
	int i, c = 0;

	for (i = 0; str[i]; i++)
	{
		if (i == 0)
		{
			c += check_del(str[i], str[i]);
			continue;

		}
		c += check_del(str[i], str[i - 1]);
	}
	if (str[i] == '\0')
	{
		if ((str[i - 1] > 32 && str[i - 1] < 126) || str[i - 1] == '\n')
			c++;
	}
	return (c);
}
