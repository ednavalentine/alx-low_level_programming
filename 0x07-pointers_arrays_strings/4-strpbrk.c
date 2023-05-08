#include "main.h"
#include <stddef.h>
/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: Pointer to the string to be searched
 * @accept: Pointer to the set of bytes to search for
 * Return: Pointer to the byte in s or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	char *pie_accept;

	while (*s != '\0')
	{
		pie_accept = accept;
		while (*pie_accept != '\0')
		{
			if (*s == *pie_accept)
			{
				return (s);
			}
			pie_accept++;
		}
		s++;
	}
	return (NULL);
}
