#include <stdio.h>

/**
  * main - Prints the sum of all multiples of 3 or 5 up to 1024
  * Return: Always 0 (Success)
  */
int main(void)
{
	int iz, zi = 0;

	while (iz < 1024)
	{
		if ((iz % 3 == 0) || (iz % 5 == 0))
		{
			zi += iz;
		}

		iz++;
	}

	printf("%d\n", zi);
	return (0);
}
