#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the minimum number of coins to make change
 * @argc: argument count
 * @argv: argument vector
 * Return: void
 */
int main(int argc, char *argv[])
{
	int cent, numb_coins = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cent = atoi(argv[1]);
	if (cent < 0)
	{
		printf("0\n");
		return (0);
	}
	while (cent >= 25)
	{
		cent -= 25;
		numb_coins++;
	}
	while (cent >= 10)
	{
		cent -= 10;
		numb_coins++;
	}
	while (cent >= 5)
	{
		cent -= 5;
		numb_coins++;
	}
	while (cent >= 2)
	{
		cent -= 2;
		numb_coins++;
	}
	while (cent >= 1)
	{
		cent -= 1;
		numb_coins++;
	}
	printf("%d\n", numb_coins);
	return (0);
}
