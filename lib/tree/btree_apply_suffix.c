/*
** EPITECH PROJECT, 2017
** File Name : btree_apply_suffix.c
** File description:
** By Arthur Teisseire
*/

#include "btree.h"

void btree_apply_suffix(btree_t *root, int (*applyf)(void *))
{
	if (root->left != NULL)
		btree_apply_suffix(root->left, applyf);
	if (root->right != NULL)
		btree_apply_suffix(root->right, applyf);
	(*applyf)(root->item);
}
