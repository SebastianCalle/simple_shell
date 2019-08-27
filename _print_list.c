#include "shell.h"

/**
 * _print_list - function  that print list
 * @argc: Number of arguments
 * @l: input line
 * @args: Multidimensional array of arguments
 * @head: Head of the linked list
 * Return: the number of nodes
 */
int _print_list(UN int argc, UN char *l, UN char **args, node_t **head)
{
	int i;
	node_t *temp = *head;

	if (temp == NULL)
		return (-1);

	for (i = 0; temp; i++)
	{
		_puts((temp)->s);
		_putchar(10);
		temp = (temp)->next;
	}

	return (i);
}
