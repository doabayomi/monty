#include "monty.h"

/**
 * check_int - checks if a string is an number
 * @num: The string representation of a number
 *
 * Return: 0 if not an integer, 1 if integer
*/
int check_int(const char *num)
{
	if (num == NULL || num[0] == '\0')
		return (0);

	while (*num != '\0')
	{
		if (*num < '0' || *num > '9')
			return (0);
		num++;
	}

	return (1);
}

/**
 * push - pushes a value to the top of the stack
 * @top: The top of the stack;
 * @line_number: The line number of the opcode
*/
void push(stack_t **top, unsigned int line_number)
{
	char *arg = push_arg;
	int is_int = check_int(push_arg);
	int num;

	if (!(is_int))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		num = atoi(arg);
		add_dnodeint(top, num);
	}
}

