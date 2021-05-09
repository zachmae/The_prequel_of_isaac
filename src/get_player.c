/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** get_player
*/

#include "struct.h"
#include "my.h"

void get_player(game_object_t **temp, core_t *core, int *count)
{
    if (my_strcmp(core->id_scene, "game") != 0)
        return;
    for (; my_strcmp(core->scene[*count].name, "game") != 0; ++count[0]);
    *temp = core->scene[*count].objs;
    for (; *temp && (*temp)->type != PLAYER; *temp = (*temp)->next);
}