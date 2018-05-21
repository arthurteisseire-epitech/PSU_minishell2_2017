/*
** EPITECH PROJECT, 2017
** File Name : cd.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"

static char *get_path(void)
{
	char buff[4096];
	char *path;

	for (int i = 0; i < 4096; i++)
		buff[i] = '\0';
	path = getcwd(buff, sizeof(buff));
	if (path == NULL)
		return (NULL);
	path = my_strdup(path);
	return (path);
}

static void set_env_pwd(void)
{
	char *pwd = get_env_value("PWD", environ);
	char *path = get_path();

	if (path != NULL && my_strcmp(pwd, path) != 0) {
		set_env_value("OLDPWD", pwd, environ);
		set_env_value("PWD", path, environ);
	}
	free(pwd);
	free(path);
}

int cd(char **args)
{
	int len;
	int status;

	if (args == NULL || args[0] == NULL)
		return (EXIT_FAILURE);
	len = my_arrlen((void **)args);
	if (len > 2) {
		my_puterror("cd: Too many arguments.\n");
		return (EXIT_FAILURE);
	}
	if (len == 1)
		status = chdir(get_env_value("HOME", environ));
	else if (my_strcmp(args[1], "-") == 0)
		status = chdir(get_env_value("OLDPWD", environ));
	else
		status = chdir(args[1]);
	status == -1 ? my_perror(args[1]) : set_env_pwd();
	return (status == -1 ? EXIT_FAILURE : status);
}
