#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * free_listint_safe - frees a listint_t list
 * @h: parameter to be used
 * Return: size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t jum = 0;
	listint_t *ink;
	listint_t *mode;
	int node;

	if (h == NULL || *h == NULL)
		return (0);
	ink = *h;
	jum = 0;
	while (ink != NULL)
	{
		node = ink - ink->next;
		if (node > 0)
		{
			mode = ink->next;
			free(ink);
			ink = mode;
			jum++;
		}
		else
		{
			free(ink);
			jum++;
			break;
		}
	}
	*h = NULL;
	return (jum);
}
