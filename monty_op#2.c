#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: Top of the linked list
 * @line_num: number of read line
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: Top of the linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *head;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	head = (*stack);
	if ((*stack)->next)
	{
		(*stack) = (*stack)->next;
		glob_vars.glob_int = (*stack)->n;
		(*stack)->prev = NULL;
		free(head);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: Top of the linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int aux;

	if (!stack || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = aux;
}

/**
 * add - adds the top two elements of the stack
 * @stack: Top of the Linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_num)
{
	int aux;
	stack_t *head;

	head = (*stack);

	if (!stack || !*stack || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->n;
	aux += (*stack)->next->n;
	(*stack)->next->n = aux;
	*stack = (*stack)->next;
	free(head);
}

/**
 * nop - doesn’t do anything
 * @stack: Top of the linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
