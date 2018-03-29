/*
** EPITECH PROJECT, 2017
** File Name : itoa.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>

int nb_len(int nb)
{
	int len = 0;

	if (nb == 0)
		return (1);
	while (nb != 0) {
		nb /= 10;
		len++;
	}
	return (len);
}

char *my_itoa(int nb)
{
	int isneg = nb < 0 ? 1 : 0;
	int len = nb_len(nb) + isneg;
	char *res = malloc(sizeof(char) * (len + 1));

	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	len--;
	if (isneg) {
		res[0] = '-';
		nb = -nb;
	}
	while (len >= isneg) {
		res[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (res);
}
