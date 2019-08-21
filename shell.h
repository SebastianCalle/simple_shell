#ifndef SHELL_H
#define SHELL_H
#define SIZE 1024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
//typedef node_s
//	char *s;
//	struct node_s *next;
//} node_t;
void sh_loop(void);
char *read_line(void);
int count_letters(char *str, int *index, int *i);
int check_del(char c, char b);
int count_arg(char *str);
char **_strtok(char *buffer, int *j);
int execute(char **args);
int _getchar(void);
void _getline(char *buf);
char *lsh_read_line(void);
int _strcmp(char *s1, char *s2);
void check_case(char **args, char *line);
void _puts(char *str);
int _putchar(char c);
void signal_h(void);
void sig_catch(int sig);
#endif
