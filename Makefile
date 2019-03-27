##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile project
##

SRC	=	src/main.c		\
		src/readfile.c		\
		src/lib.c		\
		src/initstruct.c	\
		src/createtab.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

RM	=	rm -f

CFLAGS	=	-Werror -Wextra -Wall

all:	$(NAME) clean

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) vgcore.*

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re
