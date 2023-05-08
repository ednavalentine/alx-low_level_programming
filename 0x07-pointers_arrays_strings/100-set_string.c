#include "main.h"
/**
 * set_string - Sets the value of a pointer to a char
 * @s: A pointer to the pointer to the char to be set
 * @to: A pointer to the char to set the pointer to
 * Return: void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
