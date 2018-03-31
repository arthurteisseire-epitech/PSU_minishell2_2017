/*
** EPITECH PROJECT, 2017
** File Name : exec_pipe.c
** File description:
** by Arthur Teisseire
*/

#include <unistd.h>
#include "mysh.h"
#include "my.h"

int execout_to_pipe(cmd_t *cmd, char **str)
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
		exec_cmd(str);
		my_puterror("Command not found.\n");
		return (1);
	} else {
		wait(NULL);
		close(cmd->pipefd[1]);
	}
	return (0);
}
