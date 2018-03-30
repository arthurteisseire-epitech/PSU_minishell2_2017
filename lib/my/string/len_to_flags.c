/*
** EPITECH PROJECT, 2017
** File Name : len_to_flags.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"

int len_to_flags(char const *str, char const *flags)
{
	int i = 0;

	while (str[i] != '\0' && !is_char_in_str(str[i], flags))
		i++;
	return (i);
}
