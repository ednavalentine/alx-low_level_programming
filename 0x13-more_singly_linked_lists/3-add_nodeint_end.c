#include "lists.h"
#include <stdlib.h>
/**
 * add_nodeint_end - add node at the end
 * @head: beginning of the node
 * @n: int
 * Return: end node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *mode1;
	listint_t *cur;

	mode1 = malloc(sizeof(listint_t));
	if (mode1 == NULL)
		return (NULL);
	mode1->n = n;
	mode1->next = NULL;
	if (*head == NULL)
	{
		*head = mode1;
	}
	else
	{
		cur = *head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = mode1;
	}
	return (mode1);
}
