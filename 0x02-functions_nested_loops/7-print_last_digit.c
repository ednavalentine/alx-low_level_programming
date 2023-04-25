#include "main.h"
/**
 * print_last_digit - prints the last digit of a number
 * @l: the number to be checked
 * Return: the value of the last digit
 */
int print_last_digit(int l)
{
	int last_digit;

	if (l < 0)
		l = -l;
	last_digit = l % 10;
	_putchar(last_digit + '0');
	return (last_digit);
}
