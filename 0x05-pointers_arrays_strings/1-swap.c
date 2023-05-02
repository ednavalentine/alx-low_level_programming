#include "main.h"
/**
 * swap_int - function that swaps the values of two integers
 * @a: first parameter to be used
 * @b: second parameter to be used
 * Return: always 0
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
