#include "main.h"
/**
 * _atoi - convert a string to an integer
 * @s: the parameter to be used
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
	int cu = 0;
	unsigned int ni = 0;
	int sign = 1;
	int num = 0;

	while (s[cu])
	{
	if (s[cu] == 45)
	{
		sign *= -1;
	}
	while (s[cu] >= 48 && s[cu] <= 57)
	{
		num = 1;
		ni = (ni * 10) + (s[cu] - '0');
		cu++;
	}
		if (num == 1)
		{
			break;
		}
		cu++;
	}
	ni *= sign;
	return (ni);
}
