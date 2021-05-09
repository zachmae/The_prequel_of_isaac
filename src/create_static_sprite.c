/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** create_static_sprite
*/

#include <stdlib.h>
#include "csfml.h"
#include "struct.h"

game_object_t *create_static_sprite(sfIntRect rect, char *texture,
sfVector2f position, sfVector2f scale)
{
    game_object_t *obj = malloc(sizeof(game_object_t));

    obj->texture = sfTexture_createFromFile(texture, NULL);
    obj->sprite = sfSprite_create();
    obj->rect = rect;
    obj->type = STATIC_SPRITE;
    sfSprite_setTexture(obj->sprite, obj->texture , false);
    sfSprite_setTextureRect(obj->sprite, rect);
    sfSprite_setScale(obj->sprite, scale);
    sfSprite_setPosition(obj->sprite, position);
    obj->update = NULL;
    obj->next = NULL;
    return (obj);
}