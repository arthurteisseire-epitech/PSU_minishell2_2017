/*
** EPITECH PROJECT, 2017
** File Name : btree_apply_nodes.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"

int btree_apply_nodes(btree_t *root, int (*applyf)(btree_t *))
{
	int status = 0;
	
	if (root->left != NULL)
		status = btree_apply_nodes(root->left, applyf);
	if (status != 0)
		return (status);
	if (root->right != NULL)
		status = btree_apply_nodes(root->right, applyf);
	if (status != 0)
		return (status);
	status = (*applyf)(root);
	return (status);
}
