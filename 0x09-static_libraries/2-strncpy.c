#include "main.h"
/**
 * _strncpy - copy a string
 * @dest: the destination string
 * @src: the source string
 * @n: the maximum number of bytes to copy
 * Return: a pointer to the destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int in;

	for (in = 0; in < n && src[in] != '\0'; in++)
	{
		dest[in] = src[in];
	}
	for ( ; in < n; in++)
	{
		dest[in] = '\0';
	}
	return (dest);
}
