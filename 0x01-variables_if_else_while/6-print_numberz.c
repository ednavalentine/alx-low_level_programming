#include <stdio.h>
/**
 * main - Entry point
 * Description: 'Prints all single digits without using char'
 * Return: Always 0 (Success)
 */
int main(void)
{
	int g;

	for (g = 0; g < 0; g++)
	{
		putchar((g % 10) + '0');
	}
	putchar('\n');
	return (0);
}
