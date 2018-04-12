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
	int status = 0;

	cmd_left->pipefd[0] = this->pipefd[0];
	if (cmd_left->str != NULL)
		status = execout_to_pipe(cmd_left);
	if (status != 0)
		return (status);
	cmd_right->pipefd[0] = cmd_left->pipefd[0];
	if (cmd_right->str != NULL)
		status = execout_to_pipe(cmd_right);
	this->pipefd[0] = cmd_right->pipefd[0];
	return (status);
}

int execout_to_pipe(cmd_t *cmd)
{
	int child_pid;
	int oldread = cmd->pipefd[0];
	int status = 0;
	int wstatus;

	pipe(cmd->pipefd);
	child_pid = fork();
	if (child_pid == -1)
		return (ERROR);
	if (child_pid == 0) {
		dup2(oldread, 0);
		dup2(cmd->pipefd[1], 1);
		status = exec_builtins(cmd->str);
		if (status != 0) {
			exec_cmd(cmd->str);
			my_puterror("Command not found.\n");
		}
		exit(status);
	} else {
		wait(&wstatus);
		status = handle_status(wstatus);
		if (my_strncmp(cmd->str, "exit", 4) == 0) {
			my_putstr("exit\n");
			exit(status);
		}
		close(cmd->pipefd[1]);
	}
	return (status);
}
