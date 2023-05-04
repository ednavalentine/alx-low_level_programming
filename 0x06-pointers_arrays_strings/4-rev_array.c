#include "main.h"
/**
 * reverse_array - Reverses the content of an array of integers
 * @a: Pointer to the array of integers
 * @n: Number of elements of the array
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int in, temp;

	for (in = 0; in < n / 2; in++)
	{
		temp = a[in];
		a[in] = a[n - in - 1];
		a[n - in - 1] = temp;
	}
}
