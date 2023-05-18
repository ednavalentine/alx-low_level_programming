#include "main.h"
#include <stdlib.h>
/**
 * _calloc -  allocates memory for an array, using malloc
 * @nmemb: paramete to be used
 * @size: parameter to be used
 * Return: void
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *cat = NULL;
	unsigned int total = nmemb * size;
	unsigned char *byte_cat;
	unsigned int ink;

	if (nmemb == 0 || size == 0)
		return (NULL);
	cat = malloc(total);
	if (cat == NULL)
		return (NULL);
	byte_cat = (unsigned char *)cat;
	for (ink = 0; ink < total; ink++)
		byte_cat[ink] = 0;
	return (cat);
}
