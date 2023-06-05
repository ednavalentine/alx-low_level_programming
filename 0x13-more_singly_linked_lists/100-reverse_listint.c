#include "lists.h"
#include <stdlib.h>
/**
 * reverse_listint - reverses a linked list
 * @head: beginning of node
 * Return: reverse
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *ink;
	listint_t *mode;
	listint_t *jum;

	ink = NULL;
	mode = *head;
	jum = NULL;
	while (mode != NULL)
	{
		jum = mode->next;
		mode->next = ink;
		ink = mode;
		mode = jum;
	}
	*head = jum;
	return (*head);
}
