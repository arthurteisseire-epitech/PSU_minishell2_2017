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

#define NB_TOKENS 2
#define SEGFAULT 11
#define DIVZERO 8

typedef struct cmd {
	int pipefd[2];
	int (*exec)(char **left, char **right);
	char *str;
	char **array;
	char *sep;
} cmd_t;

typedef struct sh {
	int rvalue;
	char **cmd;
} sh_t;

extern char **environ;

int execout_to_pipe(cmd_t *cmd, char **str);
int exec_cmd(char **cmd);
int run(sh_t *sh);
int mysh(sh_t *sh);
int call_exit(char *cmd);
void my_perror(char *str);

#endif
