#include "monty.h"

/**
 * is_whitespace - checks if the input is basically all spaces
 * @input: Input string
 *
 * Return: 0 if not whitespace, 1 if whitespace
 */
int is_whitespace(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n' &&
			input[i] != '\v' && input[i] != '\f' && input[i] != '\r')
		{
			return (0); /* is not whitespace */
		}
	}
	return (1); /* is whitespace */
}

/**
 * handle_exit_failure - handles the EXIT_FAILURE exit situation
 * @l: The line of the file
 * @args: The arguments array of the line
 * @ac: The argument array count
 * @s: The stack being worked on
 * @file: The file opened
*/
void handle_exit_failure(char *l, char **args, int ac, stack_t **s, FILE *file)
{
	free(l);
	free_args(args, ac);
	free_stack(*s);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * handle_push - handles the push opcode
 * @arg: The argument array (args[])
 * @l: The line (line)
 * @s: The stack (stack)
 * @file: The monty file
 * @ac: The argument count of the args array
 * @l_n: The line number
*/
void handle_push(char **arg, char *l, stack_t **s, FILE *file, int ac, int l_n)
{
	if (arg[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_n);
		handle_exit_failure(l, arg, ac, s, file);
	}
	push_arg = arg[1];
}

/**
 * run_opcode - handles the opcode instruction on a line
 * @line: The current line of the file
 * @stack: The stack for the opcode to work on
 * @line_number: The line number of the current line
 * @file: The file being worked on
*/
void run_opcode(char *line, stack_t **stack, int line_number, FILE *file)
{
	int arg_count, i = 0;
	char **args, *opcode;
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"swap", swap},
		{"pop", pop}, {"add", add},
		{"nop", nop}, {NULL, NULL}
	};

	if (is_whitespace(line))
		return;
	arg_count = count_args(line, " \t\n");
	args = get_args(line, " \t\n");
	if (args == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = args[0];
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			if (strcmp(opcodes[i].opcode, "push") == 0)
				handle_push(args, line, stack, file, arg_count, line_number);
			else
				push_arg = NULL;
			opcodes[i].f(stack, line_number);
			free_args(args, arg_count);
			return;
		}
	}
	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		handle_exit_failure(line, args, arg_count, stack, file);
	}
}
