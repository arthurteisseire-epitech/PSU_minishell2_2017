/*
** EPITECH PROJECT, 2017
** File Name : my_atoi.c
** File description:
** By Arthur Teisseire
*/

int my_atoi(char const *str)
{
	int nb = 0;
	int isneg = str[0] == '-' ? 1 : 0;
	int i = isneg;

	while (str[i] != '\0') {
		nb *= 10;
		nb += (str[i] - '0');
		i++;
	}
	if (isneg)
		return (-nb);
	return (nb);
}
