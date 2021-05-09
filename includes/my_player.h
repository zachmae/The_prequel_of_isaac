/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "struct.h"

void add_lears(core_t *core, game_object_t *obj, int c);
void upt_head(core_t *core, game_object_t *obj);
void upt_body(core_t *core, game_object_t *obj);
void move_player(game_object_t *obj, core_t *core);
int find_scene(char *str, core_t *core);
void update_lears(core_t *core);
void check_door_two(core_t *core, int c, sfVector2f pos);
void check_death(core_t *core);
void init_objd(game_object_t *obj, char **arg, sfVector2f pos, sfVector2f sca);

#endif /* !PLAYER_H_ */