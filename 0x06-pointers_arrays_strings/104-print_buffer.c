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
	int i = 0;
	int j = 0;

	while (i < size)
	{
		printf("%08x: ", i);
		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				printf("%02x%c", (unsigned char)b[i + j], j == 1 || j == 9 ? ' ' : 0);
			}
			else
			{
				printf("  ");
			}
		}
		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				printf("%c", isprint(b[i + j]) ? b[i + j] : '.');
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
		i += 10;
	}
	printf("\n");
}
