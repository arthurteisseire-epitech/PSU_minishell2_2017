/*
** EPITECH PROJECT, 2017
** File Name : set_env_value.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"

int set_env_value(char *name, char *new_value, char **env)
{
	int index = index_name(name, env);

	if (index == -1)
		return (-1);
	env[index] = concat(my_strdup(name), "=", 1);
	env[index] = concat(env[index], new_value, my_strlen(new_value));
	if (!env[index])
		return (-1);
	return (0);
}
