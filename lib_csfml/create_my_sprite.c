/*
** EPITECH PROJECT, 2021
** lib_csfml
** File description:
** create_my_sprite
*/

#include "my_csfml.h"

sfSprite *create_my_sprite(char *filepath, sfTexture *Texture, sfIntRect *rect)
{
    sfTexture_destroy(Texture);
    sfSprite *sprite = sfSprite_create();
    if (rect == NULL)
        Texture = sfTexture_createFromFile(filepath, NULL);
    else
        Texture = sfTexture_createFromFile(filepath, rect);
    sfSprite_setTexture(sprite, Texture, sfTrue);
    sfSprite_setOrigin(sprite, (sfVector2f)\
    {x:(sfTexture_getSize(Texture).x/2), y:(sfTexture_getSize(Texture).y/2)});
    return (sprite);
}