#include "main.h"
/**
 * _strncat - Concatenates 2 strings, using at most n bytes from src.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to use from src.
 * Return: A pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;
	int lib;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	for (lib = 0; lib < n && src[lib] != '\0'; lib++)
	{
		dest[dest_len + lib] = src[lib];
	}
	dest[dest_len + lib] = '\0';
	return (dest);
}
