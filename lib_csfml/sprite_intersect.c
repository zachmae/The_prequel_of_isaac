/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** coli_sprite
*/

#include "my_csfml.h"
#include <stdbool.h>

sfBool sprite_intersect(sfSprite *sprite1, sfSprite *sprite2)
{
    const sfFloatRect size1 = sfSprite_getGlobalBounds(sprite1);
    const sfFloatRect size2 = sfSprite_getGlobalBounds(sprite2);

    return (sfFloatRect_intersects(&size1, &size2, NULL));
}