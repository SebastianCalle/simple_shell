#include "shell.h"

int _getchar(void)
{
	char c;

	if ((read(STDIN_FILENO, &c, sizeof(char))) == 1)
		return (c);

	return (EOF);
}
