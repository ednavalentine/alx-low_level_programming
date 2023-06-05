#include "lists.h"
#include <stddef.h>
/**
 * listint_len - returns no of elements in a linked list
 * @h: parameter to be used
 * Return: elements
 */
size_t listint_len(const listint_t *h)
{
	size_t ink = 0;

	while (h != NULL)
	{
		ink++;
		h = h->next;
	}
	return (ink);
}
