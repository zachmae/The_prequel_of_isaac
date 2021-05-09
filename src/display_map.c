/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** display_map
*/

#include "struct.h"
#include "my.h"

void display_map(core_t *core)
{
    game_object_t *temp;

    if (my_strcmp(core->id_scene, "game")
        && my_strcmp(core->id_scene, "pause")
        && my_strcmp(core->id_scene, "status")
        && my_strcmp(core->id_scene, "loose")
        && my_strcmp(core->id_scene, "win"))
        return;
    for (int y = 0; core->map[y]; ++y) {
        for (int x = 0; core->map[y][x].type != -210; ++x) {
            temp = core->map[y][x].obj;
            while (temp) {
                sfRenderWindow_drawSprite(core->window, temp->sprite, NULL);
                temp = temp->next;
            }
        }
    }
}