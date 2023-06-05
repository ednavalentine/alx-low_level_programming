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
		printf("%d\n", h->n);
		h = h->next;
		ink++;
	}
	return (ink);
}
