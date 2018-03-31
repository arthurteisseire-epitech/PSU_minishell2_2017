/*
** EPITECH PROJECT, 2017
** File Name : env.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "builtins.h"

int my_env(char **args)
{
	if (args[1]) {
		my_puterror("No argument for env, thanks\n");
		return (-1);
	}
	disp_env(environ);
	return (0);
}

int my_setenv(char **args)
{
	int nb_args = my_arrlen((void *)args);

	if (nb_args == 1) {
		my_env(args);
		return (0);
	} else if (nb_args >= 4) {
		my_puterror("setenv: Too many arguments.\n");
		return (-1);
	}
	if (!my_str_isalphanum(args[1])) {
		my_puterror("setenv: Variable name must contain "
		"alphanumeric characters.\n");
		return (-1);
	}
	if (set_env_value(args[1], args[2], environ) == -1)
		add_var(&args[1]);
	return (0);
}

int my_unsetenv(char **args)
{
	int index;

	if (my_arrlen((void *)args) == 1) {
		my_puterror("unsetenv: Too few arguments.\n");
		return (-1);
	}
	index = index_name(args[1], environ);
	rm_arrelem((void *)environ, index, NULL);
	return (0);
}

int add_var(char **args)
{
	int i = 0;

	while (environ[i] != NULL)
		i++;
	environ[i] = array_to_str(args, "=");
	if (environ[i] == NULL)
		return (-1);
	environ[i + 1] = NULL;
	return (0);
}