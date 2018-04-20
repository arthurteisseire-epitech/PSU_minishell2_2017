##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
DSRC	=	../
DSRC_UT	=	./
DLIB	=	../
INC	=	$(DLIB)

SRC	=	$(DSRC)btree_apply_infix.c \
		$(DSRC)btree_apply_prefix.c \
		$(DSRC)btree_apply_suffix.c \
		$(DSRC)btree_create_node.c \
		$(DSRC)btree_insert_data.c \
		$(DSRC)btree_search_item.c \
		$(DSRC)btree_level_count.c \
		$(DSRC)btree_node_count.c

SRC_UT	=	$(DSRC_UT)tests_level_count.c

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
