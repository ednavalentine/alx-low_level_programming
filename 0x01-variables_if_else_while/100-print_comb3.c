#include <stdio.h>
/**
 * main - Entry point
 * Description: 'outputs all possible different combinations of two digits'
 * Return: Always 0 (Success)
 */
int main(void)
{
	int z1, z2;

	for (z1 = 0; z1 < 9; z1++)
	{
		z2 = z1 + 1;
		do {
		putchar(z1 + '0');
		putchar(z2 + '0');
		if (z1 < 8)
		{
		putchar(',');
		putchar(32);
		}
		z2++;
		} while (z2 < 10);
	}
	putchar('\n');
	return (0);
}
