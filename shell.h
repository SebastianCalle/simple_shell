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
#include <ctype.h>
//typedef node_s
//	char *s;
//	struct node_s *next;
//} node_t;
extern char **environ;
typedef struct node
{
	char *s;
	struct node *next;
} node_t;
node_t *environ_s;
extern node_t *environ_s;
node_t *path_s;
extern node_t *path_s;
int _isdigit(int c);
int _atoi(char *s);

char *_getenv(char *env);
int _strlen(char *s);
void *_memcpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _proexec(char **argv);
void sh_loop(void);
char *read_line(void);
int count_letters(char *str, int *index, int *i);
int check_del(char c, char b);
int count_arg(char *str);
char **_strtok(char *buffer, int *j);
int execute(char **args, char *line);
int _getchar(void);
int _getline(char **buf);
char *lsh_read_line(void);
int _strcmp(char *s1, char *s2);
int env(void);
void *_realloc(void *ptr, int size);
int printfile(char *filename);
void check_case(char **args, char *line);
void _puts(char *str);
int _putchar(char c);
void signal_h(void);
void sig_catch(int sig);
node_t *_add_node_end(node_t **head, char *str);
void _free_list(node_t *head);
int _print_list(node_t *head);
void _listed_env(void);
int _find_node(node_t **head, char *name);
int _setenv(char *name, char *value);
int _remove_node(node_t **head, int idx);
node_t *_add_node_idx(node_t **head, char * str, int idx);
int _unsetenv(char *name);

#endif
