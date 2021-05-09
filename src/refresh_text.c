/*
** EPITECH PROJECT, 2021
** refresh all
** File description:
** my rpg project
*/

#include "my.h"
#include "csfml.h"
#include "struct.h"

void refresh_text(core_t *core)
{
    game_object_t *obj;
    int value = 0;
    int nb_obj = 0;

    for (int c = 0; core->scene[c].name != NULL; c++) {
        if (my_strcmp(core->id_scene, core->scene[c].name) == 0)
            obj = core->scene[c].objs;
    }
    while (obj != NULL && value < 5) {
        nb_obj++;
        if (obj->type == TEXT) {
            obj->text->nb = (my_strcmp(core->id_scene, "status") == 0 ?
                core->stats[value] : core->items[value]);
            value++;
            obj->text->str = my_itoa(obj->text->nb);
            sfText_setString(obj->text->text, obj->text->str);
        }
        obj = obj->next;
    }
}