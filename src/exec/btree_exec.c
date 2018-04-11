/*
** EPITECH PROJECT, 2017
** File Name : btree_exec.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "btree.h"

static int go_left(btree_t *root)
{
	cmd_t *this = root->item;
	cmd_t *cmd_left = root->left->item;
	int status = 0;

	if (cmd_left->exec != NULL) {
		cmd_left->pipefd[0] = this->pipefd[0];
		status = btree_exec(root->left);
	}
	return (status);
}

static int go_right(btree_t *root)
{
	cmd_t *this = root->item;
	cmd_t *cmd_right = root->right->item;
	int status = 0;

	if (cmd_right->exec != NULL) {
		cmd_right->pipefd[0] = this->pipefd[0];
		status = btree_exec(root->right);
	}
	return (status);
}

int btree_exec(btree_t *root)
{
	cmd_t *this;
	int status = 0;

	if (root->left != NULL)
		status = go_left(root);
	if (status != 0)
		return (status);
	this = root->item;
	if (this->exec != NULL)
		status = this->exec(root);
	if (status != 0)
		return (status);
	if (root->right != NULL)
		status = go_right(root);
	return (status);
}
