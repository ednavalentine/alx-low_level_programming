#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_all - prints anything
 * @format: list of arguments passed to function
 * Return: anything
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0;
	int integer;
	char c;
	char *s;
	float f;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == 'c')
		{
			c = (char)va_arg(ap, int);
			printf("%c, ", c);
		}
		else if (format[i] == 'i')
		{
			integer = va_arg(ap, int);
			printf("%d, ", integer);
		}
		else if (format[i] == 'f')
		{
			f = (float)va_arg(ap, double);
			printf("%f, ", f);
		}
		else if (format[i] == 's')
		{
			s = va_arg(ap, char*);
			printf("%s, ", (s != NULL) ? s : "(nil)");
		}
		i++;
	}
	va_end(ap);
	printf("\n");
}
