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
#ifdef WCOREDUMP
	if (WCOREDUMP(wstatus) && WTERMSIG(wstatus) == SEGFAULT)
		my_putstr("Segmentation fault\n");
	else if (!WCOREDUMP(wstatus) && WTERMSIG(wstatus) == SEGFAULT)
		my_putstr("Segmentation fault\n");
	if (WCOREDUMP(wstatus) && WTERMSIG(wstatus) == DIVZERO)
		my_putstr("Floating exception\n");
	else if (!WCOREDUMP(wstatus) && WTERMSIG(wstatus) == DIVZERO)
		my_putstr("Floating exception\n");
#endif
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	return (0);
}

int fork_and_exec(char *cmd)
{
	pid_t child_pid;
	int wstatus;
	int status = exec_builtins(cmd);

	if (status == 2) {
		child_pid = fork();
		if (child_pid == 0) {
			exit(exec_cmd(cmd));
		} else if (child_pid > 0) {
			wait(&wstatus);
			return (handle_status(wstatus));
		} else
			return (-1);
	}
	return (status);
}

int run(void)
{
	int status = 0;

	my_putstr("$> ");
	for (char *line = gnl(0); !call_exit(line); line = gnl(0)) {
		if (my_strcmp(line, "exit") == 0) {
			my_putstr("exit\n");
			free(line);
			return (0);
		}
		status = exec(line);
		free(line);
		my_putstr("$> ");
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
