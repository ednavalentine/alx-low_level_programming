#include <stddef.h>
#include "function_pointers.h"
/**
 * array_iterator - executes function given as parameter on element of array
 * @array: parameter to be used
 * @size: size of array
 * @action: pointer to function
 * Return: array
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t ink;

	if (array == NULL)
		return;
	if (size == 0)
		return;
	if (action == NULL)
		return;
	for (ink = 0; ink < size; ink++)
	{
		action(array[ink]);
	}
}
