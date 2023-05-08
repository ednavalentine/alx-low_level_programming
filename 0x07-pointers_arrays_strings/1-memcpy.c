#include "main.h"
/**
 * _memcpy - Copies memory area
 * @dest: Pointer to the destination memory area
 * @src: Pointer to the source memory area
 * @n: Number of bytes to be copied
 * Return: Pointer to the destination memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int pie;

	for (pie = 0; pie < n; pie++)
	{
		*(dest + pie) = *(src + pie);
	}
	return (dest);
}
