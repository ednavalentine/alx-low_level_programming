#include "main.h"
/**
 * *_strcpy - copies the string pointed to by src
 * @dest: parameter to be used
 * @src: parameter to be used
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest_start);
}
