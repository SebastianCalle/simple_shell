#include "shell.h"
/**
 * _atoi - convert sing to an integer
 * @s: recive parameter
 * Return: Return if es number
 */
int _atoi(char *s)
{
	int i, sign, num, brk;

	num = 0;
	brk = 0;
	sign = -1;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			num *= 10;
			num -= (s[i] - '0');
			brk = 1;
		}
		else if (brk == 1)
			break;
	}
	num *= sign;
	return (num);
}
