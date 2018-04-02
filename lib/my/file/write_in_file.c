/*
** EPITECH PROJECT, 2017
** File Name : write_in_file.c
** File description:
** by Arthur Teisseire
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int write_in_file(char *pathname, int fd_in, int flag_open)
{
	int fd = open(pathname, O_WRONLY | flag_open);

	if (fd == -1)
		fd = open(pathname, O_CREAT | O_WRONLY | flag_open,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	my_fdcpy(fd, fd_in);
	close(fd);
	return (0);
}
