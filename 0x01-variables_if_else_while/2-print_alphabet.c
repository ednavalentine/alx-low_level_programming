#include  <stdio.h>
/**
 * main - Entry point
 * Description: 'Creating a program that changes alphabets into lowercase'
 * Return: Always 0 (Success)
 */
int main(void)
{
	char v;

	for (v = 'a'; v <= 'z'; v++)
	{
		putchar(v);
	}
	putchar('\n');
	return (0);
}
