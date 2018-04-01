/*
** EPITECH PROJECT, 2017
** File Name : btree_apply_create.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"

int btree_apply_last(btree_t *root, int (*applyf)(btree_t *))
{
	int status = 0;

	if (root->left == NULL && root->right == NULL)
		status = (*applyf)(root);
	if (status == -1)
		return (-1);
	if (root->left != NULL)
		status = btree_apply_last(root->left, applyf);
	if (status == -1)
		return (-1);
	if (root->right != NULL)
		status = btree_apply_last(root->right, applyf);
	return (status);
}
