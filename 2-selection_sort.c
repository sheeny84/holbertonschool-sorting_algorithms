#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order using the
 * selection sort algorithm
 * @array: the array of integers to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i = 0, j = 0;
	int imin, temp;
	bool swapped;

	while (i < (size - 1))
	{
		swapped = false;
		imin = i; /* index of min data */
		j = i + 1;
		while (j < size)
		{
			/* find ind of min value */
			if (array[j] < array[imin])
			{
				imin = j;
				swapped = true;
			}
			j++;
		}
		/* swap elements */
		if (swapped == true)
		{
			temp = array[i];
			array[i] = array[imin];
			array[imin] = temp;
			print_array(array, size);
		}
		i++;
	}
}
