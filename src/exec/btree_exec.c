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

	if (root->left != NULL)
		status = btree_exec(root->left);
	if (root->right != NULL)
		status = btree_exec(root->right);
	if (status == 7) {
		status = this->exec(root);
		status = 0;
	}
	if (root->left == NULL && root->right == NULL)
		return (7);
	return (status);
}
