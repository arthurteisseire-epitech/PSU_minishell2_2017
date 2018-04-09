/*
** EPITECH PROJECT, 2017
** File Name : semi_colons.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "btree.h"

static void write_output(cmd_t *cmd)
{
	if (cmd->str != NULL && my_strcmp(cmd->str, "") != 0)
		fork_and_exec(cmd->str);
	if (cmd->pipefd[0] != 0) 
		my_fdcpy(1, cmd->pipefd[0]);
}

int semi_colons(btree_t *root)
{
	cmd_t *this = root->item;

	if (root->left != NULL)
		write_output(root->left->item);
	if (root->right != NULL)
		write_output(root->right->item);
	this->pipefd[0] = 0;
	return (0);
}
