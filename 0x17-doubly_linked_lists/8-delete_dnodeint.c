#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes the node at index index of a
 * dlistint_t linked list
 * @head: start and end of the list
 * @index: index of the node that should be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curr;
	unsigned int inkcount;

	if (head == NULL || *head == NULL)
		return (-1);
	curr = *head;
	inkcount = 0;
	if (index == 0)
	{
		*head = curr->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(curr);
		return (1);
	}
	while (curr != NULL && inkcount < index)
	{
		curr = curr->next;
		inkcount++;
	}
	if (curr == NULL)
		return (-1);
	if (curr->prev != NULL)
		curr->prev->next = curr->next;
	if (curr->next != NULL)
		curr->next->prev = curr->prev;
	free(curr);
	return (1);
}
