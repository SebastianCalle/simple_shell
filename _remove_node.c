#include "shell.h"

int _remove_node(env_l **head, int idx)
{
	env_l *temp = (*head), *del;
	int i;

	if (head == NULL || (*head) == NULL || idx < 0)
		return (-1);

	if (idx == 0)
	{
		(*head) = (*head)->next;
		free(temp->s);
		free(temp);

		return (0);
	}

	for (i = 0; i < idx - 1; i++)
		temp = temp->next;

	del = temp->next;
	temp->next = temp->next->next;
	free(del->s);
	free(del);

	return (0);
}
