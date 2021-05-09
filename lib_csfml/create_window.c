/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_window
*/

#include "my_csfml.h"

sfRenderWindow *create_my_window(int x, int y, int bbp, char *name)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {x, y, bbp};

    window = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit()
    return (window);
}
