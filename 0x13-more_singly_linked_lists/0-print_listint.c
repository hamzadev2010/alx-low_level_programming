#include "lists.h"

/**
 * print_listint - show all element 
 * @h:  list related listint_t
 *
 * Return: nombre de node 
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}

	return (num);
}
