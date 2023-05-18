#include "main.h"
#include <string.h>
#include <stdlib.h>
/**
 * _realloc -  reallocates a memory block using malloc and free
 * @ptr: parameter to be used
 * @old_size: parameter to be used
 * @new_size: parameter to be used
 * Return: void
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int ink;
	unsigned char *p1;
	unsigned char *p2;
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		exit(1);
	p1 = (unsigned char *)ptr;
	p2 = (unsigned char *)new_ptr;
	for (ink = 0; ink < old_size && ink < new_size; ink++)
		p2[ink] = p1[ink];
	free(ptr);
	return (new_ptr);
}
