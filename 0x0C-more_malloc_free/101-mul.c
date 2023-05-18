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

	while (s[ink])
	{
		if (s[ink] < '0' || s[ink] > '9')
			return (0);
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
	int len1, len2, len, i, carry, digit1, digit2, *result, a = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !is_digit(s1) || !is_digit(s2))
		error();
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = s1[len1] - '0';
		carry = 0;
	for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
	{
		digit2 = s2[len2] - '0';
		carry += result[len1 + len2 + 1] + (digit1 * digit2);
		result[len1 + len2 + 1] = carry % 10;
		carry /= 10;
	}
	if (carry > 0)
		result[len1 + len2 + 1] += carry;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
