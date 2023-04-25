#include <stdio.h>

/**
  * main - Prints the sum of Even Fibonacci numbers
  * do not exceed 4000000.
  * Return: Always 0 (Success)
  */
int main(void)
{
	int cat = 0;
	long mouse = 1, k = 2, sum = k;

	while (k + mouse < 4000000)
	{
		k += mouse;

		if (k % 2 == 0)
			sum += k;

		mouse = k - mouse;

		++cat;
	}

	printf("%ld\n", sum);
	return (0);
