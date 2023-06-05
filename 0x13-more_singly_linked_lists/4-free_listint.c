#include "lists.h"
#include <stdlib.h>
/**
 * free_listint - frees a linked list
 * @head: beginning of the node
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *ink;

	while (head != NULL)
	{
		ink = head;
		head = head->next;
		free(ink);
	}
}
