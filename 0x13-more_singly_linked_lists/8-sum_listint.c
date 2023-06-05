#include "lists.h"
#include <stdlib.h>
/**
 * sum_listint - sum of data (n)
 * @head: beginning of node
 * Return: sum
 */
int sum_listint(listint_t *head)
{
	int ink = 0;

	while (head != NULL)
	{
		ink += head->n;
		head = head->next;
	}
	return (ink);
}
