#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order using the
 * bubble sort algorithm
 * @array: the array of integers to sort
 * @size: size of the array
 *
 * Return: Always 0
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i = 0, j = 0;
	int temp; /* store data whiel swapping elements */
	bool swapped;

	while (j < size)
	{
		swapped = false;
		while (i < size - 1 - j)
		{
			if (array[i] > array[i + 1])
			{
				/* swap elements */
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swapped = true;
			}
			i++;
		}
		if (swapped == false) /* i.e. array is sorted */
			break;
		i = 0;
		j++;
	}
}
