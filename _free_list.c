#include "shell.h"
/**
 * _free_list - function that free the nodes
 * @head: nodes to free
 */
void _free_list(node_t *head)
{
	node_t *ptr;

	while (head)
	{
		ptr = head;
		head = head->next;
		free(ptr->s);
		free(ptr);
	}
}
