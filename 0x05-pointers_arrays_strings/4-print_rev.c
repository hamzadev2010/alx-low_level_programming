#include "main.h"

/**
 * print_rev - Prints a string in reverse order.
 * @s: A pointer to the string to be printed.
 *
 * Return: void
 */
void print_rev(char *s)
{
	int length = 0;
	int i;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	s--;

	for (i = length; i > 0; i--)
	{
		_putchar(*s);
		s--;
	}

	_putchar('\n');
}
