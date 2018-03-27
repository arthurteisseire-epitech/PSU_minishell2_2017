/*
** EPITECH PROJECT, 2017
** File Name : cd.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "env.h"
#include "my_perror.h"

static int is_null(char **args)
{
	if (args == NULL)
		return (1);
	if (args[0] == NULL)
		return (1);
	return (0);
}

static char *get_path(void)
{
	char buff[4096];
	char *path;

	for (int i = 0; i < 4096; i++)
		buff[i] = '\0';
	if ((path = my_strdup(getcwd(buff, sizeof(buff)))) != NULL)
		return (path);
	my_puterror("Path too long.\n");
	return (NULL);
}

static void set_env_pwd(void)
{
	char *new_pwd[3] = {"PWD", NULL, NULL};
	char *old_pwd[3] = {"OLDPWD", NULL, NULL};

	new_pwd[1] = get_path();
	old_pwd[1] = get_value("PWD");
	set_value(new_pwd);
	set_value(old_pwd);
}

int cd(char **args)
{
	int i = 0;
	int status;

	if (is_null(args))
		return (-1);
	while (args[i] != NULL)
		i++;
	if (i >= 3) {
		my_puterror("cd: Too many arguments.\n");
		return (-1);
	}
	if (i == 1)
		status = chdir(get_value("HOME"));
	else if (my_strcmp(args[1], "-") == 0)
		status = chdir(get_value("OLDPWD"));
	else
		status = chdir(args[1]);
	status == -1 ? my_perror(args[1]) : set_env_pwd();
	return (status);
}
