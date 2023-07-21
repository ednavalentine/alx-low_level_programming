#include "lists.h"
/**
 * get_dnodeint_at_index - gets nth node of a dlistint_t linked list
 * @head: pointer to the list
 * @index: index of the node, starting from 0
 * Return: nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *curr = head;
	unsigned int inkcount = 0;

	while (curr != NULL && inkcount < index)
	{
		curr = curr->next;
		inkcount++;
	}
	if (curr == NULL || inkcount < index)
	{
		return (NULL);
	}
	return (curr);
}
