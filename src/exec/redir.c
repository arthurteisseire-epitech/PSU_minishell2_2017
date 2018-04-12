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
	cmd_t *this = root->item;
	cmd_t *cmd_right = root->right->item;
	cmd_t *cmd_left = root->left->item;
	int status = 0;

	if (cmd_left->str != NULL)
		status = execout_to_pipe(cmd_left);
	write_in_file(cmd_right->str, cmd_left->pipefd[0], O_TRUNC);
	this->pipefd[0] = cmd_left->pipefd[0];
	return (status);
}

int redir2_right(btree_t *root)
{
	cmd_t *this = root->item;
	cmd_t *cmd_right = root->right->item;
	cmd_t *cmd_left = root->left->item;
	int status = 0;

	if (cmd_left->str != NULL)
		status = execout_to_pipe(cmd_left);
	write_in_file(cmd_right->str, cmd_left->pipefd[0], O_APPEND);
	this->pipefd[0] = cmd_left->pipefd[0];
	return (status);
}

int redir1_left(btree_t *root)
{
	cmd_t *this = root->item;
	cmd_t *cmd_left = root->left->item;
	cmd_t *cmd_right = root->right->item;
	int fd = open(cmd_right->str, O_RDONLY);
	int status = 0;

	if (fd < 0) {
		my_perror(cmd_right->str);
		return (1);
	}
	cmd_left->pipefd[0] = fd;
	status = execout_to_pipe(cmd_left);
	this->pipefd[0] = cmd_left->pipefd[0];
	return (status);
}

int redir2_left(btree_t *root)
{
	cmd_t *this = root->item;
	cmd_t *cmd_right = root->right->item;
	cmd_t *cmd_left = root->left->item;
	char *line;
	char *res = NULL;
	int status = 0;

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
	status = execout_to_pipe(cmd_left);
	free(res);
	this->pipefd[0] = cmd_left->pipefd[0];
	return (status);
}
