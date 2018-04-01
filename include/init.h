/*
** EPITECH PROJECT, 2017
** File Name : init.h
** File description:
** by Arthur Teisseire
*/

#ifndef INIT_H
#define INIT_H

typedef struct btree btree_t;
typedef struct cmd cmd_t;

cmd_t *new_cmd(char *str);
int init_tree(btree_t **root, char *str);
int fill_tree(btree_t *root);

#endif
