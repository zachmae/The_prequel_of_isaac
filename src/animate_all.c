/*
** EPITECH PROJECT, 2021
** animate all
** File description:
** my rpg project
*/

#include "my.h"
#include "csfml.h"
#include "struct.h"

void refresh_cinematic(core_t *core)
{
    int c = 0;
    sfVector2u size;

    for (; core->scene[c].name != NULL; c++) {
        if ((my_strcmp(core->id_scene, "cinematic") == 0
            || my_strcmp(core->id_scene, "credits") == 0)
            && my_strcmp(core->id_scene, core->scene[c].name) == 0) {
            size = sfTexture_getSize(core->scene[c].objs->texture);
            core->scene[c].objs->an_time = sfClock_getElapsedTime(core->clock);
            if (sfTime_asMilliseconds(core->scene[c].objs->an_time) > 10
                && core->scene[c].objs->rect.top + 1080 < (int){size.y}) {
                core->scene[c].objs->rect.top += 1;
                sfSprite_setTextureRect(core->scene[c].objs->sprite,
                    core->scene[c].objs->rect);
                core->scene[c].objs->an_time = sfTime_Zero;
                sfClock_restart(core->clock);
            }
        }
    }
}

void animate_obj(game_object_t *obj, sfClock *global_clock)
{
    obj->an_time = sfClock_getElapsedTime(global_clock);
    if (sfTime_asMilliseconds(obj->an_time) > obj->an_delay) {
        obj->rect.top += obj->anim.y;
        obj->rect.left += obj->anim.x;
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        obj->an_time = sfTime_Zero;
    }
}