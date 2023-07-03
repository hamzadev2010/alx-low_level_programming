#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: memory where data is copied
 * @src: memory where data is read from
 * @n: number of bytes to be copied
 *
 * Return: pointer to the destination memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
