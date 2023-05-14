#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - multiplies two numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: void
 */
int main(int argc, char *argv[])
{
	int numb1, numb2, results;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	numb1 = atoi(argv[1]);
	numb2 = atoi(argv[2]);
	results = numb1 * numb2;

	printf("%d\n", results);
	return (0);
}
