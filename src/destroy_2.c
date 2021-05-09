/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** destroy2
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>

void destroy_text(game_object_t *obj)
{
    sfText_destroy(obj->text->text);
    free(obj->text->str);
    free(obj->text);
}

void destroy_minimap(game_object_t *obj)
{
    for (int i = 0; obj->minimap.shapes[i]; ++i)
        sfRectangleShape_destroy(obj->minimap.shapes[i]);
    free(obj->minimap.shapes);
}

void destroy_map(map_t **map)
{
    for (int y = 0; map[y]; ++y)
        free(map[y]);
    free(map);
}