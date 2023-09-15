#include "lists.h"

/**
 * sum_dlistint - function that calculates the sum of all the
 * data (n) in a linked list.
 * @head: pointer to pointer to the head of the linked list.
 *
 * If the list is empty, return 0.
 *
 * Return: The sum of the data.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
