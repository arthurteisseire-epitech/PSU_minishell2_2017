##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Arthur Teisseire
##

CC	=	gcc
DSRC	=	$(realpath src)/
INC	=	$(realpath include)
DLIB	=	$(realpath lib/my)/
DTESTS	=	$(realpath tests)/
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
DENV	=	$(DSRC)env/
DBUILTS	=	$(DSRC)builtins/
DMYSH	=	$(DSRC)mysh/
DARGS	=	$(DSRC)args/
SRC     =	$(DSRC)main.c \
		$(DMYSH)mysh.c \
		$(DMYSH)run.c \
		$(DMYSH)exec_cmd.c \
		$(DARGS)my_perror.c \
		$(DENV)env.c \
		$(DENV)add_var.c \
		$(DENV)concat_args.c \
		$(DENV)get_var.c \
		$(DENV)index_name.c \
		$(DENV)remove_var.c \
		$(DENV)set_value.c \
		$(DBUILTS)cd.c \
		$(DBUILTS)exec_builtins.c
CFLAGS	+=	-Wall -W -Wextra -I$(INC) -g
OBJ	=	$(SRC:.c=.o)
NAME	=	mysh

all: $(NAME)

$(NAME):	$(OBJ)
	make -C $(DLIB)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
	make clean -C $(DLIB)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(DLIB)
	rm -f $(NAME)

re: fclean all
	make clean

test_run: re
	make test_run -C $(DTESTS)
