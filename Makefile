##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC      =       gcc

SRC     =	my_runner_main.c \
			my_runner_create.c \
			my_runner_draw.c \
			my_runner_check.c \
			my_runner_move.c

OBJ     =       $(SRC:.c=.o)

NAME    =       my_runner

CFLAGS  =       -W -Wall -Wextra -Werror -ansi -pedantic -Ofast -g -std=c99 -I include

all:    $(NAME)

$(NAME):        $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
		rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
