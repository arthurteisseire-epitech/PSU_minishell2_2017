/*
** EPITECH PROJECT, 2017
** File Name : exec_builtins.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "builtins.h"

static const builtins_t builtins[NB_BUILTINS] = {
	{"cd", cd},
	{"env", my_env},
	{"setenv", my_setenv},
	{"unsetenv", my_unsetenv},
	{"exit", my_exit}
};

int exec_builtins(char *cmd)
{
	char **array = split(cmd, " \t");
	int status;

	if (array == NULL)
		return (ERROR);
	for (int i = 0; i < NB_BUILTINS; i++)
		if (my_strcmp(builtins[i].name, array[0]) == 0) {
			status = builtins[i].f(array);
			free_array(array);
			return (status);
		}
	free_array(array);
	return (2);
}
