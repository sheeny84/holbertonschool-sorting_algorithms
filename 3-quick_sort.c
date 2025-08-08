#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

/**
 * lomuto_partition - implement lomuto partition
 * @array: array to partition
 * @min: min ind
 * @last: last element ind
 * @size: size of the array
 *
 * Return: pivot index
 */
int lomuto_partition(int *array, int min, int last, size_t size)
{
	int pivot = array[last]; /* set pivot to last element */
	int i = min; /* index of first element */
	int j = min;
	int temp;

	while (j < last)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
			i++;
		}
		j++;
	}
	temp = array[i];
	array[i] = array[last];
	array[last] = temp;
	if (i != j)
		print_array(array, size);

	return (i);
}

/**
 * quick_sort_recursive - recursive implementation of quick sort
 * @array: array of integers
 * @min: min ind
 * @last: last element ind
 * @size: size of array
 *
 * Return: nothing
 */
void quick_sort_recursive(int *array, int min, int last, size_t size)
{
	int part_ind; /* partitioning index */

	if (min < last)
	{
		part_ind = lomuto_partition(array, min, last, size);
		/* separately sort elements before and after partition */
		quick_sort_recursive(array, min, part_ind - 1, size);
		quick_sort_recursive(array, part_ind + 1, last, size);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order using the
 * quick sort algorithm with the Lomuto partition scheme
 * @array: the array of integers to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}
