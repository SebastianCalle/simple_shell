#include "shell.h"

env_l *_add_node_idx(env_l **head, char * str, int idx)
{
	env_l *temp = (*head), *new;

	if (head == NULL || (*head) == NULL || str == NULL || idx < 0)
		return (NULL);

	new = malloc(sizeof(env_l));
	if (new == NULL)
		return(NULL);

	new->s = _strdup(str);
	new->next = NULL;

	if (idx == 0)
	{
		new->next = (*head);
		(*head) = new;
		return (*head);
	}

        for (;temp && idx > 1; idx--)
		temp = temp->next;

	new->next = temp->next;
	temp->next = new;

	return (new);
}
