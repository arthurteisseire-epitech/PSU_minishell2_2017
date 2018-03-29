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
	int fd = open(pathname, flag_open);
	char buff[READ_SIZE];
	int size = read(fd_in, buff, READ_SIZE);

	while (size != 0) {
		write(fd, buff, size);
		size = read(fd_in, buff, READ_SIZE);
	}   
	return (0);
}
