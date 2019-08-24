#include "shell.h"
/**
 * _getchar - read the line
 * Return: the character read
 */
int _getchar(void)
{
	char c;

	if ((read(STDIN_FILENO, &c, sizeof(char))) == 1)
		return (c);

	return (EOF);
}
