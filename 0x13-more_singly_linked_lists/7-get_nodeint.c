#include "lists.h"
#include <stdlib.h>
/**
 * get_nodeint_at_index - returns nth node
 * @head: beginning of the node
 * @index: int to be used
 * Return: nth node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *jum = head;
	unsigned int ink = 0;

	while (jum != NULL)
	{
		if (ink == index)
		{
			return (jum);
		}
		jum = jum->next;
		ink++;
	}
	return (NULL);
}
