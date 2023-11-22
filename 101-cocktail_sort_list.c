#include "sort.h"

/**
 * swap_list - swaps two nodes in a list
 * @head: a pointer to the head of the list
 * @node_a: a pointer to the first node to swap
 * @node_b: a pointer to the second node to swap
 */
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
 * cocktail_sort_list - implements the cocktail shaker sort algorithm
 *
 * @head: a pointer to the head node of a list
 */
void cocktail_sort_list(listint_t **head)
{
	bool swap_state = false;
	listint_t *tmp = *head;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	do {
		for (; tmp->next;)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_list(head, &tmp, &(tmp->next));
				print_list(*head);
				swap_state = true;
			}
			else
				tmp = tmp->next;
		}
		if (swap_state == false)
			break;  /* Array in correct order*/
		swap_state = false;
		for (; tmp->prev;)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap_list(head, &(tmp->prev), &tmp);
				print_list(*head);
				swap_state = true;
			}
			else
				tmp = tmp->prev;
		}
	} while (swap_state);
}
