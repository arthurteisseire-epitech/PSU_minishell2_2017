/*
** EPITECH PROJECT, 2017
** File Name : my_putnbr_base.c
** File description:
** By Arthur Teisseire
*/

#include "my.h"

int my_putnbr_base(unsigned int nbr, char const *base)
{
	unsigned int nb_base = my_strlen(base);
	int size = 0;

	if (nbr >= nb_base) {
		size += my_putnbr_base(nbr / nb_base, base);
		my_putchar(base[nbr % nb_base]);
		return (size + 1);
	} else {
		my_putchar(base[nbr % nb_base]);
		size++;
	}
	return (size);
}
