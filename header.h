#ifndef SHELL_H
#define SHELL_H
#define SIZE 1024
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>
extern char **environ;
typedef struct node
{
	char *s;
	struct node *next;
} node_t;
typedef struct core
{
	char *str;
	int (*f)(int argc, char **args, node_t **env_s);
} core_t;

node_t *_add_node_end(node_t **head, char *str);
int _print_list(int a, char **b, node_t **head);

#endif
