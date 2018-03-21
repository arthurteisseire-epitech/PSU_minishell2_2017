##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
INC	=	my.h
DTESTS	=	tests/

SRC	=	my_strlen.c \
		my_putchar.c \
		my_putstr.c \
		my_puterror.c \
		my_put_nbr.c \
		my_putnbr_base.c \
		my_strcmp.c \
		my_strncmp.c \
		my_str_isalphanum.c \
		my_str_isnum.c \
		my_strcpy.c \
		my_strncpy.c \
		my_strcat.c \
		my_strncat.c \
		my_strdup.c \
		my_atoi.c \
		my_itoa.c \
		concat.c \
		get_next_line.c \
		split.c \
		my_strndup.c \
		get_env_value.c \
		my_arrlen.c \
		free_array.c \
		my_arrcpy.c \
		count_flags.c \
		rm_arrelem.c

CFLAGS	+=	-Wall -W -Wextra
OBJ	=	$(SRC:.c=.o)
NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	cp $(INC) ../../include
	ar rc $(NAME) $(OBJ)

clean:
	make clean -C $(DTESTS)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(DTESTS)
	rm -f $(NAME)

re:	fclean all

test_run: re
	make test_run -C $(DTESTS)
