#include "main.h"
/**
 * _strcat - Concatenates two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string.
 * Return: Pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int ij, ji;

	for (ij = 0; dest[ij] != '\0'; ij++)
		;
	for (ji = 0; src[ji] != '\0'; ji++)
	{
		dest[ij + ji] = src[ji];
	}
	dest[ij + ji] = '\0';
	return (dest);
}
