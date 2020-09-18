#include "monty.h"
/**
 * main - Entry Point
 * @argc: Arguments count
 * @argv: Array with actual arguments
 * Description: Entry Point
 * Return: EXIT_SUCCESS on success and EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[])
{
	FILE *fptr;
	char **col_strings = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	if (!fptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fptr)) != -1)
	{
		col_strings = split(line);
		if (!col_strings)
		{
			line_number++;
			continue;
		}
		verification(line_number, col_strings, &stack);
		line_number++;
		free(col_strings);
	}
	fclose(fptr);
	free(line);
	if (stack)
	{
		free_list(stack);
	}
	return (EXIT_SUCCESS);
}
