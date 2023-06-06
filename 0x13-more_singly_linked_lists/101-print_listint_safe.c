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
	long int ink;
	size_t jum = 0;

	while (head)
	{
		ink = head - head->next;
		jum++;
		printf("[%p] %d\n", (void *)head, head->n);
		if (ink > 0)
			head = head->next;
		else
		{
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			exit(98);
		}
	}
	return (jum);
}
