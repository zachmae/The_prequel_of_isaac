##
## EPITECH PROJECT, 2021
## lib_csfml
## File description:
## Makefile
##

SRC	=	button.c\
		convert.c\
		check_event.c\
		coli_sprite.c\
		sprite_intersect.c\
		create_window.c\
		create_my_sprite.c\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3 -Wall -Wextra -Iincludes

RM	=	rm -f

NAME	=	libcsfml.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc -o $(NAME) $(OBJ)
	@echo -ne "\033[32mCOMPILATION SUCCESFUL!\n\033[00m"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)