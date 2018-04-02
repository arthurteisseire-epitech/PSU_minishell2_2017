/*
** EPITECH PROJECT, 2017
** File Name : btree_exec.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "btree.h"

int btree_exec(btree_t *root)
{
	cmd_t *this = root->item;
	int status = 0;

	if (root->right != NULL)
		btree_exec(root->right);
	if (root->left != NULL)
		btree_exec(root->left);
	if (root->left == NULL && root->right == NULL)
		return (0);
	if (root->left->left == NULL && root->left->right == NULL
	&& root->right->left == NULL && root->right->right == NULL)
		status = this->exec(root);
	return (status);
}
