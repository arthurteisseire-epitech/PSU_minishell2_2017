##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
INC	=	btree.h
DTESTS	=	tests/
DSRC	=	./
DINC	=	./

SRC	=	$(DSRC)btree_apply_infix.c	\
		$(DSRC)btree_apply_prefix.c	\
		$(DSRC)btree_apply_suffix.c	\
		$(DSRC)btree_apply_nodes.c	\
		$(DSRC)btree_apply_last.c	\
		$(DSRC)btree_create_node.c	\
		$(DSRC)btree_insert_data.c	\
		$(DSRC)btree_search_item.c	\
		$(DSRC)btree_level_count.c	\
		$(DSRC)btree_node_count.c

CFLAGS	+=	-Wall -W -Wextra -I$(DINC)
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
