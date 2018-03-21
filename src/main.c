/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"

int main(int ac, char **av)
{
	sh_t sh;
	int status;

	sh.rvalue = 0;
	if (ac != 1) {
		my_puterror(av[0]);
		my_puterror(": The program must take one argument\n");
		return (84);
	}
	status = mysh(&sh);
	if (status == -1) {
		my_puterror("\nAn error occured\n");
		return (84);
	}
	printf("RETURN VALUE: %d\n", sh.rvalue);
	return (sh.rvalue);
}
