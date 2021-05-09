/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** check_door
*/

#include "struct.h"

void check_door_two(core_t *core, int c, sfVector2f pos)
{
    core->scene[c].player.door = STAT;
    if (pos.y <= 205 || pos.y >= 835 || pos.x <= 405 || pos.x >= 1505) {
        if (pos.y <= 205 && pos.x > 900 && pos.x < 950)
            core->scene[c].player.door = UP;
        if (pos.y >= 835 && pos.x > 900 && pos.x < 950)
            core->scene[c].player.door = DOW;
        if (pos.x <= 405 && pos.y > 500 && pos.y < 550)
            core->scene[c].player.door = LEFT;
        if (pos.x >= 1505 && pos.y > 500 && pos.y < 550)
            core->scene[c].player.door = RIGH;
    } else
        core->scene[c].player.door = STAT;
}