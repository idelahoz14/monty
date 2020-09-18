#include "monty.h"

/**
 * is_number - checks if the push command has a number
 * @col_strings: character to be checked
 *
 * Return: 0 on failure, 1 on success
 */
int is_number(char *col_strings)
{
	if (!col_strings)
	{
		return (0);
	}
	if (*col_strings == 45)
	{
		col_strings++;
	}
	while (*col_strings != '\0')
	{
		if (!isdigit(*col_strings))
		{
			return (0);
		}
		col_strings++;
	}
	return (1);
}
