#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_numbers - prints numbers
 * @separator: string to print btw numbers
 * @n: number of ints passed to function
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int ink;
	int num;

	va_start(ap, n);
	ink = 0;
	while (ink < n)
	{
		num = va_arg(ap, int);
		printf("%d", num);
		if (ink < n - 1 && separator != NULL)
			printf("%s", separator);
		ink++;
	}
	va_end(ap);
	printf("\n");
}
