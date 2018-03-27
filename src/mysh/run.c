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

static void handle_status(sh_t *sh, int wstatus)
{
	if (WIFEXITED(wstatus))
		sh->rvalue = WEXITSTATUS(wstatus);
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
			return (exec_cmd(sh->cmd));
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
	char *line = NULL;
	int status = 0;

	while (1) {
		my_putstr("$> ");
		free(line);
		line = get_next_line(0);
		if (call_exit(line))
			return (sh->rvalue);
		sh->cmd = split(line, " \t");
		status = fork_and_exec(sh);
		free_array(sh->cmd);
		if (status != 2) {
			sh->rvalue = status;
			return (status);
		}
	}
}

int call_exit(char *line)
{
	if (line == NULL) {
		my_putstr("exit\n");
		return (1);
	}
	if (my_strcmp(line, "exit") == 0) {
		my_putstr("exit\n");
		free(line);
		return (1);
	}
	return (0);
}
