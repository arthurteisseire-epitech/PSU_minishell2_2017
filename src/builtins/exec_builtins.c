/*
** EPITECH PROJECT, 2017
** File Name : exec_builtins.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "builtins.h"
#include "env.h"

static const builtins_t builtins[NB_BUILTINS] = {
	{"cd", cd},
	{"env", my_env},
	{"unsetenv", my_unsetenv},
	{"setenv", my_setenv}
};

int exec_builtins(sh_t *sh)
{
	for (int i = 0; i < NB_BUILTINS; i++)
		if (my_strcmp(builtins[i].name, sh->args[0]) == 0) {
			builtins[i].f(sh->args);
			return (1);
		}
	return (0);
}
