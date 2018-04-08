/*
** EPITECH PROJECT, 2017
** File Name : right_redir.c
** File description:
** by Arthur Teisseire
*/

#include <fcntl.h>
#include "btree.h"
#include "my.h"
#include "mysh.h"

int redir1_right(btree_t *root)
{
	cmd_t *cmd = root->item;
	cmd_t *cmd_right = root->right->item;
	cmd_t *cmd_left = root->left->item;

	if (cmd_left->str != NULL)
		execout_to_pipe(cmd_left);
	cmd->pipefd[0] = cmd_left->pipefd[0];
	write_in_file(cmd_right->str, cmd->pipefd[0], O_TRUNC);
	return (0);
}

int redir2_right(btree_t *root)
{
	cmd_t *cmd = root->item;
	cmd_t *cmd_right = root->right->item;
	cmd_t *cmd_left = root->left->item;

	if (cmd_left->str != NULL)
		execout_to_pipe(cmd_left);
	cmd->pipefd[0] = cmd_left->pipefd[0];
	write_in_file(cmd_right->str, cmd->pipefd[0], O_APPEND);
	return (0);
}

int redir1_left(btree_t *root)
{
	cmd_t *cmd = root->item;
	cmd_t *cmd_right = root->right->item;
	int fd = open(cmd_right->str, O_RDONLY);

	if (fd < 0)
		return (fd);
	my_fdcpy(cmd->pipefd[1], fd);
	execout_to_pipe(root->item);
	return (0);
}
