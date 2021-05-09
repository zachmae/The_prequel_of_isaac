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

void set_framerate_30(struct core_s *core)
{
    sfRenderWindow_setFramerateLimit(core->window, 30);
}

void set_framerate_60(struct core_s *core)
{
    sfRenderWindow_setFramerateLimit(core->window, 60);
}

void set_framerate_120(struct core_s *core)
{
    sfRenderWindow_setFramerateLimit(core->window, 120);
}

void go_scene_credits(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "credits";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}