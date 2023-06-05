#include "lists.h"
#include <stdlib.h>
/**
 * insert_nodeint_at_index - inserts new node
 * @head: beginning of node
 * @idx: index of list
 * @n: int to be used
 * Return: node at new position
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *mode;
	listint_t *ink;
	unsigned int jum = 0;

	mode = malloc(sizeof(listint_t));
	if (mode == NULL)
		return (NULL);
	mode->n = n;
	if (idx == 0)
	{
		mode->next = *head;
		*head = mode;
		return (mode);
	}
	ink  = *head;
	while (ink != NULL && jum < idx - 1)
	{
		ink = ink->next;
		jum++;
	}
	if (ink == NULL)
		return (NULL);
	mode->next = ink->next;
	ink->next = mode;
	return (mode);
}
