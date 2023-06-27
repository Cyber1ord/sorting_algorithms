#include "sort.h"

/**
 * list_len - function returns length of list
 * @list: head of list
 *
 * Return: length
 */
size_t list_len(listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * swap_nodes - function swaps nodes at given pointers
 * @list: pointer to list
 * @node1: pointer to first node
 * @node2: pointer to second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - function sorts a doubly linked list using
 * the cocktail sort algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL;
	int sorted = 0;

	if (!list || !(*list) || list_len(*list) < 2)
		return;

	while (!sorted)
	{
		sorted = 1;
		for (listint_t *current = *list; current->next != start; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				sorted = 0;
			}
		}

		if (sorted)
			break;

		sorted = 1;
		start = (*list)->prev;

		for (listint_t *current = start; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				sorted = 0;
			}
		}
	}
}
