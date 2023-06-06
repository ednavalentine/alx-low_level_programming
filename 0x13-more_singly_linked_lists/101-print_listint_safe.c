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
	const listint_t *ink = head;
	size_t jum = 0;

	while (ink != NULL)
	{
		printf("[%p] %d\n", (void *)ink, ink->n);
		jum++;
		if (ink <= ink->next)
		{
			printf("-> [%p] %d\n", (void *)ink->next, ink->next->n);
			exit(98);
		}
		ink = ink->next;
	}
	return (jum);
}
