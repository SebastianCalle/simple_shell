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

	while (env_s)
	{
		if (env_s->s[0] == env[0])
		{
			for (i = 0; env_s->s[i] != '='; i++)
			{
				if (env_s->s[i] != env[i])
					break;
				if (env_s->s[i + 1] == '=')
					k = 1;
			}
		}
		i++;
		if (k == 1)
			break;
		else if (env_s->next == NULL)
			return (NULL);
	}

	for (j = i; env_s->s[i]; i++)
		;

	buff = malloc(sizeof(char) * (i + 1));
	if (buff == NULL)
		return (NULL);

	for (k = 0; j <= i; j++, k++)
		buff[k] = env_s->s[j];

	return (buff);
}
