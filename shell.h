#ifndef SHELL_H
#define SHELL_H
#define SIZE 1024
#include <stdio.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
//typedef node_s
//	char *s;
//	struct node_s *next;
//} node_t;
void sh_loop(void);
int count_letters(char *str, int *index, int *i);
int check_del(char c, char b);
int count_arg(char *str);
char **_strtok(char *buffer, int *j);
int execute(char **args);
int _getchar(void);
char *_getline(int *fl);
char *lsh_read_line(void);
#endif
