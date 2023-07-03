#include "main.h"

/**
 * _strstr - locates a substring in a string
 * @haystack: input string
 * @needle: substring to be found
 *
 * Return: a pointer to the beginning of the substring in the haystack,
 *         or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *l = haystack;
		char *p = needle;

		while (*l == *p && *p != '\0')
		{
			l++;
			p++;
		}

		if (*p == '\0')
			return (haystack);
	}

	return (0);
}
