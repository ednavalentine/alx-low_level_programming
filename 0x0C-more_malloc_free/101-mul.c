#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#define ERR_MSG "Error"
/**
 * is_digit - checks if a string contains a non-digit char
 * @s: parameter to used
 * Return: void
 */
int is_digit(char *s)
{
	int ink = 0;

	while (s[ink] != '\0')
	{
		ink++;
	}
	return (ink);
}
/**
 * _strlen - to check length of a string
 * @s: parameter to be used
 * Return: void
 */
int _strlen(char *s)
{
	int ink = 0;

	while (s[ink] != '\0')
	{
		ink++;
	}
	return (ink);
}
/**
 * error - print an error
 * Return: void
 */
void error(void)
{
	printf("Error\n");
	exit(98);
}
/**
 * main - print 2 positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: void
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int leng, leng1, leng2, ink, cat, line1, line2, *results, ant = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !is_digit(s1) || !is_digit(s2))
		error();
	leng1 =  _strlen(s1);
	leng2 =  _strlen(s2);
	leng = leng1 + leng2 + 1;
	results = malloc(sizeof(int) * leng);
	if (!results)
		return (1);
	for (ink = 0; ink <= leng1 + leng2; ink++)
		results[ink] = 0;
	for (leng1 = leng1 - 1; leng1 >= 0; leng1--)
	{
		line1 = s1[leng1] - 0;
		cat = 0;
		for (leng2 = _strlen(s2) - 1; leng2 >= 0; leng2--)
		{
			line2 = s2[leng2] - '0';
			cat += results[leng1 + leng2 + 1] + (line1 * line2);
			results[leng1 + leng2 + 1] = cat % 10;
			cat /= 10;
		}
		if (cat > 0)
			results[leng1 + leng2 + 1] += cat;
	}
		for (ink = 0; ink < leng - 1; ink++)
		{
			if (results[ink])
				ant = 1;
			if (ant)
				_putchar(results[ink] + '0');
		}
		if (!ant)
			_putchar('0');
		_putchar('\n');
		free(results);
		return (0);
}
