/*
** EPITECH PROJECT, 2017
** File Name : my_strndup.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>

char *my_strndup(char const *str, const int size)
{
	int i = 0;
	char *new_str = malloc(sizeof(char) * (size + 1));

	if (new_str == NULL)
		return (NULL);
	while (i < size && str[i] != '\0') {
		new_str[i] = str[i];
		i++;
	}
	new_str[size] = '\0';
	return (new_str);
}
