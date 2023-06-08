#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip
 * @n: unsigned long int to be used
 * @m: unsigned long int to be used
 * Return: flipped numbers
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int ink;
	unsigned int mode = 0;

	ink = n ^ m;
	while (ink != 0)
	{
		mode += ink & 1;
		ink >>= 1;
	}
	return (mode);
}
