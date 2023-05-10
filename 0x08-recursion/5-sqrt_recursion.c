#include "main.h"
/**
 * _sqrt_recursion - Calculates the natural square root of a number
 * @n: The number to compute the square root of
 * Return: The natural square root of n, or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_helper(n, 1));
}

/**
 * _sqrt_helper - Recursive helper function for calculating square root
 * @n: The number to compute the square root of
 * @ink: The current integer to check
 * Return: The natural square root of n, or -1
 */
int _sqrt_helper(int n, int ink)
{
	if (ink * ink == n)
		return (ink);
	if (ink * ink > n)
		return (-1);
	return (_sqrt_helper(n, ink + 1));
}
