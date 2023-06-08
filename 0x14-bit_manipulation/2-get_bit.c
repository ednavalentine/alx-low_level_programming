#include "main.h"
/**
 * get_bit - returns value of a bit
 * @n: unsigned long int
 * @index: starting index from 0
 * Return: value of the bit at index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int mode;
	unsigned long int ink;
	unsigned long int cat;

	mode = sizeof(unsigned long int) * 8;

	if (index >= mode)
	{
		return (-1);
	}
	ink = 1UL << index;
	cat = n & ink;
	return ((cat != 0) ? 1 : 0);
}
