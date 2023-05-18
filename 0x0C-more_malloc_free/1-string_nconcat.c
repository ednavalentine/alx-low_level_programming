#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - concatenates two strings
 * @s1: The first string
 * @s2: The second string
 * @n: The number of bytes from s2 to concatenate
 * Return: void
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *cat;
	unsigned int leng1 = 0, leng2 = 0, ink, jum;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[leng1] != '\0')
		leng1++;
	while (s2[leng2] != '\0')
		leng2++;
	if (n >= leng2)
		n = leng2;
	cat = malloc(sizeof(char) * (leng1 + n + 1));
	if (cat == NULL)
		return (NULL);
	for (ink = 0; ink < leng1; ink++)
		cat[ink] = s1[ink];
	for (jum = 0; jum < n; jum++)
		cat[ink] = s2[jum];
	cat[ink] = '\0';
	return (cat);
}
