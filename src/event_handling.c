/*
** EPITECH PROJECT, 2021
** event handling
** File description:
** my rpg project
*/

#include <SFML/Window.h>
#include <stdio.h>
#include <math.h>
#include "struct.h"
#include "my.h"
#include "buttons.h"

sfVector2f get_player_pos(core_t *core)
{
    game_object_t *obj = NULL;
    int c;

    for (c = 0; core->scene[c].name != NULL; c++) {
        if (my_strcmp(core->id_scene, core->scene[c].name) == 0)
            obj = core->scene[c].objs;
    }
    while (obj->next != NULL) {
        obj = obj->next;
    }
    return (sfSprite_getPosition(obj->sprite));
}

void go_scene_status(struct core_s *core)
{
    music_stop(core->scene, core->id_scene, core->status.music);
    core->id_scene = "status";
    music_start(core->scene, core->id_scene,
        core->status.music, core->status.volume);
    return;
}

static void pnj_interact(core_t *core)
{
    game_object_t *obj = NULL;
    sfVector2f pos;

    if (my_strcmp("tuto", core->id_scene) == 0) {
        pos = get_player_pos(core);
        for (int c = 0; core->scene[c].name != NULL; c++) {
            if (my_strcmp("tuto", core->scene[c].name) == 0)
                obj = core->scene[c].objs;
        }
        while (obj != NULL) {
            if (obj->type == GAME_BUTTONS &&
                fabs(pos.x - obj->pos.x) < 150 &&
                fabs(pos.y - obj->pos.y) < 150 &&
                sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
                obj->game_buttons.callback(core);
                }
            obj = obj->next;
        }
    }
}

static void scene_swapper(core_t *core, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyBack) == sfTrue \
        || event.type == sfEvtClosed)
        sfRenderWindow_close(core->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue
        && my_strcmp(core->id_scene, "game") == 0)
        go_scene_pause(core);
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue
        && my_strcmp(core->id_scene, "cinematic") == 0)
        go_scene_menu(core);
    if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue
        && my_strcmp(core->id_scene, "game") == 0)
        go_scene_status(core);
    if (sfKeyboard_isKeyPressed(sfKeyB) == sfTrue
        && (my_strcmp(core->id_scene, "status") == 0 ||
        my_strcmp(core->id_scene, "inventory") == 0))
        go_scene_game(core);
    if (sfKeyboard_isKeyPressed(sfKeyTab) == sfTrue
        && my_strcmp(core->id_scene, "game") == 0)
        go_scene_inventory(core);
    if (sfKeyboard_isKeyPressed(sfKeyV) == sfTrue)
        go_scene_credits(core);
}

int event_handling(core_t *core)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(core->window, &event)) {
        core->status.click = (event.type ==
            sfEvtMouseButtonPressed ? true: false);
        scene_swapper(core, event);
        pnj_interact(core);
        player_died(core);
        if (my_strcmp(core->id_scene, "game") == 0) {
            life_handle(core, 64);
            check_win(core);
        }
    }
    return 0;
}