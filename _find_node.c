#include "shell.h"
/**
 * _find_node - search a node for name
 * @head: head node
 * @name: name of node to serch
 * Return: a j if is succes or -1 if not
 */
int _find_node(node_t **head, char *name)
{
	int i, sw, j;
	node_t *temp = NULL;

	if (name == NULL)
		return (-1);

	temp = (*head);

	for (sw = 0, j = 0; temp; sw = 0, j++)
	{
		if (temp->s[0] == name[0])
		{
			for (i = 0; temp->s[i] != '='; i++)
			{
				if (temp->s[i] != name[i])
				{
					sw = 1;
					break;
				}
			}
			if (sw == 0)
			{
				sw = 2;
				return (j);
			}
		}
		temp = temp->next;
	}

	return (-1);
}
