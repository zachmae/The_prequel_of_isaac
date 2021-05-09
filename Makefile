##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## this is the makefile for matchstick
##

NAME		=		the_prequel_of_isaac

NAMET		=		${NAME}_tests

NAMEB		=		${NAME}_bonus

NAMES		=		server

SRC_PATH	=		src

TEST_PATH	=		tests

BONUS_PATH	=		bonus/src

SRC			=		${SRC_PATH}/main.c							\
					${SRC_PATH}/my_rpg.c						\
					${SRC_PATH}/usage.c							\
					${SRC_PATH}/error_handling.c				\
					${SRC_PATH}/init_core.c						\
					${SRC_PATH}/create_window.c					\
					${SRC_PATH}/find_scene.c					\
					${SRC_PATH}/free_lears.c					\
					${SRC_PATH}/the_parser.c					\
					${SRC_PATH}/add_lears.c						\
					${SRC_PATH}/update_lears.c					\
					${SRC_PATH}/del_lears.c						\
					${SRC_PATH}/create_scene.c					\
					${SRC_PATH}/update_player.c					\
					${SRC_PATH}/create_player.c					\
					${SRC_PATH}/create_text.c					\
					${SRC_PATH}/check_door.c					\
					${SRC_PATH}/refresh_all.c					\
					${SRC_PATH}/refresh_text.c					\
					${SRC_PATH}/animate_all.c					\
					${SRC_PATH}/destroy_all.c					\
					${SRC_PATH}/destroy_2.c						\
					${SRC_PATH}/event_handling.c				\
					${SRC_PATH}/life_handling.c				\
					${SRC_PATH}/level_handling.c				\
					${SRC_PATH}/items_handling.c				\
					${SRC_PATH}/music_handling.c				\
					${SRC_PATH}/create_static_sprite.c			\
					${SRC_PATH}/create_game_buttons.c			\
					${SRC_PATH}/put_at_end_list.c				\
					${SRC_PATH}/move_player.c					\
					${SRC_PATH}/put_at_start_list.c				\
					${SRC_PATH}/update_buttons.c				\
					${SRC_PATH}/create_enemy.c					\
					${SRC_PATH}/create_map.c					\
					${SRC_PATH}/create_map_2.c					\
					${SRC_PATH}/make_sound_effect.c				\
					${SRC_PATH}/create_minimap.c				\
					${SRC_PATH}/display.c						\
					${SRC_PATH}/update_minimap.c				\
					${SRC_PATH}/spawn_tiles.c					\
					${SRC_PATH}/callback_functions.c			\
					${SRC_PATH}/framerate_buttons.c				\
					${SRC_PATH}/option_buttons.c				\
					${SRC_PATH}/restart.c						\
					${SRC_PATH}/dialog_function.c				\
					${SRC_PATH}/display_map.c					\
					${SRC_PATH}/change_room.c					\
					${SRC_PATH}/update_animated_object.c		\
					${SRC_PATH}/update_enemy.c					\
					${SRC_PATH}/pathfinding.c					\
					${SRC_PATH}/coliding_system.c				\
					${SRC_PATH}/translation.c					\
					${SRC_PATH}/get_player.c					\
					${SRC_PATH}/create_particle.c				\
					${SRC_PATH}/attack_ennemies.c				\
					${SRC_PATH}/mov_particle.c					\
					${SRC_PATH}/init_objd.c					\

SRCT		=		${TEST_PATH}/tests.c						\

OBJ			=		${SRC:.c=.o}

OBJT		=		${SRCT:.c=.o}

RM			=		rm -rf

CFLAGS		=		-Wall -Wextra

CPPFLAGS	=		-I./includes

LDFLAGS		=		-L./lib

LDLIBS		=		-lmy -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

CC			=		gcc

all:	${NAME}

${NAME}:	${OBJ} make_lib
	${CC} -o ${NAME} ${OBJ} ${LDFLAGS} ${LDLIBS}

debug:	CFLAGS += -g

debug:	${OBJ} make_debug_lib
	${CC} -o ${NAME} ${OBJ} ${LDFLAGS} ${LDLIBS}

make_debug_lib:
	make debug -C lib

make_lib:
	make -C lib

clean:
	${RM} ${OBJ}
	${RM} ${OBJT}
	make clean -C lib

fclean:	clean
	${RM} ${NAME}
	${RM} ${NAMET} ${TEST_PATH}/*.gc* ${SRC_PATH}/*.gc*
	make fclean -C lib

re:	fclean	${NAME}

unit_test:	CFLAGS += -fprofile-arcs -ftest-coverage

unit_test:	LDLIBS += -lcriterion -lgcov

unit_test:
	${CC} -o ${NAMET} tests/test_my_rpg.c src/usage.c -lcriterion -lgcov -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

tests_run:	unit_test
	./${NAMET}

coverage:
	gcovr --exclude tests

branches:
	gcovr --branches --exclude tests

.PHONY:	all ${NAME} make_lib clean fclean re unit_test tests_run
.PHONY:	coverage branches bonus
