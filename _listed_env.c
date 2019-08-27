#include "shell.h"

/**
 * _listed_env - create a linked list of enviroment
 * @env_s: env linked list
 */
void _listed_env(node_t **env_s)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		_add_node_end(env_s, environ[i]);
	}
}
