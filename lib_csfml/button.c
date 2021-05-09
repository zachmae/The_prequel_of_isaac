/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** button
*/

#include "my_csfml.h"

int button(sfSprite **sprite, sfRenderWindow *window, sfEvent *event)
{
    sfVector2i pox = (sfVector2i){x:event->mouseButton.x, \
    y:event->mouseButton.y};
    int i = 0;

    if (coli_sprite(sprite[0], sfMouse_getPositionRenderWindow(window)) \
    == sfTrue)
        i = 1;
    if (event->type == sfEvtMouseButtonPressed && \
    coli_sprite(sprite[0], pox) == sfTrue)
        i = 2;
    if (event->type == sfEvtMouseButtonReleased && \
    coli_sprite(sprite[0], pox) == sfTrue)
        return (1);
    sfRenderWindow_drawSprite(window, sprite[i], NULL);
    return (0);
}