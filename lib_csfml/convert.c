/*
** EPITECH PROJECT, 2021
** lib_csfml
** File description:
** convert
*/

#include "my_csfml.h"

sfVector2f add_vectorf(sfVector2f pos, sfVector2f pos1)
{
    pos.x = pos.x + pos1.x;
    pos.y = pos.y + pos1.y;
    return (pos);
}

sfVector2i add_vectori(sfVector2i pos, sfVector2i pos1)
{
    pos.x = pos.x + pos1.x;
    pos.y = pos.y + pos1.y;
    return (pos);
}

sfVector2i convert_click(sfEvent *event)
{
    sfVector2i pos = (sfVector2i){x:event->mouseButton.x, \
    y:event->mouseButton.y};
    return (pos);
}

sfVector2i convert_vecf(sfVector2f vec)
{
    sfVector2i pos = (sfVector2i){x: (int)vec.x, y: (int)vec.y};
    return (pos);
}

sfVector2f convert_veci(sfVector2i vec)
{
    sfVector2f pos = (sfVector2f){x: (float)vec.x, y: (float)vec.y};
    return (pos);
}
