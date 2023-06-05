#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * add_nodeint - adds node at beginning of list
 * @head: beginning of the node
 * @n: int to be used
 * Return: node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *mode;

	if (head == NULL)
		return (NULL);
	mode = (listint_t *)malloc(sizeof(listint_t));
	if (mode == NULL)
		return (NULL);
	mode->n = n;
	mode->next = *head;
	*head = mode;
	return (mode);
}
