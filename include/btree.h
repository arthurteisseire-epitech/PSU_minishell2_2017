/*
** EPITECH PROJECT, 2017
** File Name : btree.h
** File description:
** By Arthur Teisseire
*/

#ifndef BTREE_H
#define BTREE_H

#include <stdlib.h>

typedef struct btree {
	struct btree *left;
	struct btree *right;
	void *item;
} btree_t;

btree_t *btree_create_node(void *item);
void btree_apply_prefix(btree_t *root, int (*applyf)(void *));
void btree_apply_infix(btree_t *root, int (*applyf)(void *));
void btree_apply_suffix(btree_t *root, int (*applyf)(void *));
void btree_insert_data(btree_t *root, void *item, int (*cmpf)());
void btree_disp(btree_t *root, void (*dispf)(void *));
void *btree_search_item(btree_t const *root, void const *item, int (*cmpf)());
int btree_level_count(btree_t const *root);
int btree_node_count(btree_t const *root);

#endif
