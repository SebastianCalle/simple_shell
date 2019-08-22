#include "shell.h"

void _free_list(env_l *head)
{
	env_l *ptr;

	while (head)
	{
		ptr = head;
		head = head->next;
		free(ptr->s);
		free(ptr);
	}
}
