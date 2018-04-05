/*
** EPITECH PROJECT, 2017
** File Name : dict.h
** File description:
** by Arthur Teisseire
*/

#ifndef DICT_H
#define DICT_H

typedef struct btree btree_t;
typedef int (*cmd_f)();

typedef struct dicf {
	char *str;
	int (*f)(btree_t *);
} dicf_t;

#endif
