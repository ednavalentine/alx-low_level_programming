#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_strings - prints strings
 * @separator: string to print btw strings
 * @n: number of strings passed to function
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int ink;
	const char *str;

	va_start(ap, n);
	if (separator == NULL)
		return;
	for (ink = 0; ink < n; ink++)
	{
		str = va_arg(ap, const char *);
		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);
		if (ink < n - 1 && separator != NULL)
		{
			printf("%s", separator);
		}
	}
	va_end(ap);
	printf("\n");
}
