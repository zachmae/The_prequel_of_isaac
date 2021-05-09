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
#include "buttons.h"

static void set_button_sprite(sfSprite *sprite, sfIntRect rect,
sfVector2f *pos)
{
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos[0]);
    sfSprite_setScale(sprite, pos[1]);
}

game_object_t *create_game_buttons(sfIntRect rect, char *texture,
int *stats, sfVector2f *position)
{
    game_object_t *obj = malloc(sizeof(game_object_t));

    obj->sprite = sfSprite_create();
    obj->rect = rect;
    if (my_strcmp(texture, "null") != 0) {
        obj->texture = sfTexture_createFromFile(texture, NULL);
        sfSprite_setTexture(obj->sprite, obj->texture, false);
    } else
        obj->texture = NULL;
    obj->pos = position[0];
    set_button_sprite(obj->sprite, rect, position);
    obj->game_buttons.callback = wow[stats[1]];
    obj->repitions = stats[0];
    obj->game_buttons.can_click = true;
    obj->game_buttons.clicked = false;
    obj->next = NULL;
    obj->type = GAME_BUTTONS;
    obj->update = update_buttons;
    return (obj);
}