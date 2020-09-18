#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_vars - struct for global variables
 * @glob_int: integer
 *
 * Description: structure that contains the variables
 * shared across the whole program
 */
typedef struct glob_vars
{
	int glob_int;
} glob_t;

extern glob_t glob_vars;
glob_t glob_vars;

void push(stack_t **stack, unsigned int);
void pall(stack_t **stack, unsigned int);
void pint(stack_t **stack, unsigned int);
void pop(stack_t **stack, unsigned int);
void swap(stack_t **stack, unsigned int);
void add(stack_t **stack, unsigned int);
void nop(stack_t **stack, unsigned int);

char **split(char *line);
int verification(unsigned int line, char **col_strings, stack_t **stack);
void (*get_op_func(char *opcode, unsigned int))(stack_t **stack, unsigned int);
void free_list(stack_t *stack);
int is_number(char *col_strings);

#endif
