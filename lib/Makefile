##
## EPITECH PROJECT, 2021
## lib_csfml
## File description:
## Makefile
##

SRC	=	my_array_len.c	\
		init_buffer.c	\
		my_itoa.c	\
		my_strlen.c	\
		my_strcmp.c	\
		my_strdup.c	\
		my_strncpy.c	\
		my_putstr.c	\
		str_to_array.c	\
		free_tab.c	\
		my_free.c \
		my_getnbr.c \
		my_strcmp.c \
		my_tablen.c \
		my_tabdup.c \
		tablen.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Iincludes

RM	=	rm -f

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc -o $(NAME) $(OBJ)
	@echo -ne "\033[32mCOMPILATION SUCCESFUL!\n\033[00m"

debug: CFLAGS += -g

debug: re

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)