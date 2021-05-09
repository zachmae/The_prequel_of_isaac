/*
** EPITECH PROJECT, 2021
** refresh all
** File description:
** my rpg project
*/

#include "my.h"
#include "csfml.h"
#include "struct.h"
#include "my_player.h"
#include "refresh.h"
#include "coliding_system.h"

static void update_objs_room(core_t *core)
{
    game_object_t *obj;

    for (int y = 0; core->map[y]; ++y)
        for (int x = 0; core->map[y][x].type != -210; ++x)
            if (core->map[y][x].current)
                obj = core->map[y][x].obj;
    while (obj != NULL) {
        if (obj->update)
            obj->update(core, obj);
        obj = obj->next;
    }
}

static void update_all(core_t *core)
{
    game_object_t *obj;

    if (core->translation.stop == true) {
        moove_objects(core->map, core);
        return;
    }
    for (int c = 0; core->scene[c].name != NULL; c++) {
        if (my_strcmp(core->id_scene, core->scene[c].name) == 0)
            obj = core->scene[c].objs;
    }
    while (obj != NULL) {
        if (obj->update)
            obj->update(core, obj);
        obj = obj->next;
    }
    update_objs_room(core);
    update_room(core);
}

int refresh_all(core_t *core)
{
    sfRenderWindow_clear(core->window, sfBlack);
    refresh_cinematic(core);
    refresh_text(core);
    update_all(core);
    refresh_particles(core);
    display_map(core);
    display_scene(core->id_scene, core->scene, core->window);
    update_lears(core);
    attack_ennemies(core);
    check_death(core);
    sfRenderWindow_display(core->window);
    return 0;
}