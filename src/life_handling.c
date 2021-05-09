/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** handle playerlife
*/

#include "my.h"
#include "csfml.h"
#include "struct.h"
#include "update.h"

void life_handle(core_t *core, float heart_width)
{
    game_object_t *obj = NULL;
    int c;

    for (c = 0; core->scene[c].name != NULL; c++) {
        if (my_strcmp(core->id_scene, core->scene[c].name) == 0)
            obj = core->scene[c].objs;
    }
    while (obj != NULL && obj->type != STATIC_SPRITE) {
        obj = obj->next;
    }
    obj->rect.width = core->stats[LIFE] * heart_width;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void player_died(core_t *core)
{
    if (core->stats[LIFE] > 0)
        return;
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "lose";
    if (core->status.sfx == true)
        sfSound_play(core->deathsfx->sound);
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}