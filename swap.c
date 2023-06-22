#include "monty.h"

/**
 * stack_len - counts the elements in a stack
 * @h: Head of the stack
 *
 * Return: number of nodes in the linked list
 */
int stack_len(stack_t *h)
{
	int count = 0;
	stack_t *item = h;

	if (item == NULL)
	{
		return (-1);
	}

	while (item != NULL)
	{
		count++;
		item = item->next;
	}

	return (count);
}


/**
 * swap - swaps the first two numbers.
 * @top: The top of the stack
 * @line_number: The line_number of the stack
*/
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *node_1 = *top;
	stack_t *node_2 = node_1->next;
	int len = 0;

	len = stack_len(*top);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node_1->next = node_2->next;
	node_1->prev = node_2;
	node_2->next = node_1;
	node_2->prev = NULL;
	if (node_1->next != NULL)
	{
		node_1->next->prev = node_1;
	}
	*top = node_2;
}

