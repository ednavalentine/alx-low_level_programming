#include "main.h"
#include <stdio.h>
#include <ctype.h>
/**
 * print_buffer - prints a buffer
 * @b: parmeter to be used
 * @size: parameter to be used
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int i, j;

	for (int i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);
		for (int j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				printf("%02x", (unsigned char)b[i + j]);
				if (j == 1 || j == 9)
				{
					printf(" ");
				}
			}
			else
			{
				printf("   ");
			}
		}
		for (int j = 0; j < 10; j++)
		{
			printf(i + j < size ? "%c" : " ", isprint(b[i + j]) ? b[i + j] : '.');
		}
		printf("\n");
	}
	printf("\n");
}
