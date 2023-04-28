#include <stdio.h>
/**
 * main - find and prints the largest prime factor of  612852475143
 * Return: Always 0
 */
int main(void)
{
	long int n = 612852475143;
	int largest_prime_factor = 2;

	while (n > largest_prime_factor)
	{
		if (n % largest_prime_factor == 0)
		{
			n = n / largest_prime_factor;
		}
		else
		{
			largest_prime_factor++;
		}
	}
	printf("%d\n", largest_prime_factor);
	return (0);
}
