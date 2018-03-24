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

SRC	=	$(DSRC)my_strlen.c \
		$(DSRC)my_putchar.c \
		$(DSRC)my_putstr.c \
		$(DSRC)my_puterror.c \
		$(DSRC)my_put_nbr.c \
		$(DSRC)my_putnbr_base.c \
		$(DSRC)my_strcmp.c \
		$(DSRC)my_strncmp.c \
		$(DSRC)my_str_isalphanum.c \
		$(DSRC)my_strcpy.c \
		$(DSRC)my_strncpy.c \
		$(DSRC)my_strcat.c \
		$(DSRC)my_strncat.c \
		$(DSRC)my_strdup.c \
		$(DSRC)my_atoi.c \
		$(DSRC)my_itoa.c \
		$(DSRC)concat.c \
		$(DSRC)get_next_line.c \
		$(DSRC)split.c

SRC_UT	=	$(DSRC_UT)redirect.c \
		$(DSRC_UT)tests_output.c \
		$(DSRC_UT)tests_cpy.c \
		$(DSRC_UT)tests_strcat.c \
		$(DSRC_UT)tests_atoi.c \
		$(DSRC_UT)tests_base.c \
		$(DSRC_UT)tests_split.c \
		$(DSRC_UT)tests_get_next_line.c \
		$(DSRC_UT)tests_cmp.c

LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
CFLAGS	=	-Wall -W -Wextra --coverage -I$(INC)
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
