/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include "btree.h"
#include "my.h"
#include "mysh.h"
#include "init.h"

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
	return (sh.rvalue);
}

int print_nodee(void *data)
{
	cmd_t *this = data;

	if (this->str) {
		bufferize(this->str);
		bufferize("\n");
	}
	return (0);
}

int print_node(btree_t *root)
{
	cmd_t *this = root->item;

	bufferize(this->str);
	bufferize("\n");
	return (0);
}

int main(int ac, char **av)
{
	btree_t *root;

	if (ac != 2)
		return (84);
	init_tree(&root, av[1]);
	if (root == NULL)
		return (84);
	btree_apply_last(root, print_node);
	bufferize(NULL);
	return (0);
}

/*
 *int main(void)
 *{
 *        cmd_t cmd;
 *        char *str_left[] = {"/bin/ls", "-l", NULL};
 *        char *str_right[] = {"/bin/grep", "a", NULL};
 *        char *str_end[] = {"/bin/cat", "-e", NULL};
 *        char buff[1];
 *
 *        cmd.pipefd[0] = 0;
 *        cmd.pipefd[1] = 1;
 *        execout_to_pipe(&cmd, str_left);
 *        execout_to_pipe(&cmd, str_right);
 *        execout_to_pipe(&cmd, str_end);
 *        while (read(cmd.pipefd[0], buff, 1) != 0)
 *                write(1, buff, 1);
 *        close(cmd.pipefd[0]);
 *        return (0);
 *}
 */
/*
 *
 *int main(void)
 *{
 *        char *s = get_next_line(0);
 *        char *curr = get_next_word(&s, ";");
 *        btree_t *root = btree_create_node(";");
 *
 *        while (curr != NULL) {
 *                btree_insert_data(root, my_strip(&curr, " \t"), my_strcmp);
 *                curr = get_next_word(&s, ";");
 *        }
 *        btree_apply_prefix(root, dispf);
 *        return (0);
 *}
 */
