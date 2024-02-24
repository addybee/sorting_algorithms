#include "sort.h"
listint_t *swap_nodes(listint_t **head, listint_t *node);
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: the head of the double linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int  swapped = 1;
	listint_t *head = NULL, *tail = NULL, *current;

	if (!list || !*list || !(*list)->next)
		return;
	current = *list;
	while (swapped)
	{
		swapped = 0;
		while (current->next != tail)
		{
			if (current->n > current->next->n)
			{
				current = swap_nodes(list, current->next);
				swapped = 1;
				print_list(*list);
			}
			current = current->next;
		}

		if (!swapped)
			break;
		swapped = 0;
		tail = current;
		current = current->prev;
		while (current->prev != head)
		{
			if (current->n < current->prev->n)
			{
				current = swap_nodes(list, current);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}

		head = current;
		current = current->next;
	}
}


/**
 * swap_nodes - swap two node
 * @head: pointer to pointer of head of list of integer
 * @node: to swap
 * Return: the node that is swapped to the left
 */

listint_t *swap_nodes(listint_t **head, listint_t *node)
{
	listint_t *prev_node = node->prev;
	listint_t *current_node = node;

	prev_node->next = current_node->next;
	if (current_node->next)
		current_node->next->prev = prev_node;
	current_node->next = prev_node;
	current_node->prev = prev_node->prev;
	prev_node->prev = current_node;
	if (current_node->prev)
		current_node->prev->next = current_node;
	else
		*head = current_node;
	return (current_node);
}
