/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** update_lears
*/

#include "struct.h"
#include "my_player.h"
#include "../lib/includes/my.h"

void update_lears(core_t *core)
{
    lears_t *temp;

    for (int c = 0; core->scene[c].name != NULL; c = c + 1)
        if (my_strcmp("game", core->scene[c].name) == 0)
            temp = core->scene[c].player.larmes;
    while (temp != NULL) {
        temp->pos.x += temp->vec.x;
        temp->pos.y += temp->vec.y;
        sfCircleShape_setPosition(temp->circle, temp->pos);
        sfRenderWindow_drawCircleShape(core->window, temp->circle, NULL);
        temp = temp->next;
    }
}