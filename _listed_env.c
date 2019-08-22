#include "shell.h"

int main(void)
{
        env_l *environ_s = NULL;
	env_l *node;

        _listed_env(&environ_s);
	_print_list(environ_s);
	printf("-------------------------------------\n");
	node = _findenv(&environ_s, "LC_NUMERIC");
	printf("%s\n", node->s);
        _free_list(environ_s);

	return (0);
}

void _listed_env(env_l **head)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_add_node_end(head, environ[i]);
	}
}

env_l *_findenv(env_l **head, char *name)
{
	int i, sw;
	env_l *temp = NULL;

	if (name == NULL)
		return (NULL);

	temp = (*head);

        for (sw = 0; temp; sw = 0)
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
				break;
			}
		}
		temp = temp->next;
	}

	return (temp);
}
/*
int _setenv(char *name, char *value, int overwrite)
{
	
}
*/
