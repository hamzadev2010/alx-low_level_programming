#include "main.h"

/**
 * main - Entry point of the program
 *
 * Description: Calls the _isalpha function to check if characters are alphabetic
 *              and prints the results.
 *
 * Return: Always 0
 */
int main(void)
{
	int r;

	r = _isalpha('H');
	_putchar(r + '0');
	r = _isalpha('o');
	_putchar(r + '0');
	r = _isalpha(108);
	_putchar(r + '0');
	r = _isalpha(';');
	_putchar(r + '0');
	_putchar('\n');
	return (0);
}
