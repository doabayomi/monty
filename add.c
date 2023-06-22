#include "monty.h"

/**
 * add - adds the first two elements
 * @top: The top of the stack
 * @line_number: The line_number of the stack
*/
void add(stack_t **top, unsigned int line_number)
{
	stack_t *first = *top;
	stack_t *second = first->next;
	int sum;
	int len = 0;

	len = stack_len(*top);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = first->n + second->n;
	second->n = sum;
	*top = first;
	pop(top, line_number);
}
