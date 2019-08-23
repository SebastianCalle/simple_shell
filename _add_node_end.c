#include "shell.h"

node_t *_add_node_end(node_t **head, char *str)
{
	node_t *new = NULL;
        node_t *last = NULL;

	new = malloc(sizeof(node_t));
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
