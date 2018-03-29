/*
** EPITECH PROJECT, 2017
** File Name : get_next_to.c
** File description:
** by Arthur Teisseire
*/

#include <stddef.h>
#include "my.h"

char *get_next_to(char const *str, char const *flags)
{
	int i = 0;
	int len = my_strlen(flags);

	while (str[i] != '\0' && my_strncmp(&str[i], flags, len) != 0)
		i++;
	if (str[i] == '\0')
		return (NULL);
	return (my_strdup(str + i + my_strlen(flags)));
}
