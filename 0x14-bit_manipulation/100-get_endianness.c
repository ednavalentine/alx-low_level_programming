#include "main.h"
/**
 * get_endianness - checks endianess
 * @void: returns void
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int ink = 1;
	char *mode;

	mode = (char*) &ink;
	if (*mode)
		return (1);
	else
		return (0);
}
