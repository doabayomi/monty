#include "monty.h"

/**
 * pall - prints all the elements in a stack
 * @top: The top of the stack
 * @line_number: The line_number of the stack
*/
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *item = *top;
	(void)line_number;

	if (item == NULL)
		return;
	while (item != NULL)
	{
		printf("%d\n", item->n);
		item = item->next;
	}

}
