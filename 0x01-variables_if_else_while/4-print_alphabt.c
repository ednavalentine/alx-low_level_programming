#include <stdio.h>
/**
 * main - entry point
 * Description: 'Printing out letter in lowercase except e and q'
 * Return: Always 0 (Success)
 */
int main(void)
{
	int y;

	for (y = 97; y <= 122; y++)
	{
	if (y != 101 && y != 113)
	{
		putchar(y);
	}
	}
	putchar('\n');
	return (0);
}
