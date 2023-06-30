#include "main.h"
#include <stdio.h>

/**
 * rot13 - encodes a string using the rot13 cipher
 * @s: pointer to the string to be encoded
 *
 * Return: pointer to the encoded string
 */
char *rot13(char *s)
{
	int i, j;
	char data1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char datarot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == data1[j])
			{
				s[i] = datarot[j];
				break;
			}
		}
	}

	return (s);
}
