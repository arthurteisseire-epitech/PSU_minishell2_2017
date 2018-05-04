/*
** EPITECH PROJECT, 2017
** File Name : semi_colons.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "btree.h"

static void write_output(cmd_t *cmd, int pipefd[2])
{
	if (cmd->str != NULL && my_strcmp(cmd->str, "") != 0)
		fork_and_exec(cmd->str);
	if (pipefd[0] != 0)
		my_fdcpy(1, pipefd[0]);
}

int semi_colons(btree_t *root, int pipefd[2])
{
	if (root->left != NULL)
		write_output(root->left->item, pipefd);
	if (root->right != NULL)
		write_output(root->right->item, pipefd);
	pipefd[0] = 0;
	return (EXIT_SUCCESS);
}
