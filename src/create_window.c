/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** create_window
*/

#include "struct.h"

sfRenderWindow *create_window(sfVideoMode mode, int limit,
char const *title, sfUint32 style)
{
    sfRenderWindow *window = sfRenderWindow_create(mode, title, style, NULL);
    sfImage *image = sfImage_createFromFile("./assets/sprite/logo.png");
    const sfUint8 *ptr = sfImage_getPixelsPtr(image);

    sfRenderWindow_setIcon(window, 801, 415, ptr);
    sfRenderWindow_setFramerateLimit(window, limit);
    return (window);
}