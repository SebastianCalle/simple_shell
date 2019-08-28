#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 always
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	char *ss;

	if (s1 == NULL || s2 == NULL)
		return (-1);


	ss = (_strlen(s1) > _strlen(s2)) ? s1 : s2;
	for (i = 0; ss[i] != '\0'; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
