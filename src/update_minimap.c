/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** update_minimap
*/

#include "struct.h"

void update_minimap(core_t *core, game_object_t *obj)
{
    size_t count = 0;

    for (; obj->minimap.shapes[count]; ++count);
    count--;
    for (int y = 0; core->map[y]; ++y)
        for (int x = 0; core->map[y][x].type != -210; ++x)
            if (core->map[y][x].current)
                sfRectangleShape_setPosition(obj->minimap.shapes[count],
                (sfVector2f){5 + 10 + 30 * x + x * 10, 15 + 30 * y + y * 10});
}