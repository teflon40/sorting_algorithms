/**
 * swap_list - A function to swap elements in a doubly linked list
 *
 * @head: Head of the list that points to NULL
 *
 * @node_a: First node for comparison
 *
 * @node_b: Second node for comparison
 */

#include "sort.h"

void swap_list(listint_t **head, listint_t **node_a, listint_t **node_b)
{
	listint_t *a, *b;

	a = *node_a, b = *node_b;

	if (b->next != NULL)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;
	if (a == *head)
		*head = b;
	else
		b->prev->next = b;
}
/**
 * insertion_sort_list - A function to insert elements into a list
 *
 * @head: The head of the list that points to NULL
 */

void insertion_sort_list(listint_t **head)
{
	listint_t *tmp, *ptr;

	if (head == NULL || *head == NULL)
		return;
	tmp = (*head)->next;
	while (tmp != NULL)
	{
		for (ptr = tmp; ptr != *head && (ptr->n < ptr->prev->n);)
		{
			swap_list(head, &(ptr->prev), &ptr);
			print_list(*head);
		}
		tmp = tmp->next;
	}
}
