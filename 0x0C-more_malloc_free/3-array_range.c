#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of integers
 * @min: lowest array
 * @max: highest array
 * Return: void
 */
int *array_range(int min, int max)
{
	int *array;
	int sizes, ink;

	if (min > max)
		return (NULL);
	sizes = max - min + 1;
	array = malloc(sizes * sizeof(int));
	if (array == NULL)
		return (NULL);
	for (ink = 0; ink < sizes; ink++)
		array[ink] = min++;
	return (array);
}
