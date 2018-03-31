/*
** EPITECH PROJECT, 2017
** File Name : builtins.h
** File description:
** by Arthur Teisseire
*/

#ifndef BUILTINS_H
#define BUILTINS_H

#include <fcntl.h>

#define NB_BUILTINS 4

typedef struct sh sh_t;

typedef struct builtins {
	char *name;
	int (*f)(char **args);
} builtins_t;

int exec_builtins(sh_t *sh);
int cd(char **args);
int my_setenv(char **args);
int my_unsetenv(char **args);
int my_env(char **args);
int add_var(char **args);

#endif
