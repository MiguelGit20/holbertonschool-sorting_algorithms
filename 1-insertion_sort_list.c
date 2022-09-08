#include "sort.h"
/**
 *sortedInsert - insert node
 *@list: double linked list
 *@newNode: node
 *Return: void
 */
void sortedInsert(listint_t **list, listint_t *newNode)
{
	listint_t *current;

	if (*list == NULL)
		*list = newNode;
	else if ((*list)->n >= newNode->n)
	{
		newNode->next = *list;
		newNode->next->prev = newNode;
		*list = newNode;
	}
	else
	{
		current = *list;
		while (current->next != NULL && current->next->n < newNode->n)
			current = current->next;
		newNode->next = current->next;
		if (current->next != NULL)
			newNode->next->prev = newNode;
		current->next = newNode;
		newNode->prev = current;
	}
}
/**
 *insertion_sort_list - sorts the list
 *@list: double linked list
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current = *list;
	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->prev = current->next = NULL;
		sortedInsert(&sorted, current);
		current = next;
	}
	*list = sorted;
}
