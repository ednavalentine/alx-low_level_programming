#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * main - adds positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: void
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int ink, jum;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
}

	for (ink = 1; ink < argc; ink++)
	{
		for (jum = 0; argv[ink][jum] != '\0'; jum++)
		{
			if (!isdigit(argv[ink][jum]))
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[ink]);
	}
	printf("%d\n", sum);
	return (0);
}
