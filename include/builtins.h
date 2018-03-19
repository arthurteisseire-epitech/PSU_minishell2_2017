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

typedef struct builtins {
	char *name;
	int (*f)(char **args);
} builtins_t;

int cd(char **args);
int exec_builtins(char **args);

#endif
