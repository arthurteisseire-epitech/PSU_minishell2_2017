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

DENV	=	$(DSRC)env/
DBUILTS	=	$(DSRC)builtins/
DMYSH	=	$(DSRC)mysh/
DERROR	=	$(DSRC)error/
DEXEC	=	$(DSRC)exec/

SRC     =	$(DSRC)main.c			\
		$(DEXEC)get_token.c		\
		$(DEXEC)store_pipe.c		\
		$(DMYSH)mysh.c			\
		$(DMYSH)run.c			\
		$(DMYSH)exec_cmd.c		\
		$(DERROR)my_perror.c		\
		$(DENV)env.c			\
		$(DENV)add_var.c		\
		$(DENV)concat_args.c		\
		$(DENV)get_var.c		\
		$(DENV)index_name.c		\
		$(DENV)remove_var.c		\
		$(DENV)set_value.c		\
		$(DBUILTS)cd.c			\
		$(DBUILTS)exec_builtins.c
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
