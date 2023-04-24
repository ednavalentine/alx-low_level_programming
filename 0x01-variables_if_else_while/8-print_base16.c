#include <stdio.h>
/**
 * main - Entry point
 * Description: 'printing all number of base 16 in lowercase'
 * Return: Always 0 (Success)
 */
int main(void)
{
	int u;
	char t;

	for (u = 0; u < 10; u++)
	{
		putchar((u % 10) + '0');
	}
	for (t = 'a'; t < 'f'; t++)
	{
		putchar(t);
	}
	putchar('\n');
	return (0);
}
