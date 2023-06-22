#include "main.h"

/**
 * print_line - Prints a straight line n times.
 *
 * @n: Number of times the straight line is printed.
 *
 * Return: No return value (void).
 */
void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		_putchar(95);
	}
	_putchar('\n');
}
