##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
INC	=	./
DTESTS	=	tests/
DSRC	=	./
DSTRING	=	$(DSRC)string/
DPUT	=	$(DSRC)put/
DENV	=	$(DSRC)env/
DARRAY	=	$(DSRC)array/
DFILE	=	$(DSRC)file/

SRC	=	$(DPUT)my_put_nbr.c		\
		$(DPUT)my_putchar.c		\
		$(DPUT)my_puterror.c		\
		$(DPUT)my_putnbr_base.c		\
		$(DPUT)my_putstr.c		\
		$(DSTRING)my_str_isalphanum.c	\
		$(DSTRING)my_str_isnum.c	\
		$(DSTRING)my_strcat.c		\
		$(DSTRING)my_strcmp.c		\
		$(DSTRING)my_strcpy.c		\
		$(DSTRING)my_strdup.c		\
		$(DSTRING)my_strip.c		\
		$(DSTRING)my_strlen.c		\
		$(DSTRING)my_strncat.c		\
		$(DSTRING)my_strncmp.c		\
		$(DSTRING)my_strncpy.c		\
		$(DSTRING)my_strndup.c		\
		$(DSTRING)count_endflags.c	\
		$(DSTRING)count_flags.c		\
		$(DSTRING)my_atoi.c		\
		$(DSTRING)my_itoa.c		\
		$(DSTRING)concat.c		\
		$(DSTRING)get_next_to.c		\
		$(DSTRING)bufferize.c		\
		$(DARRAY)my_memcpy.c		\
		$(DARRAY)my_arrlen.c		\
		$(DARRAY)my_arrdup.c		\
		$(DARRAY)apply_on_array.c	\
		$(DARRAY)rm_arrelem.c		\
		$(DARRAY)free_and_set.c		\
		$(DARRAY)free_array.c		\
		$(DARRAY)split.c		\
		$(DSRC)get_next_line.c 		\
		$(DENV)get_env_value.c		\
		$(DENV)index_name.c		\
		$(DFILE)write_in_file.c

CFLAGS	+=	-Wall -W -Wextra -I$(INC)
OBJ	=	$(SRC:.c=.o)
NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	cp my.h ../../include
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
