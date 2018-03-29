/*
** EPITECH PROJECT, 2017
** File Name : my_putchar.c
** File description:
** By Arthur Teisseire
*/

#include <unistd.h>

void my_putchar(char const c)
{
	write(1, &c, 1);
}
