/*
** EPITECH PROJECT, 2017
** File Name : exec_pipe.c
** File description:
** by Arthur Teisseire
*/

#include <unistd.h>
#include "mysh.h"
#include "my.h"

int store_pipe(cmd_t *cmd, char **str)
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
		execve(str[0], str, environ);
		my_puterror("Command not found.\n");
		return (1);
	} else {
		wait(NULL);
		close(cmd->pipefd[1]);
	}
	return (0);
}
/*
 *
 *int main(void)
 *{
 *        cmd_t cmd;
 *        char *str_left[] = {"/bin/ls", "-l", NULL};
 *        char *str_right[] = {"/bin/grep", "a", NULL};
 *        char *str_end[] = {"/bin/cat", "-e", NULL};
 *        char buff[1];
 *
 *        cmd.pipefd[0] = 0;
 *        cmd.pipefd[1] = 1;
 *        exec_pipe(&cmd, str_left);
 *        exec_pipe(&cmd, str_right);
 *        exec_pipe(&cmd, str_end);
 *        while (read(cmd.pipefd[0], buff, 1) != 0)
 *                write(1, buff, 1);
 *        close(cmd.pipefd[0]);
 *        return (0);
 *}
 */
