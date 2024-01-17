#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * function that searches for a value in an array of
 * integers using the Linear search algorithm 
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (!array || size == 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
