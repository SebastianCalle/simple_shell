#include "shell.h"
/*
int main(void)
{
	char *a;

	_add_node_end(&env_s, "HOLA=HUGO");
	a = _getenv("HOLA");
	printf("%s\n", a);

	return (0);
	}*/
/*
 * _getenv - Function that finds an enviroment variable in our env
 * @env: String to be searched
 * Return: An string if it finds or NULL otherwise
 */
char *_getenv(char *env)
{
	char *buff;
	int i, j, k = 0;
	node_t *temp = env_s;

	while (temp)
	{
		if (temp->s[0] == env[0])
		{
			for (i = 0; temp->s[i] != '='; i++)
			{
				if (temp->s[i] != env[i])
					break;
				if (temp->s[i + 1] == '=')
					k = 1;
			}
		}
		i++;
		if (k == 1)
			break;
		else if (temp->next == NULL)
			return (NULL);
	        temp = temp->next;
	}

	if (k != 1)
		return (NULL);

	for (j = i; temp->s[i]; i++)
		;

	buff = malloc(sizeof(char) * (i + 1));
	if (buff == NULL)
		return (NULL);

	for (k = 0; j <= i; j++, k++)
		buff[k] = temp->s[j];

	return (buff);
}
