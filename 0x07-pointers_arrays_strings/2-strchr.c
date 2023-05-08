#include "main.h"
#include <stddef.h>
/**
 * _strchr - Locates a character in a string
 * @s: Pointer to the string to be searched
 * @c: Character to be located
 * Return: pointer if found or null if not found
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	return (NULL);
}
