/*
** EPITECH PROJECT, 2017
** File Name : get_env_value.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

char *get_env_value(char **env, char const *var)
{
	int i = 0;
	char *curr_var = NULL;
	char *tmp;

	while (env[i] != NULL) {
		tmp = env[i];
		curr_var = get_next_word(&tmp, "=");
		if (curr_var == NULL)
			return (NULL);
		if (my_strcmp(curr_var, var) == 0) {
			tmp++;
			free(curr_var);
			return (my_strdup(tmp));
		}
		free(curr_var);
		i++;
	}
	return (NULL);
}
