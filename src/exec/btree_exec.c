/*
** EPITECH PROJECT, 2017
** File Name : btree_exec.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "btree.h"

static void go_left(btree_t *root)
{
	cmd_t *this = root->item;
	cmd_t *cmd_left = root->left->item;

	if (cmd_left->exec != NULL) {
		cmd_left->pipefd[0] = this->pipefd[0];
		this->pipefd[0] = btree_exec(root->left);
	}
}

static void go_right(btree_t *root)
{
	cmd_t *this = root->item;
	cmd_t *cmd_right = root->right->item;

	if (cmd_right->exec != NULL) {
		cmd_right->pipefd[0] = this->pipefd[0];
		this->pipefd[0] = btree_exec(root->right);
	}
}

int btree_exec(btree_t *root)
{
	cmd_t *this;

	if (root->left != NULL)
		go_left(root);
	this = root->item;
	if (this->exec != NULL)
		this->pipefd[0] = this->exec(root);
	if (root->right != NULL)
		go_right(root);
	return (this->pipefd[0]);
}
