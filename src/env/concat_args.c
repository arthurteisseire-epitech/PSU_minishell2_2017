/*
** EPITECH PROJECT, 2017
** File Name : concat_args.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "my.h"
#include "env.h"

char *concat_args(char **args)
{
	char *var = my_strdup(args[0]);

	if (var == NULL)
		return (NULL);
	var = concat(var, "=", my_strlen(args[1]));
	var = concat(var, args[1], my_strlen(args[1]));
	return (var);
}
