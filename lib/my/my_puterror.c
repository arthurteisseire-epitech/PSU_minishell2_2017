/*
** EPITECH PROJECT, 2017
** File Name : my_puterror.c
** File description:
** By Arthur Teisseire
*/

#include <unistd.h>
#include "my.h"

void my_puterror(char const *str)
{
	write(2, str, my_strlen(str));
}
