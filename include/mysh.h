/*
** EPITECH PROJECT, 2017
** File Name : mysh.h
** File description:
** by Arthur Teisseire
*/

#ifndef MY_EXEC_H
#define MY_EXEC_H

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <dirent.h>

#define SEGFAULT 11
#define DIVZERO 8

typedef struct btree btree_t;

typedef struct cmd {
	int (*exec)(btree_t *root, int pipefd[2]);
	char *str;
} cmd_t;

extern char **environ;

int exec(char *cmd, int pipefd[2]);
int semi_colons(btree_t *root, int pipefd[2]);
int exec_pipe(btree_t *root, int pipefd[2]);
int execout_to_pipe(cmd_t *cmd, int pipefd[2]);
int parent(char *str);
int redir2_right(btree_t *root, int pipefd[2]);
int redir1_right(btree_t *root, int pipefd[2]);
int redir2_left(btree_t *root, int pipefd[2]);
int redir1_left(btree_t *root, int pipefd[2]);
int btree_exec(btree_t *root, int pipefd[2]);
int exec_cmd(char *cmd);
int fork_and_exec(char *cmd);
int run(void);
int call_exit(char *cmd);
void my_perror(char *str);
int handle_status(int wstatus);
int node_destroy(void *ptr);
int get_index(char *str);
void print_prompt(void);

#endif
