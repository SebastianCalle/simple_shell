#include "shell.h"

int _print_list(node_t *head)
{
	int i;

	for (i = 0; head; i++)
	{
		printf("%s\n", head->s);
		head = head->next;
	}

	return (i);
}
