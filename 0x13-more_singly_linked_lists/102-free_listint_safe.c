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
	listint_t *next;

	if (h == NULL || *h == NULL)
		return (jum);
	ink = *h;
	while (ink != NULL)
	{
		next = ink->next;
		printf("[%p] %d\n", (void *)ink, ink->n);
		free(ink);
		jum++;
		ink = next;
	}
	printf("(nil), (nil)\n");
	*h = NULL;
	return (jum);
}
