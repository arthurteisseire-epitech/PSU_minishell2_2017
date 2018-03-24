/*
** EPITECH PROJECT, 2017
** File Name : btree_apply_prefix.c
** File description:
** By Arthur Teisseire
*/

#include "btree.h"

void btree_apply_prefix(btree_t *root, int (*applyf)(void *))
{
	(*applyf)(root->item);
	if (root->left != NULL)
		btree_apply_prefix(root->left, applyf);
	if (root->right != NULL)
		btree_apply_prefix(root->right, applyf);
}
