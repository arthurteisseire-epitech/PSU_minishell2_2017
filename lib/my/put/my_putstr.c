/*
** EPITECH PROJECT, 2017
** File Name : my_putstr.c
** File description:
** By Arthur Teisseire
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
}
