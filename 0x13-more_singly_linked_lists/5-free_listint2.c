#include "lists.h"
#include <stdlib.h>
/**
 * free_listint2 - frees listint_t list
 * @head: beginning of the node
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *jum;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		jum = *head;
		*head = (*head)->next;
		free(jum);
	}
}
