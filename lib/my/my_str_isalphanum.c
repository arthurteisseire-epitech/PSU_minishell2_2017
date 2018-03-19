/*
** EPITECH PROJECT, 2017
** File Name: my_str_isalphanum
** File description:
** Arthur Teisseire
*/

int my_str_isalphanum(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= 'A' && str[i] <= 'Z')
		|| (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}
