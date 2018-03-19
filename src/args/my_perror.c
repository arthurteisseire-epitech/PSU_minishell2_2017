/*
** EPITECH PROJECT, 2017
** File Name : my_perror.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "my_perror.h"

void my_perror(char *str)
{
	if (str) {
		my_puterror(str);
		my_puterror(": ");
	}
	my_puterror(strerror(errno));
	my_puterror(".\n");
}
