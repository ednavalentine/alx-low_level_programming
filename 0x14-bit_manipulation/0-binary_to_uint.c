#include "main.h"
#include <stddef.h>
/**
 * binary_to_uint - converts binary to unsigned int
 * @b: pointer to string
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int ink;
	unsigned int mode = 0;
	char cat;

	if (b == NULL)
		return (0);
	for (ink = 0; b[ink] != '\0'; ink++)
	{
		cat = b[ink];
		if (cat == '0' || cat == '1')
		{
			mode = (mode << 1) + (cat - '0');
		}
		else
		{
			return (0);
		}
	}
	return (mode);
}
