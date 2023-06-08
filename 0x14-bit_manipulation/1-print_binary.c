#include "main.h"
#include <stdio.h>
/**
 * print_binary - prints binary rep of a number
 * @n: parameter to be used
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int ink;
	int mode;

	mode = sizeof(unsigned long int) * 8;
	ink = 1UL << (mode - 1);

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while ((n & ink) == 0)
	{
		ink = ink >> 1;
	}

	while (ink > 0)
	{
		if ((n & ink) != 0)
		{
			_putchar('1');
		}
		else
		{
			_putchar('0');
		}
		ink = ink >> 1;
	}
}
