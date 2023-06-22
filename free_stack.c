#include "monty.h"

/**
 * free_dlistint - frees a doubly linked list
 * @head: Head of the doubly linked list
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *tmp = head;
	stack_t *next_node;

	while (tmp != NULL)
	{
		next_node = tmp->next;
		tmp->prev = NULL;
		tmp->next = NULL;
		free(tmp);
		tmp = next_node;
	}
}
