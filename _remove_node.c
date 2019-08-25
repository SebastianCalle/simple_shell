#include "shell.h"

/**
 * _remove_node - Function that removes a node in a linked list
 * @head: head of the linked list
 * @idx: index to be deleted
 * Return: 0 on Success and -1 otherwise
 */
int _remove_node(node_t **head, int idx)
{
	node_t *temp = (*head), *del;
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
