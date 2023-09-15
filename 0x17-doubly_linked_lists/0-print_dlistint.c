#include "lists.h"

/**
 * print_dlistint - function that display all the element of a doubly linked list
 * @h: pointer to the top of the list
 *
 * Return: the number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	
	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}
