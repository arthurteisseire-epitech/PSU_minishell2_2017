/*
** EPITECH PROJECT, 2017
** File Name : apply_on_array.c
** File description:
** by Arthur Teisseire
*/

int apply_on_array(void **array, int (*applyf)())
{
	int status;
	int i = 0;

	while (array[i]) {
		status = applyf(array[i]);
		if (status != 0)
			return (status);
		i++;
	}
	return (0);
}
