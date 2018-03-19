/*
** EPITECH PROJECT, 2017
** File Name : set_value.c
** File description:
** by Arthur Teisseire
*/

#include "mysh.h"
#include "env.h"

int set_value(char **args)
{
	int index = index_name(args[0]);

	if (index == -1)
		return (-1);
	environ[index] = concat_args(args);
	if (environ[index] == NULL)
		return (-1);
	return (0);
}
