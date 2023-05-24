#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints opcodes
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int num_bytes, i;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	num_bytes = atoi(argv[1]);
	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}
	for (i = 0; i < num_bytes; i++)
	{
		printf("%02hhx", *((char *)main + 1));
		if (i < num_bytes - 1)
			printf(" ");
		else
			printf("\n");
	}
	return (0);
}
