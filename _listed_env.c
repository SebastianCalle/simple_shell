#include "shell.h"
/*
int main(void)
{
	int idx;
	environ_s = NULL;

	_listed_env();
	_print_list(environ_s);
	printf("-------------------------------------\n");
        idx = _find_node(&environ_s, "SESSION_MANAGER");
	printf("%d\n", idx);
	printf("-------------------------------------\n");
	_setenv("LC_NUMERIC", "HOLA HOLBERTON");
	_print_list(environ_s);
	_unsetenv("USERNAME");
	_print_list(environ_s);

        _free_list(environ_s);

	return (0);
}
*/
void _listed_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_add_node_end(&environ_s, environ[i]);
	}
}
