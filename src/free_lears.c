/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** free_lears
*/

#include "struct.h"
#include "my_player.h"
#include <stdlib.h>

void free_lears(core_t *core)
{
    int c = find_scene("game", core);
    lears_t *rien = NULL;

    for (; core->scene[c].player.larmes; core->scene[c].player.larmes = rien) {
        rien = core->scene[c].player.larmes->next;
        free(core->scene[c].player.larmes);
    }
    core->scene[c].player.larmes = NULL;
}