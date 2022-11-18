#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
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

/**
 * struct line - cntents of line and corresponding number.
 * @content: array of tokens read from the line.
 * @number the line number.
 *
 * Description: contents of a line and corresponding number.
 */

typedef struct line
{
	unsigned int number;
	char **content;
} line_t;

/**
 * struct data_s - contains the script name.
 * @buf: buffer.
 * @stack: read from stack.
 * @FILE: filename.
 *
 * Description: contains the filename and buffer.
 */

typedef struct data_s
{
	char *buf;
	stack_t *stack;
	FILE *file;
}data_t;

void (*op_selector(line_t line, data_t *data))(stack_t **, unsigned int)

void parseline(line_t *line, char *buffer);
void parsefile(FILE *file);

#endif
