#include "main.h"
#include <stddef.h>
/**
 * _strstr - Locates a substring in a string
 * @haystack: Pointer to the string to be searched
 * @needle: Pointer to the substring to be located
 * Return: Pointer to the beginning of the substring,or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *hay = haystack;
		char *nee = needle;

		while (*hay == *nee && *nee != '\0')
		{
			hay++;
			nee++;
		}
		if (*nee == '\0')
		{
			return (haystack);
		}
		haystack++;
	}
	return (NULL);
}
