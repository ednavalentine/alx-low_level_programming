#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * detect_loop - detect and return the node where the loop starts
 * @head: parameter to be used
 * Return: 0
 */
const listint_t *detect_loop(const listint_t *head)
{
	const listint_t *tort = head;
	const listint_t *hare = head;

	while (hare && hare->next)
	{
		tort = tort->next;
		hare = hare->next->next;
		if (tort == hare)
			return (tort);
	}
	return (NULL);
}

/**
 * print_listint_safe - prints a linked list
 * @head: beginning of node
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *ink_start;
	const listint_t *mode;
	size_t jum = 0;

	ink_start = detect_loop(head);
	mode = head;
	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		jum++;
		if (head == ink_start)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			if (ink_start != NULL)
			{
				do
				{
					mode = mode->next;
					printf("[%p] %d\n", (void *)mode, mode->n);
					jum++;
				} while (mode != ink_start);
			}
			exit(98);
		}
		head = head->next;
	}
	return (jum);
}
