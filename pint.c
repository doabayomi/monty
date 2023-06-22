#include "monty.h"

/**
 * pint - prints all the elements in a stack
 * @top: The top of the stack
 * @line_number: The line_number of the stack
*/
void pint(stack_t **top, unsigned int line_number)
{
	stack_t *item = *top;
	(void)line_number;

	if (item == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", item->n);
}
