#include "shell.h"
/**
 * _isdigit - Print if a character is uppercase
 * Return: 0
 * @c: input a character
 */
int _isdigit(int c)
{
	int a;

	if (c >= 48 && c <= 57)
		a = 1;
	else
		a = 0;

	return (a);
}
