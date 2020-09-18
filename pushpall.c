#include "monty.h"

/**
 * pall - prints all the values on the stack, starting on the top
 * @stack: Top of the linked list
 * @line_num: Number of read line
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *head;

	if (!stack)
	{
		fprintf(stderr, "L%d: Need to use line_num\n", line_num);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * push - pushes an argument to the beginning of a lk list
 * @stack: top of the lk linst
 * @line_num: number of read line
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node;

	if (!stack)
	{
		fprintf(stderr, "L%d: Need to use line_num\n", line_num);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = glob_vars.glob_int;
	new_node->next = (*stack);
	new_node->prev = NULL;
	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
