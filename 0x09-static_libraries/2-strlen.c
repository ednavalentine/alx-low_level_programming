#include "main.h"
/**
 * _strlen -  returns the length of a string
 * @s: character to be used
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
