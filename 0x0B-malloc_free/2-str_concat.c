#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: char to be used
 * @s2: char to be used
 * Return: void
 */
char *str_concat(char *s1, char *s2)
{
	int ink;
	int jum;
	int leng1 = 0;
	int leng2 = 0;
	char *result;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[leng1])
		leng1++;
	while (s2[leng2])
		leng2++;
	result = (char *) malloc(leng1 + leng2 + 1);
	if (result == NULL)
		return (NULL);
	for (ink = 0; ink < leng1; ink++)
	{
		result[ink] = s1[ink];
	}
	for (jum = 0; jum < leng2; jum++)
	{
		result[ink + jum] = s2[jum];
	}
	result[leng1 + leng2] = '\0';
	return (result);
}
