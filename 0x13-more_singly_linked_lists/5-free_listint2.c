#include "lists.h"
#include <stdlib.h>
/**
 * free_listint2 - frees listint_t list
 * @head: beginning of the node
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *ink = *head;
	listint_t *next;
	
	if (head == NULL)
		return;
	while (ink != NULL)
	{
		next = ink->next;
		free(ink);
		ink = next;
	}
	*head = NULL;
}
