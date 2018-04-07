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
	cmd_t *cmd_right;
	cmd_t *cmd_left;

	if (root->left != NULL) {
		cmd_left = root->left->item;
		if (cmd_left->exec != NULL) {
			cmd_left->pipefd[0] = this->pipefd[0];
			this->pipefd[0] = btree_exec(root->left);
		}
	}
	this = root->item;
	if (this->exec != NULL)
		this->exec(root);
	if (root->right != NULL) {
		cmd_right = root->right->item;
		if (cmd_right->exec != NULL) {
			cmd_right->pipefd[0] = this->pipefd[0];
			this->pipefd[0] = btree_exec(root->right);
		}
	}
	return (this->pipefd[0]);
}
