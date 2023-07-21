#include "lists.h"
/**
 * print_dlistint - prints all elements
 * @h: head of the list
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodecount = 0;
	const dlistint_t *curr = h;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
		nodecount++;
	}
	return (nodecount);
}
