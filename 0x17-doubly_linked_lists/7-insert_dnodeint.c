#include "lists.h"
/**
 * insert_dnodeint_at_index - adds a new node at a given position
 * @h: pointer to both the start and end of the list
 * @idx: index of the list where the new node should be added
 * @n: integer to be used
 * Return: new node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *newmode;
	dlistint_t *curr;
	unsigned int inkcount;

	if (h == NULL)
		return (NULL);
	newmode = (dlistint_t *)malloc(sizeof(dlistint_t));
	if (newmode == NULL)
		return (NULL);
	newmode->n = n;
	if (idx == 0)
	{
		newmode->next = *h;
		newmode->prev = NULL;
		if (*h != NULL)
		{
			(*h)->prev = newmode;
		}
		*h = newmode;
		return (newmode);
	}
	curr = *h;
	inkcount = 0;
	while (curr != NULL && inkcount < idx)
	{
		curr = curr->next;
		inkcount++;
	}
	if (curr == NULL && inkcount < idx)
	{
		free(newmode);
		return (NULL);
	}
	newmode->next = curr;
	newmode->prev = curr->prev;
	if (curr->prev != NULL)
		curr->prev->next = newmode;
	curr->prev = newmode;
	return (newmode);
}
