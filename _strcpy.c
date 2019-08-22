#include "shell.h"

void _strcpy(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i <= n; i++)
		s1[i] = s2[i];
}
