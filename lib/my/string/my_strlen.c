/*
** EPITECH PROJECT, 2017
** File Name : my_strlen.c
** File description:
** By Arthur Teisseire
*/

#include "my.h"

int my_strlen(char const *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
