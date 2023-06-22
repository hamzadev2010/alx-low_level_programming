#include "main.h"

/**
 * print_numbers - Prints numbers between 0 and 9.
 *
 * Return: No return value (void).
 */
void print_numbers(void)
{
	int ch;

	for (ch = 48; ch < 58; ch++)
	{
		_putchar(ch);
	}
	_putchar('\n');
}
