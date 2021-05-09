/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** create_moving_sprite
*/

#include <stdlib.h>
#include "struct.h"
#include "csfml.h"
#include "my.h"
#include "update.h"
#include "buttons.h"

void go_scene_tuto(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "tuto";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}

void go_scene_dialog(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "dialog";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}

void go_scene_dialog_robot(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "dialog_robot";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}

void go_scene_dialog_car(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "dialog_car";
    core->items[ATTACK]++;
    core->items[LIFE]++;
    core->items[SPEED]++;
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}

void go_scene_dialog_popeye(struct core_s *core)
{
    game_object_t *obj = NULL;
    static int index = 0;

    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "dialog_popeye";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    if (index == 0) {
        core->stats[LEVEL]++;
        core->stats[POINT]++;
    } else if (index == 1) {
        for (int c = 0; core->scene[c].name != NULL; c++) {
            if (my_strcmp("dialog_popeye", core->scene[c].name) == 0)
                obj = core->scene[c].objs;
        }
        sfTexture_destroy(obj->texture);
        obj->texture = sfTexture_createFromFile
            ("assets/sprite/popeye_no_more.png", NULL);
        sfSprite_setTexture(obj->sprite, obj->texture, false);
    }
    index++;
}