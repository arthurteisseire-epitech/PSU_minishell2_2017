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
int btree_init(btree_t **root, char *str);
int btree_fill(btree_t *root);
btree_t *btree_new_node(cmd_t *cmd, int index, char *(get)());

#endif
