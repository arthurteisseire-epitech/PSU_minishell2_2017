/*
** EPITECH PROJECT, 2017
** File Name : my_arrlen.h
** File description:
** By Arthur Teisseire
*/

int my_arrlen(void **data)
{
	int i = 0;

	while (data && data[i])
		i++;
	return (i);
}
