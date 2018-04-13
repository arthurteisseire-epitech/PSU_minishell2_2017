/*
** EPITECH PROJECT, 2017
** File Name : dict.h
** File description:
** by Arthur Teisseire
*/

#ifndef DICT_H
#define DICT_H

#define NB_SEP 6

typedef struct btree btree_t;
typedef int (*cmd_f)();

typedef struct dicf {
	char *str;
	int (*f)(btree_t *, int pipefd[2]);
	unsigned char byte;
} dicf_t;

extern const dicf_t sep[NB_SEP];

int parse_null(btree_t *root);
int parse_ambigous(char *str);

#endif
