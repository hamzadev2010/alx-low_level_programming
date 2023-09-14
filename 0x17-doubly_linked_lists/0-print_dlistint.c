#include "lists.h"

/**
 * print_dlistint - display all elements of a dlistint_t list.
 * @h: The head of the dlistint_t list.
 *
 * Return: a number of all nodes 
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (nodes);
}
