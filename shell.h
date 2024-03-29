#ifndef SHELL_H
#define SHELL_H
#define SIZE 15024
#define UN __attribute__((__unused__))
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>
extern char **environ;

/**
 * struct node - Node of the linked list
 * @s: String of the struct
 * @next: Next node
 */
typedef struct node
{
	char *s;
	struct node *next;
} node_t;
/**
 * struct core - Core of the linked list
 * @str: String of the struct
 * @f: Function of the struct
 */
typedef struct core
{
	char *str;
	int (*f)(int argc, char *l, char **args, node_t **env_s);
} core_t;

int _isdigit(int c);
int _atoi(char *s);
int _strlen(char *s);
void *_memcpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _proexec(char **argv, char *line, node_t **env_s, node_t **path_s);
void sh_loop(void);
char *read_line(int *flag, node_t *env_s, node_t *path_s);
int count_letters(char *str, int *index, int *i);
int check_del(char c, char b);
int count_arg(char *str);
char **_strtok(char *buffer, int *j);
int execute(char **args, char *line, node_t **env_s, node_t **path_s);
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
char *_getenviron(char *env);
char *_getenv(char *env, node_t **env_s);
node_t *_add_node_end(node_t **head, char *str);
void _free_list(node_t *head);
int _print_list(int argc, char *l, char **args, node_t **head);
void _listed_env(node_t **env_s);
int _find_node(node_t **head, char *name);
int _setenv(int argc, UN char *l, char **args, node_t **env_s);
int _setenv1(char *name, char *value, node_t **env_s);
int _remove_node(node_t **head, int idx);
node_t *_add_node_idx(node_t **head, char *str, int idx);
int _unsetenv(int argc, UN char *l, char **args, node_t **env_s);
int _cd(int argc, UN char *l, char **args, node_t **env_s);
int _exit_shell(char *line, char **args, int *stats);
int no_found(UN int argc, UN char *l, UN char **args, UN node_t **env_s);
void free_all2(char **args, char *line);
int _pwd(UN int argc, UN char *l, UN char **args, node_t **env_s);
void *_calloc(unsigned int nmemb, unsigned int size);

#endif
