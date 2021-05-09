/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** add_lears
*/

#include "struct.h"
#include "my_player.h"
#include <stdlib.h>

lears_t *addlears(sfVector2f pos)
{
    lears_t *cell = malloc(sizeof(lears_t));

    pos.y += 10;
    cell->vec = (sfVector2f){15, 0};
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
        cell->vec = (sfVector2f){0, 15};
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
        cell->vec = (sfVector2f){0, -15};
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
        cell->vec = (sfVector2f){-15, 0};
    cell->pos = (sfVector2f)pos;
    cell->circle = sfCircleShape_create();
    sfCircleShape_setRadius(cell->circle, 15);
    sfCircleShape_setOrigin(cell->circle, (sfVector2f){7.5, 7.5});
    sfCircleShape_setFillColor(cell->circle, sfCyan);
    cell->an.microseconds = 0;
    cell->next = NULL;
    return (cell);
}

void add_lears(core_t *core, game_object_t *obj, int c)
{
    lears_t *temp;
    sfVector2f pos = sfSprite_getPosition(obj->sprite);

    if (core->scene[c].player.larmes == NULL) {
        core->scene[c].player.larmes = addlears(pos);
        return;
    } else
        temp = core->scene[c].player.larmes;
    while (temp != NULL) {
        if (temp->next == NULL) {
            temp->next = addlears(pos);
            return;
        }
        temp = temp->next;
    }
}

