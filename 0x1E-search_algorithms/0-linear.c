#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers
 *  using the Linear search algorithm
 *  @array: A ptr to the first element of the array to search in
 *  @size: The number of elements in array
 *  @value: The value to search for
 *  Return: The first index where value is located
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL || size == 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
