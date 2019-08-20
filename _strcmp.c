#include "shell.h"

int _strcmp(char *s1, char *s2)
{
	int i, n;

	for (i = 0; s1[i] || s2[i]; i++)
	{
		if (s1[i] == s2[i])
			n = 0;
		else
		{
			n = s1[i] - s2[i];
			break;
		}
	}

	return (n);
}
