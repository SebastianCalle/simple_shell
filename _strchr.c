#include "shell.h"

char *_strchr(char *s, char c)
{
        while (*s++ != c)
		if (*s == '\0')
			return (NULL);

	return (s);
}
