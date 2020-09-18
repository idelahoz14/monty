#include "monty.h"

/**
 * free_list - free a double linked list
 * @stack: head of the lk list
 * Return: Nothing
 */
void free_list(stack_t *stack)
{
	stack_t *head;

	if (stack == NULL)
	{
		return;
	}

	while (stack != NULL)
	{
		head = stack;
		stack = stack->next;
		free(head);
	}
}
