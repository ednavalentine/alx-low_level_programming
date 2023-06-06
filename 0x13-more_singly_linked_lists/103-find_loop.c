#include "lists.h"
#include <stdlib.h>
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: beginning of node
 * Return: address of the node where the loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tort = head;
	listint_t *hare = head;

	if (head == NULL || head->next == NULL)
	{
		return (NULL);
	}
	do {
		tort = tort->next;
		hare = hare->next->next;
		if (hare == NULL || hare->next == NULL)
		{
			return (NULL);
		}
	} while (tort != hare);
	tort = head;
	while (tort != hare)
	{
		tort = tort->next;
		hare = hare->next;
	}
	return (tort);
}
