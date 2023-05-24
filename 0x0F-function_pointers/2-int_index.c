#include "function_pointers.h"
#include <stddef.h>
/**
 * int_index - searches for int in an array
 * @array: parameter to be searched
 * @size: number of elements
 * @cmp: pointer to function
 * Return: index of matching element or -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int ink;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);
	for (ink = 0; ink < size; ink++)
	{
		if (cmp(array[ink]))
			return (ink);
	}
	return (-1);
}
