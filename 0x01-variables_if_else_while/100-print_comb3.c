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
	for (z1 = z2 + 1; z2 < 10; z2++)
	{
		putchar((z1 % 10) + '0');
		putchar((z2 % 10) + '0');

		if (z1 == 8 && z2 == 9)
			continue;
		putchar(',');
		putchar(' ');
	}
	}
	putchar('\n');
	return (0);
}
