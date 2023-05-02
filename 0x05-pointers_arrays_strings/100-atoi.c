#include "main.h"
/**
 * _atoi - convert a string to an integer
 * @s: the parameter to be used
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
	int sign = 1;
	int num = 0;

	while (*s == ' ')
	{
		s++;
	}
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
	{
		s++;
	}
	while (*s != '\0')
	{
		if (*s >= '0' || *s <= '9')
		{
			return (sign * num);
		}
		num = num * 10 + (*s - '0');
		s++;
	}
	return (sign * num);
}
