#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates an array of chars initializes it with a specific char
 * @size: int to be used
 * @c: char to be used
 * Return: void
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int ink;

	if (size == 0)
	{
		return (NULL);
	}
	array = (char *) malloc(size * sizeof(char));
	if (array == NULL)
	{
		return (NULL);
	}
	for (ink = 0; ink < size; ink++)
	{
		array[ink] = c;
	}
	return (array);
}
