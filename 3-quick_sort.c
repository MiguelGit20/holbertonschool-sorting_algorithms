#include "sort.h"
/**
 *quick_sort - sorts an array of integers in ascending order
 *@array: array
 *@size: size of the array
 *Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}
/**
 *swap - it swaps two elements
 *@x: first element
 *@y: second element
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}
/**
 *partition - split array around pivot
 *@array: array
 *@first: first element
 *@last: last element
 *@size: size of the array
 *Return: 0
 */
int partition(int *array, int first, int last, size_t size)
{
	int pivot = array[last];
	int i = first;
	int j;

	for (j = first; j < last; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap(&array[i], &array[last]);
	if (i != j)
		print_array(array, size);
	return (i);
}
/**
 *quickSort - sort a part of the list
 *@array: array
 *@first: first element
 *@last: last element
 *@size: size of the array
 */
void quickSort(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		quickSort(array, first, pivot - 1, size);
		quickSort(array, pivot + 1, last, size);
	}
}
