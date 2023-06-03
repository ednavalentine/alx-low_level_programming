#include "lists.h"
#include <stdio.h>
#include <stddef.h>
/**
 * print_list - prints a list
 * @h: constant list variable
 * Return: list
 */
size_t print_list(const list_t *h)
{
	const list_t *ink = h;
	size_t jum = 0;

	while (ink != NULL)
	{
		if (ink->str == NULL)
		{
			printf("[0] (nil)\n");
			jum++;
		}
		else
		{
			printf("[%lu] %s\n", jum++, ink->str);
		}
		ink = ink->next;
	}
	return (jum);
}
