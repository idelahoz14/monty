#include "monty.h"

/**
 * get_op_func - get the function to use
 * @code: Operation code
 * @ln: Number of read line
 * Return: seleccted function
 */
void (*get_op_func(char *code, unsigned int ln))(stack_t **stack, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
	};

	unsigned int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, code) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln, code);
	return (ops[i].f);
}

/**
 * verification - Function that verifies command and arguments
 * @stack: Top of the list
 * @line: number of read line
 * @col_strings: parsed strings
 * Return: integer
 */
int verification(unsigned int line, char **col_strings, stack_t **stack)
{
	if (strcmp(col_strings[0], "push") == 0)
	{
		if (is_number(col_strings[1]) == 1)
		{
			glob_vars.glob_int = atoi(col_strings[1]);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free_list(*stack);
			free(col_strings);
			exit(EXIT_FAILURE);
		}
		get_op_func(col_strings[0], line)(stack, line);
	}
	else
	{
		get_op_func(col_strings[0], line)(stack, line);
	}

	return (0);
}
