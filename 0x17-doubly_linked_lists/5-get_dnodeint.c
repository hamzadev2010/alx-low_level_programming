#include "lists.h"

/**
 * get_dnodeint_at_index - function that retrieves the nth node of a
 * doubly linked list at a given index.
 * @head: pointer to the head of the list.
 * @index: position of the node, starting from 0.
 *
 * If the node does not exist, return NULL.
 *
 * Return: the nth node of the dlistint_t linked list.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	i = 0;

	if (!head)
		return (NULL);

	while (head != NULL)
	{
		if (i == index)
			break;
		i++;
		head = head->next;
	}
	return (head);
}
