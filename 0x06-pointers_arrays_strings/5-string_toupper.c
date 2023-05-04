#include "main.h"
/**
 * string_toupper - Changes all lowercase letters of a string to uppercase.
 * @s: The string to modify
 * Return: The modified string
 */
char *string_toupper(char *s)
{
	int it;

	for (it = 0; s[it] != '\0'; it++)
	{
		if (s[it] >= 'a' && s[it] <= 'z')
		{
			s[it] -= 32;
		}
	}
	return (s);
}
