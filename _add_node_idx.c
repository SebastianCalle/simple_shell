#include "shell.h"

node_t *_add_node_idx(node_t **head, char * str, int idx)
{
	node_t *temp = (*head), *new;

	if (head == NULL || (*head) == NULL || str == NULL || idx < 0)
		return (NULL);

	new = malloc(sizeof(node_t));
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
