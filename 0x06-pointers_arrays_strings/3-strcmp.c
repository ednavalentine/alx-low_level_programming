#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: 0 equal - s1 less s2 + si greater s2
 */
int _strcmp(char *s1, char *s2)
{
	int in = 0;

	while (s1[in] != '\0' && s2[in] != '\0' && s1[in] == s2[in])
		in++;
	return (s1[in] - s2[in]);
}
