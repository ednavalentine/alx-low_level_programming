#include "main.h"
#include <stdio.h>
/**
 * print_numbers - prints the numbers from 0-9 followed by a new line
 * Return: void
 */
void print_numbers(void)
{
	int c;

	for (c = 0; c <= 9; c++)
		putchar(c + '0');

	putchar('\n');
}
