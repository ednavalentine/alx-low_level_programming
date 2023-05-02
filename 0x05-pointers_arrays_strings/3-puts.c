#include "main.h"
/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: parameter to be used
 * Return: returns str
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}
