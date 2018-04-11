/*
** EPITECH PROJECT, 2017
** File Name : my_exit.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int my_exit(char **array)
{
	int len = my_arrlen((void **)array);

	if (len == 1)
		exit(0);
	if (len > 2) {
		my_putstr("exit: Expression Syntax.\n");
		return (1);
	}
	if (!my_str_isnum(array[1])) {
		my_putstr("exit: Expression Syntax.\n");
		return (1);
	}
	exit(my_atoi(array[1]));
}
