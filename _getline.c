 #include "shell.h"

int _getline(char **buff)
{
        static char b[SIZE], *ptr;
	int len, i;
	char c;

	for (i = 0; i < SIZE; i++)
		b[i] = 0;

	for (i = 0; (c = _getchar()) != '\n'; i++)
	{
		if (c == EOF)
			return (-1);
		b[i] = c;
	}
	b[i] = '\n';
	b[i + 1] = '\0';

	len = _strlen(b);
	ptr = NULL;

	ptr = _realloc(*buff, SIZE);
	if (ptr == NULL)
		return (-1);
	for (i = 0; i < SIZE; i++)
		ptr[i] = 0, (*buff) = 0;
        //ptr[i] = '\n';
        *buff = ptr;
        _strcpy(*buff, b);

	return (len);
}
