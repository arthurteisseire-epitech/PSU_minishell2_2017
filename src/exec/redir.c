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
	cmd_t *cmd_right = root->right->item;
	cmd_t *cmd_left = root->left->item;

	if (cmd_left->str != NULL)
		execout_to_pipe(cmd_left);
	write_in_file(cmd_right->str, cmd_left->pipefd[0], O_TRUNC);
	return (cmd_left->pipefd[0]);
}

int redir2_right(btree_t *root)
{
	cmd_t *cmd_right = root->right->item;
	cmd_t *cmd_left = root->left->item;

	if (cmd_left->str != NULL)
		execout_to_pipe(cmd_left);
	write_in_file(cmd_right->str, cmd_left->pipefd[0], O_APPEND);
	return (cmd_left->pipefd[0]);
}

int redir1_left(btree_t *root)
{
	cmd_t *cmd_left = root->left->item;
	cmd_t *cmd_right = root->right->item;
	int fd = open(cmd_right->str, O_RDONLY);

	if (fd < 0)
		return (fd);
	cmd_left->pipefd[0] = fd;
	execout_to_pipe(cmd_left);
	return (cmd_left->pipefd[0]);
}

int redir2_left(btree_t *root)
{
	cmd_t *cmd_right = root->right->item;
	cmd_t *cmd_left = root->left->item;
	char *line;
	char *res = NULL;

	my_putstr("? ");
	line = gnl(0);
	while (line != NULL && my_strcmp(line, cmd_right->str) != 0) {
		res = concat(res, line, my_strlen(line));
		res = concat(res, "\n", 1);
		free(line);
		my_putstr("? ");
		line = gnl(0);
	}
	pipe(cmd_left->pipefd);
	write(cmd_left->pipefd[1], res, my_strlen(res));
	close(cmd_left->pipefd[1]);
	execout_to_pipe(cmd_left);
	free(res);
	return (cmd_left->pipefd[0]);
}
