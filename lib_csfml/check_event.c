/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** check_event
*/

#include "my_csfml.h"

void check_event(sfRenderWindow *win, sfEvent *event)
{
    if (event->type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyBack) == sfTrue)
        sfRenderWindow_close(win);
}
