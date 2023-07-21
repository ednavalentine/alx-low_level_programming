#include "lists.h"
/**
 * sum_dlistint - sum of all the data (n) of a dlistint_t linked list
 * @head: pointer to the list
 * Return: sum of the data
 */
int sum_dlistint(dlistint_t *head)
{
	int sumnode = 0;
	dlistint_t *curr = head;

	while (curr != NULL)
	{
		sumnode += curr->n;
		curr = curr->next;
	}
	return (sumnode);
}
