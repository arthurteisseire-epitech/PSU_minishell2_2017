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

int exec_pipe(btree_t *root, int pipefd[2])
{
	cmd_t *cmd_left = root->left->item;
	cmd_t *cmd_right = root->right->item;
	int status = EXIT_SUCCESS;

	if (cmd_left->str != NULL)
		status = execout_to_pipe(cmd_left, pipefd);
	if (status != EXIT_SUCCESS)
		return (status);
	if (cmd_right->str != NULL)
		status = execout_to_pipe(cmd_right, pipefd);
	return (status);
}

int execout_to_pipe(cmd_t *cmd, int pipefd[2])
{
	int child_pid;
	int oldread = pipefd[0];
	int status = EXIT_SUCCESS;

	pipe(pipefd);
	child_pid = fork();
	if (child_pid == -1)
		return (EXIT_FAILURE);
	if (child_pid == 0) {
		dup2(oldread, 0);
		dup2(pipefd[1], 1);
		status = exec_builtins(cmd->str);
		if (status != 0)
			status = exec_cmd(cmd->str);
		exit(status);
	}
	status = parent(cmd->str);
	close(pipefd[1]);
	return (status);
}

int parent(char *str)
{
	int wstatus;
	int status;

	wait(&wstatus);
	status = handle_status(wstatus);
	if (my_strncmp(str, "exit", 4) == 0) {
		my_putstr("exit\n");
		exit(status);
	}
	return (status);
}
