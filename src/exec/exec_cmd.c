/*
** EPITECH PROJECT, 2017
** File Name : exec_cmd.c
** File description:
** by Arthur Teisseire
*/

#include <errno.h>
#include <string.h>
#include "my.h"
#include "btree.h"
#include "mysh.h"
#include "builtins.h"

static int exec_with_path(char **args)
{
	char *path = get_env_value("PATH", environ);
	int len_prog = my_strlen(args[0]);
	char **paths;
	char *cmd = NULL;
	int i = 0;

	if (!path)
		return (-1);
	paths = split(path, ":");
	while (paths[i] != NULL) {
		cmd = concat(my_strdup(paths[i]), "/", 1);
		cmd = concat(cmd, args[0], len_prog);
		if (access(cmd, F_OK) != -1)
			execve(cmd, args, environ);
		free(cmd);
		i++;
	}
	free_array(paths);
	free(path);
	return (-1);
}

static int wrong_arch(char *arg)
{
	if (errno == ENOEXEC) {
		my_putstr(arg);
		my_putstr(": ");
		my_putstr(strerror(ENOEXEC));
		my_putstr(". Wrong Architecture.\n");
		return (1);
	}
	return (0);
}

static int right_ok(char *pathname)
{
	DIR *dir = opendir(pathname);

	if (access(pathname, X_OK) == -1 || dir != NULL) {
		my_putstr(pathname);
		my_putstr(": Permission denied.\n");
		if (dir)
			closedir(dir);
		return (0);
	}
	return (1);
}

int exec_cmd(btree_t *root)
{
	cmd_t *this = root->item;
	char **cmd = this->array;
	int status = -1;

	if (cmd && cmd[0] && access(cmd[0], F_OK) != -1) {
		if (!right_ok(cmd[0]))
			return (-1);
		status = execve(cmd[0], cmd, environ);
	}
	if (wrong_arch(cmd[0]))
		return (-1);
	if (status == -1 && my_strcmp(cmd[0], "") != 0)
		status = exec_with_path(cmd);
	if (status == -1 && cmd[0] != NULL) {
		my_putstr(cmd[0]);
		my_putstr(": Command not found.\n");
		return (1);
	}
	return (0);
}
