#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: parameter to be used
 * Return: void
 */
char *_strdup(char *str)
{
	char *copy;

	if (str == NULL)
	{
		return (NULL);
	}
	copy = (char *) malloc(strlen(str) + 1);
	if (copy == NULL)
	{
		return (NULL);
	}
	strcpy(copy, str);
	return (copy);
}
