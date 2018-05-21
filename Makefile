##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
DSRC	=	$(realpath src)/
INC	=	$(realpath include)

DLIB	=	$(realpath lib)/
DMY	=	$(DLIB)my
DTREE	=	$(DLIB)tree
DTESTS	=	$(realpath tests)/
MY	=	my
TREE	=	tree
LIBS	=	-L$(DMY) -l$(MY) -L$(DTREE) -l$(TREE)

DBUILTS	=	$(DSRC)builtins/
DMYSH	=	$(DSRC)run/
DEXEC	=	$(DSRC)exec/
DINIT	=	$(DSRC)init/
DESTROY	=	$(DSRC)destroy/
DPARSE	=	$(DSRC)parse/

SRC     =	$(DSRC)main.c			\
		$(DINIT)btree_init.c		\
		$(DEXEC)exec.c			\
		$(DEXEC)execout_to_pipe.c	\
		$(DEXEC)exec_cmd.c		\
		$(DEXEC)btree_exec.c		\
		$(DEXEC)redir.c			\
		$(DEXEC)semi_colons.c		\
		$(DMYSH)run.c			\
		$(DMYSH)my_perror.c		\
		$(DMYSH)prompt.c		\
		$(DBUILTS)env.c			\
		$(DBUILTS)my_exit.c		\
		$(DBUILTS)cd.c			\
		$(DBUILTS)exec_builtins.c	\
		$(DESTROY)node_destroy.c	\
		$(DPARSE)parse_ambiguous.c	\
		$(DPARSE)parse_null.c		\
		$(DPARSE)get_sep.c
CFLAGS	+=	-Wall -W -Wextra -I$(INC) -g
OBJ	=	$(SRC:.c=.o)
NAME	=	mysh

all: $(NAME)

$(NAME):	$(OBJ)
	make -C $(DMY)
	make -C $(DTREE)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
	make clean -C $(DMY)
	make clean -C $(DTREE)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(DMY)
	make fclean -C $(DTREE)
	rm -f $(NAME)

re: fclean all
	make clean

test_run: re
	make test_run -C $(DTESTS)
