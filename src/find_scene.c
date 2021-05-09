/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** find_scene
*/

#include "struct.h"
#include "buttons.h"
#include "my.h"

int find_scene(char *str, core_t *core)
{
    int c = 0;

    for (; core->scene[c].name != NULL; c = c + 1)
        if (my_strcmp(str, core->scene[c].name) == 0)
            return (c);
    return (-1);
}

void check_win(core_t *core)
{
    int y;
    int x;
    game_object_t *obj = NULL;
    int nb_enn = 0;

    for (y = 0; core->map[y]; y++)
        for (x = 0; core->map[y][x].type != -210; x++) {
            if (core->map[y][x].last == true)
                obj = core->map[y][x].obj;
        }
    while (obj != NULL) {
        nb_enn = (obj->type == ENEMIES ? nb_enn + 1: nb_enn);
        obj = obj->next;
    }
    if (nb_enn == 0) {
        music_stop(core->scene, core->id_scene, core->status.music);
        core->id_scene = "win";
        music_start(core->scene, core->id_scene,
            core->status.music, core->status.volume);
    }
}