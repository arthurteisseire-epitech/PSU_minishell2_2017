/*
** EPITECH PROJECT, 2017
** File Name : btree_apply_nodes.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"

void btree_apply_nodes(btree_t *root, int (*applyf)(void *))
{
	if (root->left != NULL)
		btree_apply_nodes(root->left, applyf);
	if (root->right != NULL)
		btree_apply_nodes(root->right, applyf);
	(*applyf)(root);
}
