#include "lists.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

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
		if (ink->str != NULL)
		{
			printf("[%lu] %s\n", strlen(ink->str), ink->str);
		}
		else
		{
			printf("[0] (nil)\n");
		}
		jum++;
		ink = ink->next;
	}
	return (jum);
}
