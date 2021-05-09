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

void music_switcher(struct core_s *core)
{
    if (core->status.music == true) {
        music_stop(core->scene, core->id_scene, core->status.music);
        core->status.music = false;
    } else {
        core->status.music = true;
        music_start(core->scene, core->id_scene,
            core->status.music, core->status.volume);
    }
    return;
}

void sfx_switcher(struct core_s *core)
{
    core->status.sfx = !core->status.sfx;
    return;
}

void music_lower(struct core_s *core)
{
    core->status.volume += core->status.volume > 5 ? -5: 0;
    if (core->status.music == true) {
        for (int c = 0; core->scene[c].name != NULL; c++) {
            if (my_strcmp(core->id_scene, core->scene[c].name) == 0)
                sfMusic_setVolume(core->scene[c].music, core->status.volume);
        }
    }
    return;
}

void music_upper(struct core_s *core)
{
    core->status.volume += core->status.volume <= 95 ? 5: 0;
    if (core->status.music == true) {
        for (int c = 0; core->scene[c].name != NULL; c++) {
            if (my_strcmp(core->id_scene, core->scene[c].name) == 0)
                sfMusic_setVolume(core->scene[c].music, core->status.volume);
        }
    }
    return;
}

void go_scene_cinematic(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "cinematic";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}