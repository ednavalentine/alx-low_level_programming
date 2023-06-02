#include "lists.h"
#include <stdio.h>
#include <stddef.h>
/**
 * print_list - prints a list
 * @h: constant list variable
 * Return: list
 */
size_t print_list(const list_t *h)
{
	const list_t *ink = h;
	size_t jum = 0;

	while (ink != NULL)
	{
		printf("[%u} ", ink->len);
		if (ink->str != NULL)
		{
			printf("%s", ink->str);
		}
		else
		{
			printf("(nil)");
		}
		printf("\n");
		jum++;
		ink = ink->next;
	}
	return (jum);
}
