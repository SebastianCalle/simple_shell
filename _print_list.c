#include "shell.h"

int _print_list(env_l *head)
{
	int i;

	for (i = 0; head; i++)
	{
		printf("%s\n", head->s);
		head = head->next;
	}

	return (i);
}
