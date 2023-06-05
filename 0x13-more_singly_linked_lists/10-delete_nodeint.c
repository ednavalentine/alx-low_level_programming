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

	if (*head == NULL)
		return (-1);
	ink = *head;
	mode = NULL;
	if (index == 0)
	{
		*head = ink->next;
		free(ink);
		return (1);
	}
	while (ink != NULL)
	{
		if (jum == index)
		{
			mode->next = ink->next;
			free(ink);
			return (1);
		}
		mode = ink;
		ink = ink->next;
		jum++;
	}
	return (-1);
}
