#include "shell.h"
/**
 * _listed_env - create a linked list of enviroment
 */
void _listed_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		_add_node_end(&environ_s, environ[i]);
	}
}
