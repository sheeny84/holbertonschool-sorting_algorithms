#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"
#include "swap_nodes.c"

/**
 * insertion_sort_list - Sort a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: the doubly linked list of integers to sort
 *
 * Return: Always 0
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp_head, *temp, *next;

	temp_head = (*list)->next; /* start at second node */
	while (temp_head != NULL)
	{
		next = temp_head->next;
		temp = temp_head;
		while (temp->prev != NULL)
		{
			if (temp->n < (temp->prev)->n)
			{
				/* swap elements */
				swap_nodes(list, temp->prev);
				print_list(*list);
			}
			else /* i.e. no elements swapped */
				break;
		}
		temp_head = next;
	}
}
