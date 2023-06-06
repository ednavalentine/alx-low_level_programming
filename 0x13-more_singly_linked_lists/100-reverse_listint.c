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

	ink = NULL;
	while (*head != NULL)
	{
		mode = (*head)->next;
		(*head)->next = ink;
		ink = *head;
		*head = mode;
	}
	*head = ink;
	return (*head);
}
