/*
** EPITECH PROJECT, 2017
** File Name : my_strdup.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *str)
{
	char *res = malloc(sizeof(char) * (my_strlen(str) + 1));

	my_strcpy(res, str);
	return (res);
}
