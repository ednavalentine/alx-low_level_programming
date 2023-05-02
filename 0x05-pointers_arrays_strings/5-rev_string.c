#include "main.h"
/**
 * rev_string - reverses a string
 * @s: parameter to be used
 * Return: reverse string
 */
void rev_string(char *s)
{
	char rev = s[0];
	int road = 0;
	int fence;

	while (s[road] != '\0')
		road++;
	for (fence = 0; fence < road; fence++)
	{
		road--;
		rev = s[fence];
		s[fence] = s[road];
		s[road] = rev;
	}
}
