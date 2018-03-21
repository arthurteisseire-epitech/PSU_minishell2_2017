/*
** EPITECH PROJECT, 2017
** File Name : my_strip.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

char *my_strip(char **str, char const *flags)
{
	char *to_free = *str;
	int bflags = count_flags(*str, flags);
	int eflags = count_endflags(*str, flags);

	*str += bflags;
	*str = my_strndup(*str, my_strlen(*str) - eflags);
	free(to_free);
	return (*str);
}
