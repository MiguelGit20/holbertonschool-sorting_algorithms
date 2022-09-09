#include "sort.h"
/**
 *insertion_sort_list - sorts a doubly linked list in ascending order
 *@list: double linked list
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prevN, *nextN;

	if (!list)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		if (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				prevN = current->prev;
				nextN = current->next;
				current->prev = prevN->prev;
				current->next = prevN;
				if (current->prev != NULL)
					current->prev->next = current;

				prevN->prev = current;
				prevN->next = nextN;
				if (nextN != NULL)
					nextN->prev = prevN;
				if (current->prev == NULL)
					*list = current;

				print_list(*list);
			}
			else
				current = current->next;
		}
		else
			current = current->next;
	}

}
