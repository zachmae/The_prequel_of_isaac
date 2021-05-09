/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** update_animated_objects
*/

#include "struct.h"

void update_animated_move(core_t *core, game_object_t *obj)
{
    sfTime mov_time = sfClock_getElapsedTime(core->clock);
    sfInt32 time = sfTime_asMilliseconds(obj->mov_time);
    sfInt32 time_2 = sfTime_asMilliseconds(mov_time);

    if (time_2 - time >= obj->mov_delay) {
        sfSprite_move(obj->sprite, obj->mov);
        obj->mov_time = mov_time;
    }
}

void update_animated_an(core_t *core, game_object_t *obj)
{
    sfTime an_time = sfClock_getElapsedTime(core->clock);
    sfInt32 time = sfTime_asMilliseconds(obj->an_time);
    sfInt32 time_2 = sfTime_asMilliseconds(an_time);

    if (time_2 - time >= obj->an_delay) {
        if (obj->rect.left < obj->repitions * obj->rect.width - \
        obj->rect.width) {
            obj->rect.left += obj->rect.width;
        } else {
            obj->rect.left = 0;
        }
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        obj->an_time = an_time;
    }
}