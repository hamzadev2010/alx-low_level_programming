#include "main.h"

/**
 * set_string - sets the value of a pointer to a char
 * @s: pointer to pointer to be set
 * @to: pointer to char to set to
 *
 * Return: void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
