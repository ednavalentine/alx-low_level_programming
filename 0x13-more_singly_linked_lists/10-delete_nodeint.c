#include "lists.h"
#include <stdlib.h>
/**
 * delete_nodeint_at_index - deletes a node at index
 * @head: beginning of node
 * @index: index of node
 * Return: nothing
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *ink;
	listint_t *mode;
	unsigned int jum = 0;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		ink = *head;
		free(ink);
		return (1);
	}
	mode = NULL;
	while (ink != NULL && jum < index)
	{
		mode = ink;
		ink = ink->next;
		jum++;
	}
	if (ink == NULL)
		return (-1);
	mode->next = ink->next;
	free(ink);
	return (-1);
}
