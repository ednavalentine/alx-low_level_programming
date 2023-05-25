#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_all - prints anything
 * @format: list of arguments passed to function
 * Return: anything
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0;
	char *s;

	while (format == NULL)
	{
		printf("\n");
		return;
	}
	va_start(ap, format);
	while (format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf("%c", (char)va_arg(ap, int));
			break;
		case 'i':
			printf("%i", va_arg(ap, int));
			break;
		case 'f':
			printf("%f", (float)va_arg(ap, double));
			break;
		case 's':
			s = va_arg(ap, char*);
			if (s == NULL)
			{
				printf("(nil)");
				break;
			}
			printf("%s", s);
		}
		if (format[i + 1] != '\0' && (format[i] == 'c' || format[i] == 'i' ||
			format[i] == 'f' || format[i] == 's'))
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(ap);
}
