/*
** EPITECH PROJECT, 2017
** File Name : count_endflags.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"

int count_endflags(char const *str, char const *flags)
{
	int len = my_strlen(str) - 1;
	int i = len;

	while (is_char_in_str(str[i], flags))
		i--;
	return (len - i);
}
