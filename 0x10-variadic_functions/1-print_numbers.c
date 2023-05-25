#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
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
	for (ink = 0; ink < n; ink++)
	{
		num = va_arg(ap, int);
		printf("%d ", num);
		if (ink < n - 1 && separator != NULL && n > 1)
		{
			printf("%s", separator);
		}
	}
	va_end(ap);
	printf("\n");
}
