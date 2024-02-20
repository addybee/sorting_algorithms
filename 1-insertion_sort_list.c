#include "sort.h"
listint_t *swap_nodes(listint_t **head, listint_t *node);
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 *
 * @list: pointer to pointer of head of list of integer
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;
	current = (*list)->next;
	while (current)
	{
		temp = current->next;
		while (current->prev != NULL && current->prev->n > current->n)
		{
			current = swap_nodes(list, current);
			print_list(*list);
		}
		current = temp;
	}
}

/**
 * swap_nodes - swap two node
 * @head: pointer to pointer of head of list of integer
 * @node: to swap
 * Return: new head
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
