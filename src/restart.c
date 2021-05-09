/*
** EPITECH PROJECT, 2021
** my rpg
** File description:
** restart function file
*/

#include <stdlib.h>
#include "struct.h"
#include "csfml.h"
#include "my.h"
#include "update.h"

void restart_game(core_t *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    sfRenderWindow_close(core->window);
    my_rpg();
    return;
}