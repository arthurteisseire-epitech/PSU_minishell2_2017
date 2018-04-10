/*
** EPITECH PROJECT, 2017
** File Name : exec_pipe.c
** File description:
** by Arthur Teisseire
*/

#include <unistd.h>
#include "mysh.h"
#include "my.h"
#include "btree.h"
#include "builtins.h"

int exec_pipe(btree_t *root)
{
	cmd_t *this = root->item;
	cmd_t *cmd_left = root->left->item;
	cmd_t *cmd_right = root->right->item;

	cmd_left->pipefd[0] = this->pipefd[0];
	if (cmd_left->str != NULL)
		execout_to_pipe(cmd_left);
	cmd_right->pipefd[0] = cmd_left->pipefd[0];
	if (cmd_right->str != NULL)
		execout_to_pipe(cmd_right);
	return (cmd_right->pipefd[0]);
}

int execout_to_pipe(cmd_t *cmd)
{
	int child_pid;
	int oldread = cmd->pipefd[0];

	pipe(cmd->pipefd);
	child_pid = fork();
	if (child_pid == -1)
		return (-1);
	if (child_pid == 0) {
		dup2(oldread, 0);
		dup2(cmd->pipefd[1], 1);
		if (exec_builtins(cmd->str) != 1) {
			exec_cmd(cmd->str);
			my_puterror("Command not found.\n");
		}
		exit(0);
	} else {
		wait(NULL);
		close(cmd->pipefd[1]);
	}
	return (0);
}
