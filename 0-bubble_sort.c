#include "sort.h"
/**
 *bubble_sort -  sorts an array of integers in ascending order
 *@array: array to sort
 *@size: size of the array
 *Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y, temp;

	if (!array)
		return;

	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
