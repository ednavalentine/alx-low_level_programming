#include <stdio.h>
/**
 * main - Entry point
 * Description: 'printing all number of base 16 in lowercase'
 * Return: Always 0 (Success)
 */
int main(void)
{
	int u;

	for (u = 0; u < 16; u++)
	{
		if (u < 10)
		{
			putchar('0' + u);
		}
		else
		{
			putchar(87 + u);
		}
	}
	putchar('\n');
	return (0);
}
