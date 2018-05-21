/*
** EPITECH PROJECT, 2017
** File Name : run.c
** File description:
** by Arthur Teisseire
*/

#include <sys/wait.h>
#include <sys/types.h>
#include "my.h"
#include "mysh.h"
#include "builtins.h"

int handle_status(int wstatus)
{
	if (WTERMSIG(wstatus) == SEGFAULT) {
		my_putstr("Segmentation fault\n");
		return (139);
	}
	if (WTERMSIG(wstatus) == DIVZERO) {
		my_putstr("Floating exception\n");
		return (136);
	}
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	return (EXIT_SUCCESS);
}

int fork_and_exec(char *cmd)
{
	pid_t child_pid;
	int wstatus;
	int status = exec_builtins(cmd);

	if (status == 2) {
		child_pid = fork();
		if (child_pid < 0)
			return (EXIT_FAILURE);
		if (child_pid == 0) {
			exit(exec_cmd(cmd));
		} else {
			wait(&wstatus);
			return (handle_status(wstatus));
		}
	}
	return (status);
}

int run(void)
{
	int pipefd[2];
	int status = EXIT_SUCCESS;

	print_prompt();
	for (char *line = gnl(0); !call_exit(line); line = gnl(0)) {
		pipefd[0] = 0;
		pipefd[1] = 0;
		status = exec(line, pipefd);
		free(line);
		print_prompt();
	}
	return (status);
}

int call_exit(char *line)
{
	if (line == NULL) {
		my_putstr("exit\n");
		free(line);
		return (1);
	}
	return (0);
}
