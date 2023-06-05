#include "lists.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/**
 * print_listint - print elements in a listint
 * @h: parameter to be used
 * Return: the elements
 */
size_t print_listint(const listint_t *h)
{
	size_t ink = 0;

	while (h != NULL)
	{
		if (h->n != 0)
		{
			printf("%d\n", h->n);
		}
		else
		{
			printf ("0\n");
		}
		ink++;
		h = h->next;
	}
	return (ink);
}
