/*
** EPITECH PROJECT, 2017
** File Name : run.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "builtins.h"

static void handle_status(sh_t *sh, int wstatus)
{
	if (WIFEXITED(wstatus)) {
		sh->rvalue = WEXITSTATUS(wstatus);
		printf("rvalue %d\n", sh->rvalue);
	}
	if (WCOREDUMP(wstatus) && WTERMSIG(wstatus) == SEGFAULT)
		my_putstr("Segmentation fault\n");
	else if (!WCOREDUMP(wstatus) && WTERMSIG(wstatus) == SEGFAULT)
		my_putstr("Segmentation fault\n");
	if (WCOREDUMP(wstatus) && WTERMSIG(wstatus) == DIVZERO)
		my_putstr("Floating exception\n");
	else if (!WCOREDUMP(wstatus) && WTERMSIG(wstatus) == DIVZERO)
		my_putstr("Floating exception\n");
}

static int fork_and_exec(sh_t *sh)
{
	pid_t child_pid;
	int wstatus;

	if (!exec_builtins(sh)) {
		child_pid = fork();
		if (child_pid == 0) {
			return (exec_cmd(sh));
		} else if (child_pid > 0) {
			wait(&wstatus);
			handle_status(sh, wstatus);
		} else
			return (-1);
	}
	return (2);
}

int run(sh_t *sh)
{
	char *cmd = NULL;
	int status = 0;

	while (1) {
		my_putstr("$> ");
		free(cmd);
		cmd = get_next_line(0);
		if (call_exit(cmd))
			return (sh->rvalue);
		sh->args = split(cmd, " \t");
		status = fork_and_exec(sh);
		free_array(sh->args);
		if (status != 2) {
			sh->rvalue = status;
			return (status);
		}
	}
}

int call_exit(char *cmd)
{
	if (cmd == NULL) {
		my_putstr("exit\n");
		return (1);
	}
	if (my_strcmp(cmd, "exit") == 0) {
		my_putstr("exit\n");
		free(cmd);
		return (1);
	}
	return (0);
}
