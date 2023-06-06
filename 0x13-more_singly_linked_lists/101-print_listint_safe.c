#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_listint_safe - prints a linked list
 * @head: beginning of node
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *ink = NULL;
	const listint_t *mode = NULL;
	size_t jum = 0;
	size_t node;

	ink = head;
	while (ink)
	{
		printf("[%p] %d\n", (void *)ink, ink->n);
		jum++;
		ink = ink->next;
		mode = head;
		node = 0;
		while (node < jum)
		{
			if (ink == mode)
			{
				printf("[%p] %d\n", (void *)ink, ink->n);
				return (jum);
			}
			mode = mode->next;
			node++;
		}
		if (!head)
			exit(98);
	}
	return (jum);
}
