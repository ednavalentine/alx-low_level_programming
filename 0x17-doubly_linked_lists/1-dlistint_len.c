#include "lists.h"
/**
 * dlistint_len - returns number of elements
 * @h: header of the list
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t nodecount = 0;
	const dlistint_t *curr = h;

	while (curr != NULL)
	{
		curr = curr->next;
		nodecount++;
	}
	return (nodecount);
}
