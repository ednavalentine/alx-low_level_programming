#include <stdio.h>
#include <stdlib.h>

void print_opcodes(int num_bytes);
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int i, num_bytes;
	void *main_addr;
	unsigned char *opcodes;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	num_bytes = atoi(argv[1]);
	if (num_bytes <= 0)
	{
		printf("Error\n");
		exit(2);
	}
	main_addr = (void *)main;
	opcodes = (unsigned char *)main_addr;
	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x ", opcodes[i]);
	}
	printf("\n");
}
