#include "shell.h"

env_l *_add_node_end(env_l **head, char *str)
{
	env_l *new = NULL;
	env_l *last = NULL;

	new = malloc(sizeof(env_l));
	if (new == NULL)
		return (NULL);

	new->s = _strdup(str);
	new->next = NULL;

	last = (*head);

	if (*head)
	{
		while (last->next)
			last = last->next;

		last->next = new;
	}
	else
		(*head) = new;

	return (new);
}
