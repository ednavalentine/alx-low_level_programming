#include "main.h"
/**
 * _memset - fills memory with a constant byte
 * @s: parameter to be used
 * @b: parameter to be used
 * @n: unsigned int
 * Return: Pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int ink;

	for (ink = 0; ink < n; ink++)
	{
		*(s + ink) = b;
	}
	return (s);
}
