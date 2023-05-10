#include "main.h"
/**
 * _strlen_recursion - Computes the length of a string recursively
 * @s: The string to compute the length of
 * Return: length of string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + _strlen_recursion(s + 1));
}
