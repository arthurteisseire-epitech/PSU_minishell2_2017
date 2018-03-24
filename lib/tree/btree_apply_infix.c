/*
** EPITECH PROJECT, 2017
** File Name : btree_apply_infix.c
** File description:
** By Arthur Teisseire
*/

#include "btree.h"

void btree_apply_infix(btree_t *root, int (*applyf)(void *))
{
	if (root->left != NULL)
		btree_apply_infix(root->left, applyf);
	(*applyf)(root->item);
	if (root->right != NULL)
		btree_apply_infix(root->right, applyf);
}
