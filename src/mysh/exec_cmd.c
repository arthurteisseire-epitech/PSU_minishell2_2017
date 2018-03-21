/*
** EPITECH PROJECT, 2017
** File Name : exec_cmd.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "env.h"
#include "builtins.h"
#include "my_perror.h"

static char *concat_with_slash(char *dest, char *src, int len_src)
{
	int len_dest = my_strlen(dest);
	char *res = malloc(sizeof(char) * (len_dest + len_src + 2));
	int i = 0;
	int j = 0;

	if (res == NULL)
		return (NULL);
	while (dest[i] != '\0') {
		res[i] = dest[i];
		i++;
	}
	res[i] = '/';
	i++;
	while (j < len_src) {
		res[i] = src[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int exec_with_path(char **args)
{
	char *path = get_value("PATH");
	int len_prog = my_strlen(args[0]);
	char **paths;
	char *cmd = NULL;
	int i = 0;

	if (!path)
		return (-1);
	paths = split(path, ":");
	while (paths[i] != NULL) {
		cmd = concat_with_slash(paths[i], args[0], len_prog);
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
	DIR *dir;

	if (access(pathname, X_OK) == -1) {
		my_putstr(pathname);
		my_putstr(": Permission denied.\n");
		return (0);
	} else if ((dir = opendir(pathname)) != NULL) {
		my_putstr(pathname);
		my_putstr(": Permission denied.\n");
		closedir(dir);
		return (0);
	}
	return (1);
}

int exec_cmd(sh_t *sh)
{
	int status = -1;

	if (sh->args && sh->args[0] && access(sh->args[0], F_OK) != -1) {
		if (!right_ok(sh->args[0]))
			return (-1);
		status = execve(sh->args[0], sh->args, environ);
	}
	if (wrong_arch(sh->args[0]))
		return (-1);
	if (status == -1 && my_strcmp(sh->args[0], "") != 0)
		status = exec_with_path(sh->args);
	if (status == -1 && sh->args[0] != NULL) {
		my_putstr(sh->args[0]);
		my_putstr(": Command not found.\n");
		return (1);
	}
	return (0);
}
