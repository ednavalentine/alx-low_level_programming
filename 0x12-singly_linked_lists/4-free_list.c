#include "lists.h"
#include <stdlib.h>
/**
 * free_list - frees a node
 * @head: parameter to be used
 * Return: nothing
 */
void free_list(list_t *head)
{
	list_t *ink;

	while (head != NULL)
	{
		ink = head->next;
		free(head);
		head = ink;
	}
}
