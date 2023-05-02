#include "main.h"
/**
 * print_rev - function that prints a string, in reverse
 * @s: parameter to be used
 * Return: 0
 */
void print_rev(char *s)
{
	int pt = 0;
	int qp;

	while (*s != '\0')
	{
		pt++;
		s++;
	}
	s--;
	for (qp = pt; qp > 0; qp--)
	{
		_putchar(*s);
		s--;
	}
	_putchar('\n');
}
