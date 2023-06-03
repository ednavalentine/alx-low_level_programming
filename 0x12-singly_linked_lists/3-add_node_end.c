#include "lists.h"
#include <stdlib.h>
#include <string.h>
/**
 * add_node_end - add end of node
 * @head: head of the node
 * @str: parameter to be used
 * Return: tail
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *ink;
	char *jum;
	list_t *curr;

	if (str == NULL)
		return (NULL);
	ink = malloc(sizeof(list_t));
	if (ink == NULL)
		return (NULL);
	jum = strdup(str);
	if (jum == NULL)
	{
		free(ink);
		return (NULL);
	}
	ink->str = jum;
	ink->next = NULL;
	if (*head == NULL)
	{
		*head = ink;
	}
	else
	{
		curr = *head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = ink;
	}
	return (ink);
}
