#include "sort.h"
/**
 *selection_sort - it sorts an array of integers in ascending order
 *@array: array
 *@size: size of the array
 *Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_element;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_element = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_element])
			{
				min_element = j;
			}
		}
		if (min_element != i)
		{
			swap(&array[i], &array[min_element]);
			print_array(array, size);
		}
	}
}

/**
 *swap - it swaps two elements
 *@x: first element
 *@y: seconm element
 */
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
