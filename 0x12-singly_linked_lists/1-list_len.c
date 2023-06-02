#include "lists.h"
#include <stddef.h>
/**
 * list_len - returns no of elements in a linked list_t
 * @h: pointer to array
 * Return: no of elements
 */
size_t list_len(const list_t *h)
{
	size_t jum = 0;

	while (h != NULL)
	{
		jum++;
		h = h->next;
	}
	return (jum);
}
