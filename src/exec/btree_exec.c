/*
** EPITECH PROJECT, 2017
** File Name : btree_exec.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "btree.h"

static int go_left(btree_t *root, int pipefd[2])
{
	cmd_t *cmd_left = root->left->item;
	int status = EXIT_SUCCESS;

	if (cmd_left->exec != NULL)
		status = btree_exec(root->left, pipefd);
	return (status);
}

static int go_right(btree_t *root, int pipefd[2])
{
	cmd_t *cmd_right = root->right->item;
	int status = EXIT_SUCCESS;

	if (cmd_right->exec != NULL)
		status = btree_exec(root->right, pipefd);
	return (status);
}

int btree_exec(btree_t *root, int pipefd[2])
{
	cmd_t *this;
	int status = EXIT_SUCCESS;

	if (root->left != NULL)
		status = go_left(root, pipefd);
	if (status != EXIT_SUCCESS)
		return (status);
	this = root->item;
	if (this->exec != NULL)
		status = this->exec(root, pipefd);
	if (status != EXIT_SUCCESS)
		return (status);
	if (root->right != NULL)
		status = go_right(root, pipefd);
	return (status);
}
