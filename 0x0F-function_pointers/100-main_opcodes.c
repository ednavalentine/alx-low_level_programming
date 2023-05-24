#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int ink, num_bytes;
	unsigned char *opcode_ptr;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	num_bytes = atoi(argv[1]);
	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}
	opcode_ptr = (unsigned char *)main;
	for (ink = 0; ink < num_bytes; ink++)
	{
		printf("%02x ", opcode_ptr[ink]);
	}
	printf("\n");
	return (0);
}
