#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix
 * @size: size of the matrix
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int ink, ink1 = 0, ink2 = 0;

	for (ink = 0; ink < size; ink++)
	{
		ink1 += a[ink * size + ink];
		ink2 += a[ink * size + (size - ink - 1)];
	}
	printf("%d, %d\n", ink1, ink2);
}
