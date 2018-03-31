/*
** EPITECH PROJECT, 2017
** File Name : my.h
** File description:
** By Arthur Teisseire
*/

#ifndef MY_H
#define MY_H

#define READ_SIZE 4096

char*	get_next_line(int fd);

char*	get_env_value(char **env, char const *var);
int	index_name(char *var_name, char **env);

char**	split(char *str, char const *flags);
char*	array_to_str(char **array, char *between);
void	free_array(char **array);
int     my_arrlen(void **data);
void	my_arrcpy(void **dest, void const **array);
void	rm_arrelem(void **array, int index, void (*free_fun)(void *ptr));
int	apply_on_array(void **array, int (*applyf)());
void	free_and_set(void **ptr, void *new_ptr);
void*	my_memcpy(void *dest, void *src, int size);

int	write_in_file(char *pathname, int fd_in, int flag_open);
void	my_fdcpy(int fd_dest, int fd_src);

void	my_putchar(char const c);
void	my_puterror(char const *str);
void	my_putstr(char const *str);
int	my_put_nbr(int nb);
int	my_putnbr_base(unsigned int nbr, char const *base);

char*	get_next_word(char **str, char const *flags);
int	my_strlen(char const *str);
int	my_atoi(char const *str);
int	my_strcpy(char *dest, char const *src);
char*	my_strncpy(char *dest, char const *src, int const n);
int	my_str_isalphanum(char const *str);
char*	my_strdup(char const *str);
int	my_strcmp(char const *s1, char const *s2);
int	my_strncmp(char const *s1, char const *s2, int const n);
int	count_words(char const *str, char const *flags);
int	is_char_in_str(char const c, char const *str);
int	len_to_flags(char const *str, char const *flags);
char*	concat(char *dest, char *src, int len_src);
char*	my_strcat(char *dest, char const *src);
char*	my_strncat(char *dest, char const *src, int const n);
int	nb_len(int nb);
char*	my_itoa(int nb);
int	my_str_isnum(char const *str);
char*	my_strndup(char const *str, const int size);
int	count_flags(char const *str, char const *flags);
int	count_endflags(char const *str, char const *flags);
char*	my_strip(char **str, char const *flags);
char*	get_next_to(char const *str, char const *flags);
char*	get_before_to(char const *str, char const *flags);
void	bufferize(char *str);
char*	my_strstr(char const *haystack, char const *needle);

#endif
