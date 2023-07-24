#include "main.h"
/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to search
 * @accept: The string containing the characters to match
 * Return: The number of bytes in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int lent = 0;
	char *pie;

	for (; *s; s++, lent++)
	{
		for (pie = accept; *pie; pie++)
		{
			if (*s == *pie)
			break;
		}
		if (*pie == '\0')
			return (lent);
	}
	return (lent);
}
