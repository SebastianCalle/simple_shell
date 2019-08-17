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

int _putchar(char c);
int _getchar(void);
char *_getline(void);

#endif
