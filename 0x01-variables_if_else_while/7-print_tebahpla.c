#include <stdio.h>
/**
 * main - Entry pont
 * Description: 'extracting lowercase in reverse'
 * Return: Always 0 (Success)
 */
int main(void)
{
	int p;

	for (p = 'z'; p >= 'a'; p--)
	{
		putchar(p);
	}
	putchar('\n');
	return (0);
}
