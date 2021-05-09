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

void go_scene_game(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "game";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}

void go_scene_option(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "option";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}

void close_win(struct core_s *core)
{
    sfRenderWindow_close(core->window);
    return;
}

void go_scene_menu(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "menu";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}

void go_scene_pause(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "pause";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}