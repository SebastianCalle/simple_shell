#include "shell.h"


void sh_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = _getline();
    args = _strtok(line);
    status = lsh_launch(args);

    free(args);
  } while (status);
}
