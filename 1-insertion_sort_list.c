#include "sort.h"

/**
 * insertion_sort_list - insertion sorting algorithm
 * @list: linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;

	while (current != NULL)
	{
		listint_t *insertion = current;
		int value = insertion->n;

		while (insertion->prev != NULL && insertion->prev->n > value)
		{
			insertion->n = insertion->prev->n;
			insertion = insertion->prev;
		}

		insertion->n = value;
		current = current->next;
		print_list(*list);
	}
}
