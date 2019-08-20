#include "shell.h"

char *_getenv(char *env)
{
	char *buff;
	int i, j, k, l, sw;

	for (i = 0, sw = 0; environ[i]; i++)
	{
		if (environ[i][0] == env[0])
		{
			for (j = 0; environ[i][j] != '='; j++)
			{
				if (environ[i][j] != env[j])
					break;
				if (environ[i][j + 1] == '=')
					sw = 1;
			}
			j++;
			if (sw == 1)
				break;
		}
	}

	for (k = 0; environ[i][k] != '\0'; k++)
		;

	buff = malloc(sizeof(char) * (k + 1));
	if (buff == NULL)
		return (NULL);

	for (l = 0; l <= k; l++, j++)
		buff[l] = environ[i][j];

	return (buff);
}
