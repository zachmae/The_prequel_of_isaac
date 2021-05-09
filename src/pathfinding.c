/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** pathfinding
*/

#include "struct.h"
#include "enemie.h"

static void make_damage(core_t *core)
{
    static sfInt32 time = 10000;
    sfTime elapsed = sfClock_getElapsedTime(core->clock);

    time = sfTime_asMilliseconds(elapsed);
    if (core->status.inviciblity == false) {
        core->stats[LIFE]--;
        core->status.inviciblity = true;
        time = 0;
        elapsed = sfTime_Zero;
    } else if (core->status.inviciblity == true && time > 10000) {
        core->status.inviciblity = false;
    }
}

void path_finding(game_object_t *obj, bool is_flying, core_t *core)
{
    sfVector2f pos_enemy = sfSprite_getPosition(obj->sprite);
    sfVector2f pos_player = get_player_pos(core);

    obj->mov = (sfVector2f){0, 0};
    if (is_flying) {
        if (pos_player.x > pos_enemy.x)
            obj->mov.x = 10 * obj->enemy.speed;
        else
            obj->mov.x = -10 * obj->enemy.speed;
        if (pos_player.y > pos_enemy.y)
            obj->mov.y = 10 * obj->enemy.speed;
        else
            obj->mov.y = -10 * obj->enemy.speed;
        if ((pos_player.y <= pos_enemy.y + 5 &&
        pos_player.y >= pos_enemy.y - 5) &&
        (pos_player.x <= pos_enemy.x + 5 && pos_player.x >= pos_enemy.x -5)) {
            obj->mov = (sfVector2f){0, 0};
            make_damage(core);
        }
    }
}