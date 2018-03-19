/*
** EPITECH PROJECT, 2017
** File Name : run.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "builtins.h"

static int handle_status(int wstatus)
{
	if (!WIFSIGNALED(wstatus))
		return (0);
	if (WCOREDUMP(wstatus) && WTERMSIG(wstatus) == SEGFAULT)
		my_putstr("Segmentation fault\n");
	else if (!WCOREDUMP(wstatus) && WTERMSIG(wstatus) == SEGFAULT)
		my_putstr("Segmentation fault\n");
	if (WCOREDUMP(wstatus) && WTERMSIG(wstatus) == DIVZERO)
		my_putstr("Floating exception\n");
	else if (!WCOREDUMP(wstatus) && WTERMSIG(wstatus) == DIVZERO)
		my_putstr("Floating exception\n");
	return (1);
}

static int fork_and_exec(char **args, char *cmd)
{
	pid_t child_pid;
	int wstatus;

	if (!exec_builtins(args)) {
		child_pid = fork();
		if (child_pid == 0) {
			exec_cmd(cmd, args);
			return (1);
		} else if (child_pid > 0) {
			wait(&wstatus);
		} else
			return (-1);
		return (handle_status(wstatus));
	}
	return (0);
}

int run(void)
{
	char *cmd = NULL;
	char **args;
	int status = 0;

	while (1) {
		my_putstr("$> ");
		free(cmd);
		cmd = get_next_line(0);
		if (want_exit(cmd))
			return (status);
		args = split(cmd, " \t");
		status = fork_and_exec(args, cmd);
		free_array(args);
		if (status != 0)
			return (status);
	}
}

int want_exit(char *cmd)
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
