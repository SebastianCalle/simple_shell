#include <unistd.h>
/**
 * _putchar - writes the character c to std out.
 * @c: the character to print
 * Return: 1 on success.
 * on error, -1
 */
int _putchar(char c)
{
	return (write(STDIN_FILENO, &c, 1));
}
