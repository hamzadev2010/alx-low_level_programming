#include "search_algos.h"
#include <math.h>

/**
 * jump_search - function that searches for a value in
 * a sorted array of integers using the Jump search algorithm
 * @array: the array (input)
 * @size: array size
 * @value: the value
 * Return: the last value
 */
int jump_search(int *array, size_t size, int value)
{
	int big, c, d, last;

	if (!array || !size)
		return (-1);

	c = (int)sqrt((double)size);
	d = 0;
	last = big = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", last, array[last]);

		if (array[last] == value)
			return (last);
		d++;
		big = last;
		last = d * c;
	} while (last < (int)size && array[last] < value);

	printf("Value found between indexes [%d] and [%d]\n", big, last);
        

	while ( big <= last && big < (int)size)
	{
		printf("Value checked array[%d] = [%d]\n", big, array[last]);
		if (array[big] == value)
			return (big);
		big++;
	}

	return (-1);
}
