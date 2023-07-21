#include "lists.h"
/**
 * add_dnodeint_end - adds a node to the end
 * @head: pointer to the start and end of the node
 * @n: integer to be used
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newnode;
	dlistint_t *lastnode;

	newnode = (dlistint_t *)malloc(sizeof(dlistint_t));
	if (newnode != NULL)
	{
		return (NULL);
	}
	newnode->n = n;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		lastnode = *head;
		while (lastnode->next != NULL)
		{
			lastnode = lastnode->next;
		}
		lastnode->next = newnode;
		newnode->prev = lastnode;
	}
	return (newnode);
}
