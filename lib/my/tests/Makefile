##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
DSRC_UT	=	./
DLIB	=	../
INC	=	$(DLIB)

DSRC	=	../
DSTRING	=	$(DSRC)string/
DPUT	=	$(DSRC)put/
DENV	=	$(DSRC)env/
DARRAY	=	$(DSRC)array/

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
		$(DARRAY)my_arrcpy.c		\
		$(DARRAY)my_arrlen.c		\
		$(DARRAY)apply_on_array.c	\
		$(DARRAY)rm_arrelem.c		\
		$(DARRAY)free_and_set.c		\
		$(DARRAY)free_array.c		\
		$(DARRAY)split.c		\
		$(DSRC)get_next_line.c 		\
		$(DENV)get_env_value.c		\
		$(DENV)index_name.c

SRC_UT	=	$(DSRC_UT)redirect.c		\
		$(DSRC_UT)tests_output.c	\
		$(DSRC_UT)tests_cpy.c		\
		$(DSRC_UT)tests_strcat.c	\
		$(DSRC_UT)tests_atoi.c		\
		$(DSRC_UT)tests_base.c		\
		$(DSRC_UT)tests_split.c		\
		$(DSRC_UT)tests_get_next_line.c	\
		$(DSRC_UT)tests_get_next_to.c	\
		$(DSRC_UT)tests_cmp.c

LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
CFLAGS	+=	-Wall -W -Wextra --coverage -I$(INC)
LDFLAGS	=	-lcriterion -lgcov
NAME	=	units

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_run: re
	./$(NAME)
	gcov *.gcno
