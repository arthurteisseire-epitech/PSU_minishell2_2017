/*
** EPITECH PROJECT, 2017
** File Name : write_in_file.c
** File description:
** by Arthur Teisseire
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int write_in_file(int fd_in, char *pathname, int flag_open)
{
	char buff[READ_SIZE];
	int size;
	int fd = open(pathname, O_WRONLY);

	if (fd == -1)
		fd = open(pathname, flag_open,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	size = read(fd_in, buff, READ_SIZE);
	while (size != 0) {
		write(fd, buff, size);
		size = read(fd_in, buff, READ_SIZE);
	}
	close(fd);
	return (0);
}
