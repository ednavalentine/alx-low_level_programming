#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_all - prints anything
 * @const format: list of arguments passed to function
 * Return: anything
 */
void print_all(const char * const format, ...)
{
	va_list ap;
