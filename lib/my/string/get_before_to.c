/*
** EPITECH PROJECT, 2017
** File Name : get_before_to.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

char *get_before_to(char const *str, char const *flags)
{
	int len = len_to_flags(str, flags);

	if (str[len] == '\0')
		return (NULL);
	return (my_strndup(str, len));
}
