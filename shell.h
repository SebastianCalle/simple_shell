#ifndef SHELL_H
#define SHELL_H
#define SIZE 1024
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
//typedef node_s
//	char *s;
//	struct node_s *next;
//} node_t;
extern char **environ;

char *_getenv(char *env);
int _strlen(char *s);
void _strcpy(char **s1, char *s2, int n);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _proexec(char **argv);
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
