/*
** EPITECH PROJECT, 2017
** File Name : btree_free.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"

static int freef(btree_t *root)
{
	free(root);
	return (0);
}

void btree_free(btree_t *root, int (*free_func)(void *))
{
	if (free_func != NULL)
		btree_apply_suffix(root, free_func);
	btree_apply_nodes(root, freef);
}
