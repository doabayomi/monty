#include "monty.h"

/**
 * pop - removes the top element from the stack.
 * @top: The top of the stack
 * @line_number: The line_number of the stack
*/
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *item_to_pop = *top;
	stack_t *new_stack = item_to_pop->next;

	if (item_to_pop == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	item_to_pop->next = NULL;
	free_stack(item_to_pop);

	if (new_stack != NULL)
	{
		new_stack->prev = NULL;
	}
	*top = new_stack;
}
