/*
** EPITECH PROJECT, 2017
** File Name : disp_env.c
** File description:
** by Arthur Teisseire
*/

#include <stddef.h>
#include "my.h"

void disp_env(char **env)
{
	int i = 0;

	while (env[i] != NULL) {
		bufferize(env[i]);
		if (!is_char_in_str('=', env[i]))
			bufferize("=");
		bufferize("\n");
		i++;
	}
	bufferize(NULL);
}
