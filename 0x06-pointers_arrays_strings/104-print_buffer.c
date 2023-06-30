#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints the content of a buffer
 * @b: The buffer to be printed
 * @size: The size of the buffer
 *
 * Return: void
 */
void print_buffer(char *b, int size)
{

	int o, j, i;

	o = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	while (o < size)
	{
		j = (size - o < 10) ? size - o : 10;
		printf("%08x: ", o);

		for (i = 0; i < 10; i++)
		{
			printf(i < j ? "%02x" : "  ");
			printf(i % 2 ? " " : "");
		}

		for (i = 0; i < j; i++)
		{
			int c = *(b + o + i);

			printf((c < 32 || c > 132) ? "." : "%c", c);
		}

		printf("\n");
		o += 10;
	}
}
