/*
** EPITECH PROJECT, 2017
** File Name : my.h
** File description:
** By Arthur Teisseire
*/

#ifndef MY_H
#define MY_H

#define READ_SIZE 4096

void	my_putchar(char const c);
void	my_puterror(char const *str);
void	my_putstr(char const *str);
int	my_strlen(char const *str);
int	my_atoi(char const *str);
char*	my_strcpy(char *dest, char const *src);
char*	my_strncpy(char *dest, char const *src, int const n);
int	my_put_nbr(int nb);
int	my_str_isalphanum(char const *str);
char*	my_strdup(char const *str);
int	my_strcmp(char const *s1, char const *s2);
int	my_strncmp(char const *s1, char const *s2, int const n);
char*	get_next_word(char **str, char const *flags);
int	count_words(char *str, char const *flags);
char**	split(char *str, char const *flags);
int	is_char_in_str(char const c, char const *str);
int	len_first_word(char *str, char const *flags);
int	my_putnbr_base(unsigned int nbr, char const *base);
char*	get_next_line(int fd);
char*	concat(char *dest, char *src, int len_src);
char*	my_strcat(char *dest, char const *src);
char*	my_strncat(char *dest, char const *src, int const n);
int	nb_len(int nb);
char*	my_itoa(int nb);
void	free_array(char **array);
char	*my_strndup(char const *str, const int size);
char*	get_env_value(char **env, char const *var);
int	my_str_isnum(char const *str);
int     my_arrlen(void **data);
char**  my_arrcpy(char const **array);
void	rm_arrelem(void **array, int index, void (*free_fun)(void *ptr));

#endif
