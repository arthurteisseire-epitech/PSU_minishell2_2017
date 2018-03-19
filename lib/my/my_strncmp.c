/*
** EPITECH PROJECT, 2017
** File Name : my_strncmp.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	n--;
	while (s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}
