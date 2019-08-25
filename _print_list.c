#include "shell.h"

/**
 * _print_list - Function that prints a linked list
 * @head: head of linked list
 * Return: The length of linked list on success or -1 if it fails
 */
int _print_list(node_t *head)
{
	int i;

	if (head == NULL)
		return (-1);

	for (i = 0; head; i++)
	{
		_puts(head->s);
		_putchar(10);
		head = head->next;
	}

	return (i);
}
