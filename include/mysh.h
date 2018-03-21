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

typedef struct sh {
	int rvalue;
	char **args;
} sh_t;

extern char **environ;

int exec_cmd(sh_t *sh);
int run(sh_t *sh);
int mysh(sh_t *sh);
int call_exit(char *cmd);
void skip_name(char **var);
char *get_value(char *var);

#endif
