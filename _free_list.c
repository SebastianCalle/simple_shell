#include "shell.h"

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
