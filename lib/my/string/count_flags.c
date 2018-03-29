/*
** EPITECH PROJECT, 2017
** File Name : count_flags.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"

int count_flags(char const *str, char const *flags)
{
	int i = 0;

	while (is_char_in_str(str[i], flags))
		i++;
	return (i);
}
