#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _l - reallocates memory of arrays
 * @list: list to be reallocated
 * @size: new size of list
 * @now: new node to be added to the list
 * Return: pointer to list
 */
const listint_t **_l(const listint_t **list, size_t size, const listint_t *now)
{
	const listint_t **tort;
	size_t ink;

	tort = malloc(size * sizeof(listint_t *));
	if (tort == NULL)
	{
		free(list);
		exit(98);
	}
	for (ink = 0; ink < size - 1; ink++)
		tort[ink] = list[ink];
	tort[ink] = now;
	free(list);
	return (tort);
}

/**
 * print_listint_safe - prints a linked list
 * @head: beginning of node
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t inker, jum = 0;
	const listint_t **ink = NULL;

	while (head != NULL)
	{
		for (inker = 0; inker < jum; inker++)
		{
			if (head == ink[inker])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(ink);
				return (jum);
			}
		}
		jum++;
		ink = _l(ink, jum, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(ink);
	return (jum);
}
