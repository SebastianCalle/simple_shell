#include "shell.h"

int _rem_node_inde(env_l **head, int ind)
{
        env_l *temp = (*head), *var;
	int i;

	if (ind == 0)
	{
		(*head) = (*head)->next;
		free(temp->s);
		free(temp);

		return(0);
	}
	for (i = 0; i < ind - 1; i++)
		temp = temp->next;

	

}
