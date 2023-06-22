#include "monty.h"

/**
 * *add_dnodeint - Adds a node on the beginning of a stack
 * @head: Head of the linked list
 * @n: The number value of the linked list
 *
 * Return: pointer to the newly created node,
 * NULL if it fails
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;
	int tmp = n;

	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = tmp;
	new->prev = NULL;
	new->next = *head;
	if ((*head) != NULL)
		(*head)->prev = new;
	(*head) = new;

	return (new);
}
