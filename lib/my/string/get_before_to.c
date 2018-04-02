/*
** EPITECH PROJECT, 2017
** File Name : get_before_to.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

int count_to_word(char const *str, char const *word)
{
	int len = my_strlen(word);
	int i = 0;

	while (str[i] != '\0') {
		if (my_strncmp(&str[i], word, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char *get_before_to(char const *str, char const *flags)
{
	int len = count_to_word(str, flags);

	if (len == -1)
		return (NULL);
	return (my_strndup(str, len));
}
