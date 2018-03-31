/*
** EPITECH PROJECT, 2017
** File Name : environ.h
** File description:
** by Arthur Teisseire
*/

#ifndef ENV_H
#define ENV_H

int my_setenv(char **args);
int my_unsetenv(char **args);
int my_env(char **args);

int add_var(char **args);
int remove_var(char **args);
int set_value(char **args);

#endif
