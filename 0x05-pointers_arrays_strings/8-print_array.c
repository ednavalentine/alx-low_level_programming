#include "main.h"
#include <stdio.h>
/**
 * print_array - prints n elements of an array of integers
 * @a: variable to be used
 * @n: number of elements of the array to be printed
 * Return: a and n
 */
void print_array(int *a, int n)
{
	int it;

	for (it = 0; it < (n - 1); it++)
	{
		printf("%d, ", a[it]);
	}
	if (it == (n - 1))
	{
		printf("%d", a[n - 1]);
	}
	printf("\n");
}
