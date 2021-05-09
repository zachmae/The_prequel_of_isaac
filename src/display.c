/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** display
*/

#include "struct.h"
#include "my.h"
#include "display.h"

static void display_minimap(game_object_t *obj, sfRenderWindow *win)
{
    for (int i = 0; obj->minimap.shapes[i]; ++i)
        sfRenderWindow_drawRectangleShape(win, obj->minimap.shapes[i], NULL);
}

static void display_obj(char *id_scene, scene_t *scene, sfRenderWindow *win)
{
    game_object_t *obj = NULL;

    for (int c = 0; scene[c].name;  c++)
        if (my_strcmp(id_scene, scene[c].name) == 0)
            obj = scene[c].objs;
    while (obj) {
        switch (obj->type) {
            case MINIMAP:
                display_minimap(obj, win);
                break;
            case TEXT:
                sfRenderWindow_drawText(win, obj->text->text, NULL);
                break;
            case PARTICLE:
                display_particles(obj, win);
                break;
            default:
                sfRenderWindow_drawSprite(win, obj->sprite, NULL);
        }
        obj = obj->next;
    }
}

void display_scene(char *id_scene, scene_t *scene, sfRenderWindow *win)
{
    size_t coun = 0;

    for (; scene[coun].name && my_strcmp(id_scene, scene[coun].name); ++coun);
    display_obj(scene[coun].child, scene, win);
    display_obj(id_scene, scene, win);
}