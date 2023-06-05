#include "lists.h"
#include <stdlib.h>
/**
 * pop_listint - deletes head node
 * @head: beginning of node
 * Return: nothing
 */
int pop_listint(listint_t **head)
{
	int ink;
	listint_t *jum;

	if (*head == NULL)
		return (0);
	ink = (*head)->n;
	jum = *head;
	*head = (*head)->next;
	free(jum);
	return (ink);
}
