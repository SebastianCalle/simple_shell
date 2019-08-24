#include "shell.h"
/**
 * _print_list - function  that print list
 * @head: node to print
 * Return: the number of nodes
 */
int _print_list(node_t *head)
{
	int i;

	for (i = 0; head; i++)
	{
		_puts(head->s);
		_putchar(10);
		head = head->next;
	}

	return (i);
}
