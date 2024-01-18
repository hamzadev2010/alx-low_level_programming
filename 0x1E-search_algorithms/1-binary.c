#include "search_algos.h"

/**
 * binary_search -  searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: the pointer
 * @size: element number
 * @value: the value of search
 * Return: the value or -1
 * array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left, right, moyenne, i;

	if (array== NULL)
		return (-1);

	left = 0;
	right = size - 1;

	while (left <= right)
	{
		moyenne = (left + right) / 2;
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
			printf("%i%s", array[i], i == right ? "\n" : ", ");
		if (array[moyenne] < value)
			left = moyenne + 1;
		else if (array[moyenne] > value)
			right = moyenne - 1;
		else
			return ((int)moyenne);
	}

	return (-1);
}
