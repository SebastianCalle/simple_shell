#include "shell.h"

int main(void)
{
	env_l *head = NULL;
        //_listed_env(&head);
	int i;

	for (i = 0; environ[i]; i++)
	{
		_add_node_end(&head, environ[i]);
	}

	_print_list(head);
        _free_list(head);

	return (0);
}

/*void *_listed_env(env_l **head)
{
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		_add_node_end(&head, environ[i]);
	}
}
*/
