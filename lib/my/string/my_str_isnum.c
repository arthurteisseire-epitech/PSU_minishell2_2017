/*
** EPITECH PROJECT, 2017
** File Name : my_str_isnum.c
** File description:
** by Arthur Teisseire
*/

int my_str_isnum(char const *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
