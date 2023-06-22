#include "main.h"

/**
 * _isdigit - Checks if the parameter is a number between 0 and 9.
 * @c: Input number.
 *
 * Return: 1 if it is a number (0 to 9), 0 otherwise.
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
