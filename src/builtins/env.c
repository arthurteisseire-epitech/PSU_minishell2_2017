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
	if (args[1] != NULL) {
		my_puterror("No argument for env, thanks\n");
		return (EXIT_FAILURE);
	}
	disp_env(environ);
	return (EXIT_SUCCESS);
}

int my_setenv(char **args)
{
	if (my_arrlen((void *)args) == 1) {
		my_env(args);
		return (EXIT_SUCCESS);
	} else if (my_arrlen((void *)args) >= 4) {
		my_puterror("setenv: Too many arguments.\n");
		return (EXIT_FAILURE);
	}
	if (!my_str_isalphanum(args[1])) {
		my_puterror("setenv: Variable name must contain "
		"alphanumeric characters.\n");
		return (EXIT_FAILURE);
	}
	if (args[1][0] > '0' && args[1][0] < '9') {
		my_puterror("setenv: Variable name must"
		" begin with a letter.\n");
		return (EXIT_FAILURE);
	}
	if (set_env_value(args[1], args[2], environ) == -1)
		add_var(&args[1]);
	return (EXIT_SUCCESS);
}

int my_unsetenv(char **args)
{
	int index;

	if (my_arrlen((void *)args) == 1) {
		my_puterror("unsetenv: Too few arguments.\n");
		return (EXIT_FAILURE);
	}
	index = index_name(args[1], environ);
	rm_arrelem((void *)environ, index, NULL);
	return (EXIT_SUCCESS);
}

int add_var(char **args)
{
	int i = 0;

	while (environ[i] != NULL)
		i++;
	environ[i] = array_to_str(args, "=");
	if (environ[i] == NULL)
		return (EXIT_FAILURE);
	environ[i + 1] = NULL;
	return (EXIT_SUCCESS);
}
