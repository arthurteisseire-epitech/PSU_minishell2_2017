##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
INC	=	my.h
DTESTS	=	tests/
DSRC	=	./

SRC	=	$(DSRC)apply_on_array.c		\
		$(DSRC)concat.c			\
		$(DSRC)count_endflags.c		\
		$(DSRC)count_flags.c		\
		$(DSRC)free_and_set.c		\
		$(DSRC)free_array.c		\
		$(DSRC)get_env_value.c 		\
		$(DSRC)get_next_line.c 		\
		$(DSRC)my_arrcpy.c		\
		$(DSRC)my_arrlen.c		\
		$(DSRC)my_atoi.c		\
		$(DSRC)my_itoa.c		\
		$(DSRC)my_put_nbr.c		\
		$(DSRC)my_putchar.c		\
		$(DSRC)my_puterror.c		\
		$(DSRC)my_putnbr_base.c		\
		$(DSRC)my_putstr.c		\
		$(DSRC)my_str_isalphanum.c	\
		$(DSRC)my_str_isnum.c		\
		$(DSRC)my_strcat.c		\
		$(DSRC)my_strcmp.c		\
		$(DSRC)my_strcpy.c		\
		$(DSRC)my_strdup.c		\
		$(DSRC)my_strip.c		\
		$(DSRC)my_strlen.c		\
		$(DSRC)my_strncat.c		\
		$(DSRC)my_strncmp.c		\
		$(DSRC)my_strncpy.c		\
		$(DSRC)my_strndup.c		\
		$(DSRC)rm_arrelem.c		\
		$(DSRC)split.c

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
