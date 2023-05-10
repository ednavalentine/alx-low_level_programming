#include "main.h"
/**
 * is_prime_number - Checks if a number is a prime number
 * @n: The number to be checked
 * Return: 1 if n is a prime number, otherwise return 0
 */
int is_prime_number(int n)
{
	if (n < 2)
	{
		return (0);
	}
	return (is_prime_helper(n, 2));
}

/**
 * is_prime_helper - Helper function to check if a number is prime or not
 * @n: The number to be checked
 * @i: The divisor to check n against
 * Return: 1 if n is a prime number, otherwise return 0
 */
int is_prime_helper(int n, int i)
{
	if (i > n / 2)
	{
		return (1);
	}
	if (n % i == 0)
	{
		return (0);
	}
	return (is_prime_helper(n, i + 1));
}
