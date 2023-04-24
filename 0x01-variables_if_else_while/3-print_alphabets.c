#include <stdio.h>
/**
 * main - Entry point
 * Description: 'generating lowercase and then uppercase alphabets'
 * Return: Always 0 (Success)
 */
int main(void)
{
	int k;

	for (k = 97; k <= 122; k++)
	{
		putchar(k);
	}
	for (k = 65; k <= 90; k++)
	{
		putchar(k);
	}
	putchar('\n');
	return (0);
}
