/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"
#include "my.h"
#include "mysh.h"

int main_old(int ac, char **av)
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

int dispf(void *data)
{
	my_putstr(data);
	my_putchar('\n');
	return (0);
}

int main(void)
{
	char *s = get_next_line(0);
	char *curr = get_next_word(&s, ";");
	btree_t *root = btree_create_node(";");

	while (curr != NULL) {
		btree_insert_data(root, my_strip(&curr, " \t"), my_strcmp);
		curr = get_next_word(&s, ";");
	}
	btree_apply_prefix(root, dispf);
	return (0);
}
