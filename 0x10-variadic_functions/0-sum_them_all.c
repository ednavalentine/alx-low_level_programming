#include <stdarg.h>
#include "variadic_functions.h"
/**
 * sum_them_all - finds sum of all parameters
 * @n: unsigned int
 * @...: arguments to be made
 * Return: sum
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int ink = 0, sum = 0;

	va_start(ap, n);
	if (n == 0)
		return (0);
	for (ink = 0; ink < n; ink++)
	{
		sum += va_arg(ap, int);
	}
	va_end(ap);
	return (sum);
}
