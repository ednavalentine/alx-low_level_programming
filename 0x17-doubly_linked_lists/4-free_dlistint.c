#include "lists.h"
/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the list
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *curr = head;
	dlistint_t *nextnode;

	while (curr != NULL)
	{
		nextnode = curr->next;
		free(curr);
		curr = nextnode;
	}
}
