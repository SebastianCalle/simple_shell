#ifndef SHELL_H_
#define SHELL_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#define SIZE 1024

int _getchar(void);
int _getline(char **b, unsigned int n);

#endif
