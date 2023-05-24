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
	int num_bytes = 0;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	if (atoi(argv[1]) < 0)
	{
		printf("Error\n");
		exit(2);
	}
	while (num_bytes < atoi(argv[1]))
	{
		printf("%02x", *((unsigned char *)main + num_bytes));
		num_bytes++;
		if (atoi(argv[1]) > num_bytes)
		{
			printf(" ");
		}
	}
	printf("\n");
	return (0);
}
