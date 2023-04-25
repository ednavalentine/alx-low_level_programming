#include "main.h"
#include <unistd.h>
/**
 * print_alphabet - Entry point
 * function that prints the alphabet, in lowercase
 * Return: Always 0 (Success)
 */
void print_alphabet(void)
{
	char t;

	for (t = 'a'; t <= 'z'; t++)
	{
		_putchar(t);
	}
	_putchar('\n');
}
