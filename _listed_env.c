#include "shell.h"

/**
 * _listed_env - Function that lists the environ
 */
void _listed_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		_add_node_end(&env_s, environ[i]);
	}
}
