/*
** EPITECH PROJECT, 2021
** lib_csfml
** File description:
** hitbox
*/

#include "my_csfml.h"

sfBool coli_sprite(sfSprite *sprite, sfVector2i mouse)
{
    sfFloatRect size = sfSprite_getGlobalBounds(sprite);

    return (sfFloatRect_contains(&size, (float)mouse.x, (float)mouse.y));
}