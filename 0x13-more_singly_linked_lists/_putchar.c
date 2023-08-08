#include <unistd.h>

/**
 * _putchar -  character c to stdout
 * @c: character to print
 *
 * Return: On success 1.
 * while error, -1 is returne.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
