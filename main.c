#include "monty.h"
#define _GNU_SOURCE

char *push_arg = NULL;

/**
 * main - The main of the interpreter
 * @argc: The number of arguments
 * @argv: Array containing the arguments
 *
 * Return: 0
*/
int main(int argc, char *argv[])
{
	char *m_filename;
	FILE *m_file;
	char *line = NULL;
	size_t line_size = 0;
	int line_length, line_number = 0;
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	m_filename = argv[1];
	m_file = fopen(m_filename, "r");
	if (m_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", m_filename);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	line_length = getline(&line, &line_size, m_file);
	while (line_length != -1)
	{
		line_number++;
		run_opcode(line, &stack, line_number, m_file);
		line_length = getline(&line, &line_size, m_file);
	}

	free(line);
	fclose(m_file);
	free_stack(stack);
	return (0);
}
