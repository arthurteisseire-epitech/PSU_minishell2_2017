##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
INC	=	btree.h
DTESTS	=	tests/

SRC	=	btree_apply_infix.c \
		btree_apply_prefix.c \
		btree_apply_suffix.c \
		btree_create_node.c \
		btree_insert_data.c \
		btree_search_item.c \
		btree_level_count.c \
		btree_node_count.c

CFLAGS	+=	-Wall -W -Wextra
OBJ	=	$(SRC:.c=.o)
NAME	=	libtree.a

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
