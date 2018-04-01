/*
** EPITECH PROJECT, 2017
** File Name : btree_apply_create.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"

void btree_apply_create(btree_t *root, int (*applyf)(btree_t *))
{
	if (root->left == NULL && root->right == NULL)
		(*applyf)(root);
	if (root->left != NULL)
		btree_apply_create(root->left, applyf);
	if (root->right != NULL)
		btree_apply_create(root->right, applyf);
}
