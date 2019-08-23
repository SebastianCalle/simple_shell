#include "shell.h"

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

void _listed_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_add_node_end(&environ_s, environ[i]);
	}
}

int _find_node(env_l **head, char *name)
{
	int i, sw, j;
	env_l *temp = NULL;

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


int _setenv(char *name, char *value)
{
	int idx;
	char *str, *s1 = name, *s2 = "=", *s3 = value;

	str = malloc(_strlen(name) + _strlen(value) + 2);
	if (str == NULL)
		return(-1);

	str[0] = '\0';

	str = _strcat(str, s1);
	str = _strcat(str, s2);
	str = _strcat(str, s3);

	if ((idx = _find_node(&environ_s, name)) != -1)
	{
		_remove_node(&environ_s, idx);
		_add_node_idx(&environ_s, str, idx);
	}
	else
		_add_node_end(&environ_s, str);

	free(str);

	return (0);
}

int _unsetenv(char *name)
{
	int idx;

	if ((idx = _find_node(&environ_s, name)) == -1 || name == NULL)
		return (-1);

	_remove_node(&environ_s, idx);

	return (0);
}
