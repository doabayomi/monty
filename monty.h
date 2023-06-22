#ifndef MONTY_H_
#define MONTY_H_

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **top, unsigned int line_number);
void pall(stack_t **top, unsigned int line_number);
void pint(stack_t **top, unsigned int line_number);
void swap(stack_t **top, unsigned int line_number);
void pop(stack_t **top, unsigned int line_number);
void add(stack_t **top, unsigned int line_number);
void nop(stack_t **top, unsigned int line_number);

stack_t *add_dnodeint(stack_t **head, const int n);
void free_stack(stack_t *head);
char *strdup(const char *str);

int count_args(char *input, char *delimiter);
char **get_args(char *input, char *delimiter);
void free_args(char **args, int arg_count);

void run_opcode(char *line, stack_t **stack, int line_number, FILE *file);
int is_whitespace(char *input);
int check_int(const char *num);
int stack_len(stack_t *h);

extern char *push_arg;

#endif /* MONTY_H_ */
