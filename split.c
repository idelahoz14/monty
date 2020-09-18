#include "monty.h"
/**
 * split - Parses the line into tokens
 * @line: string read by getline function
 *
 * Return: Array of tokens on success, NULL on failure
 *
 */
char **split(char *line)
{
	int i;
	char **nest = NULL;
	char *token = NULL;

	nest = malloc(sizeof(char *) * 1024);
	if (!nest)
	{
		exit(1);
	}
	token = strtok(line, " \n\t\r\a");
	if (token == NULL || *token == ' ' || *token == '\n' || *token == '#')
	{
		free(nest);
		return (NULL);
	}
	for (i = 0; token != NULL; i++)
	{
		nest[i] = token;
		token = strtok(NULL, " \n\t\r\a");
	}
	nest[i] = NULL;
	return (nest);
}
