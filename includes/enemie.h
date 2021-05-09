/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** enemie
*/

#ifndef ENEMIE_H_
#define ENEMIE_H_

#include "struct.h"

void update_enemy(core_t *core, game_object_t *obj);
void path_finding(game_object_t *obj, bool is_flying, core_t *core);
sfVector2f get_player_pos(core_t *core);
void level_handle(int stats[6]);

#endif /* !ENEMIE_H_ */
