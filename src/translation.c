/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** translation
*/

#include "struct.h"

void moove_objects(map_t **map, core_t *core)
{
    game_object_t *head = NULL;

    if (sfTime_asMicroseconds(sfClock_getElapsedTime(core->clock)) - \
    core->translation.last_time < core->translation.delay)
        return;
    for (int y = 0; map[y]; ++y)
        for (int x = 0; map[y][x].type != -210; ++x) {
            head = map[y][x].obj;
            while (map[y][x].obj) {
                sfSprite_move(map[y][x].obj->sprite,
                core->translation.movement);
                map[y][x].obj = map[y][x].obj->next;
            }
            map[y][x].obj = head;
        }
    core->translation.last_time = \
    sfTime_asMicroseconds(sfClock_getElapsedTime(core->clock));
    core->translation.repitions--;
    if (core->translation.repitions == 0)
        core->translation.stop = false;
}