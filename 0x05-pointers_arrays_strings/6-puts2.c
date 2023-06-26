#include "main.h"

/**
 * puts2 - Prints every other character 
 * @str: Input string.
 *
 * Return: void
 */
void puts2(char *str)
{
	int length = 0;
	int i;
	char *temp = str;

	while (*temp != '\0')
	{
		temp++;
		length++;
	}

	for (i = 0; i < length; i++)
	{
		if (i % 2 == 0)
		{
			_putchar(str[i]);
		}
	}

	_putchar('\n');
}
