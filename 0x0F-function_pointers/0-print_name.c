#include "function_pointers.h"
#include <stddef.h>
/**
 * print_name - prints a name
 * @name: name to be printed
 * @f: pointer to char
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL)
		return;
	if (f == NULL)
		return;
	f(name);
}
